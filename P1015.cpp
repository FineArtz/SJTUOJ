#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

//const int MAXSIZE = 10000;
const double pi = 3.1415926;

class comp{//complex number
    //friend
    friend comp operator +(const comp&, const comp&);
    friend comp operator -(const comp&, const comp&);
    friend comp operator *(const comp&, const comp&);
    friend comp operator /(const comp&, const comp&);
public:
    //constructor
    comp() : x(0.0), y(0.0) {}
    comp(double xx, double yy) : x(xx), y(yy) {};
    comp(const comp &cmp) : x(cmp.x), y(cmp.y) {};

    comp operator ~() const;//conjugation
    comp operator -() const;//minus
    comp& operator =(const comp&);
    double mod() const {return sqrt(x * x + y * y);}
    double smod() const {return x * x + y * y;}
    comp recp() const;
    double x, y;
};
comp comp::operator ~() const {return comp(x, -y);}
comp comp::operator -() const {return comp(-x, -y);}
comp& comp::operator =(const comp &rhs){
    x = rhs.x;
    y = rhs.y;
    return *this;
}
inline comp operator +(const comp &lhs, const comp &rhs){return comp(lhs.x + rhs.x, lhs.y + rhs.y);}
inline comp operator -(const comp &lhs, const comp &rhs){return comp(lhs.x - rhs.x, lhs.y - rhs.y);}
inline comp operator *(const comp &lhs, const comp &rhs){
    return comp(lhs.x * rhs.x - lhs.y * rhs.y, lhs.x * rhs.y + lhs.y * rhs.x);
}
inline comp operator /(const comp &lhs, const comp &rhs){
    double module = rhs.smod();
    return comp((lhs.x * rhs.x - lhs.y * rhs.y) / module, (lhs.x * rhs.y + lhs.y * rhs.x) / module);
}
inline comp comp::recp() const {
    double module = this->smod();
    return comp(x / module, -y / module);
}

class BigInt{
    //friend
    friend ostream& operator <<(ostream&, const BigInt&);
    friend BigInt operator *(const BigInt&, const BigInt&);
public:
    //constructor
    BigInt();
    BigInt(const string&);
    vector<int> data;
    int len;
};
BigInt::BigInt() : len(1), data(0) {}
BigInt::BigInt(const string &s) : len(s.size()){
    for (int i = 1; i <= len; ++i)
        data.push_back(s[len - i] - '0');
}

ostream& operator <<(ostream& os, const BigInt &b){
    for (int i = b.len - 1; i >= 0; --i)
        os << b.data[i];
    return os;
}

vector<comp> FFT(const vector<comp> &f, bool inv = false){
    int len = f.size();
    if (len == 1){
        vector<comp> ret;
        ret.push_back(f[0]);
        return ret;
    }
    vector<comp> f1 , f2;
    for (int i = 0; i < len; i += 2){
        f1.push_back(f[i]);
        f2.push_back(f[i + 1]);
    }
    vector<comp> ret1, ret2, ret;
    ret1 = FFT(f1, inv);
    ret2 = FFT(f2, inv);
    for (int i = 0; i < len; ++i){
        comp w(cos(2.0 * pi * i / len), sin(2.0 * pi * i / len));
        if (inv) w = w.recp();
        comp reti(ret1[i % (len / 2)] + w * ret2[i % (len / 2)]);
        ret.push_back(reti);
    }
    return ret;
}

BigInt operator *(const BigInt &lhs, const BigInt &rhs){
    vector<comp> fx1, fx2;
    int len = max(lhs.len, rhs.len), k = 1;
    while (len > k) k *= 2;
    len = k * 2;
    for (int i = 0; i < len; ++i){
        if (i < lhs.len) fx1.push_back(comp(double(lhs.data[i]), 0.0));
        else fx1.push_back(comp(0.0, 0.0));
    }
    for (int i = 0; i < len; ++i){
        if (i < rhs.len) fx2.push_back(comp(double(rhs.data[i]), 0.0));
        else fx2.push_back(comp(0.0, 0.0));
    }
    vector<comp> y1 = FFT(fx1), y2 = FFT(fx2), y;
    for (int i = 0; i < len; ++i)
        y.push_back(y1[i] * y2[i]);
    vector<comp> fx = FFT(y, 1);
    for (int i = 0; i < len; ++i)
		fx[i].x /= len;
    BigInt ret("");
    for (int i = 0; i < len; ++i)
        ret.data.push_back(round(fx[i].x));
	for (int i = 0; i < len - 1; ++i){
		if (ret.data[i] >= 10){
			ret.data[i + 1] += ret.data[i] / 10;
			ret.data[i] %= 10;
		}
	}
	while (ret.data[len - 1] == 0){
		--len;
		ret.data.erase(ret.data.end() - 1);
	}
    ret.len = len;
    return ret;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    BigInt lhs(s1), rhs(s2);
    cout << lhs * rhs << endl;
    return 0;
}

