/* 高精度除法 */
#include <iostream>
#include <string>
using namespace std;

constexpr int MAXL = 1000;

class BigInt{
    //friend
    friend BigInt operator /(const BigInt&, const BigInt&);
    friend BigInt operator -(const BigInt&, const BigInt&);
    //friend bool operator >(const BigInt&, const BigInt&);
    //friend bool operator ==(const BigInt&, const BigInt&);
    //friend bool operator >=(const BigInt&, const BigInt&);
    //friend ostream& operator <<(ostream&, const BigInt&);
    //friend istream& operator >>(istream&, BigInt&);
public:
    //constructor
    BigInt() = default;
    BigInt(const string&);
    BigInt(const BigInt&);

    int operator [](const int &x) const {return data[x];}
    int GetLen() const {return len;}
    BigInt lshift10(const int&) const;
private:
    int len = 1;
    int data[MAXL] = {0};
};
BigInt::BigInt(const string &s){
    len = s.size();
    for (int i = 1; i <= len; ++i)
        data[i] = s[len - i] - '0';
}
BigInt::BigInt(const BigInt &b){
    len = b.len;
    for (int i = 1; i <= len; ++i)
        data[i] = b.data[i];
}
bool operator ==(const BigInt &lhs, const BigInt &rhs){
    if (lhs.GetLen() != rhs.GetLen()) return false;
    for (int i = 1; i <= lhs.GetLen(); ++i)
        if (lhs[i] != rhs[i]) return false;
    return true;
}
bool operator >(const BigInt &lhs, const BigInt &rhs){
    if (lhs.GetLen() < rhs.GetLen()) return false;
    if (lhs.GetLen() > rhs.GetLen()) return true;
    for (int i = lhs.GetLen(); i >= 1; --i){
        if (lhs[i] > rhs[i]) return true;
        if (lhs[i] < rhs[i]) return false;
    }
    return false;
}
bool operator >=(const BigInt &lhs, const BigInt &rhs){
    if (lhs == rhs || lhs > rhs) return true;
    return false;
}
ostream& operator <<(ostream &os, const BigInt &bi){
    for (int i = bi.GetLen(); i >= 1; --i)
        os << bi[i];
    return os;
}
BigInt operator -(const BigInt &lhs, const BigInt &rhs){
    BigInt ret(lhs);
    for (int i = 1; i <= rhs.len; ++i)
        ret.data[i] -= rhs[i];
    for (int i = 1; i <= ret.len; ++i){
        if (ret.data[i] < 0){
            ret.data[i] += 10;
            --ret.data[i + 1];
        }
    }
    int i = ret.len;
    while (i >= 1 && ret.data[i] == 0) --i;
    ret.len = (i != 0) ? i : 1;
    return ret;
}
BigInt BigInt::lshift10(const int &x) const{
    if (x <= 0) return *this;
    BigInt tmp(*this);
    for (int i = len + x; i >= x + 1; --i)
        tmp.data[i] = tmp[i - x];
    for (int i = 1; i <= x; ++i)
        tmp.data[i] = 0;
    tmp.len += x;
    return tmp;
}
BigInt operator /(const BigInt &lhs, const BigInt &rhs){
    BigInt ret, tmp(lhs);
    while(tmp > rhs){
        int i = 0;
        while (tmp > rhs.lshift10(i + 1)) ++i;
        if (i >= ret.len) ret.len = i + 1;
		while (tmp > rhs.lshift10(i)){
			tmp = tmp - rhs.lshift10(i);
			++ret.data[i + 1];
		}
    }
    if (tmp >= rhs) ++ret.data[1];
	for (int i = 1; i <= ret.len - 1; ++i)
		if (ret[i] >= 10){
			ret.data[i] -= 10;
			++ret.data[i + 1];
		}
	if (ret[ret.len] >= 10){
		ret.data[ret.len] -= 10;
		++ret.data[++ret.len];
	}
    return ret;
}
int main(){
    string s1, s2;
    cin >> s1 >> s2;
    BigInt bi1(s1), bi2(s2);
    cout << bi1 / bi2 << endl;
    return 0;
}
