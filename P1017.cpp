/* 二哥养兔子 */
#include <iostream>
#include <string>
using namespace std;

class BigInt{
    friend BigInt operator +(const BigInt&, const BigInt&);
    friend BigInt operator *(const BigInt&, const int&);
    friend ostream& operator <<(ostream &, const BigInt&);
public:
//constructor
    BigInt() = default;
    BigInt(string);
    BigInt(const BigInt&);

    int getl() const { return len; }
private:
    int data[20000] = {0};
    int len = 1;
};

BigInt::BigInt(string s){
    len = s.size();
    for (int i = 1; i <= len; ++i)
        data[i] = s[len - i] - '0';
}
BigInt::BigInt(const BigInt &b){
	len = b.len;
	for (int i = 1; i <= len; ++i)
		data[i] = b.data[i];
}

BigInt operator +(const BigInt &a, const BigInt &b){
    BigInt ans;
    int l = (a.getl() > b.getl() ? a.getl() : b.getl());
    for (int i = 1; i <= l; ++i)
        ans.data[i] = a.data[i] + b.data[i];
    int i = 1;
    while (i <= l + 1){
        if (ans.data[i] >= 10){
            ans.data[i++] -= 10;
            ++ans.data[i];
        }
        else ++i;
    }
    ans.len = i;
    while (ans.len > 1 && ans.data[ans.len] == 0) --ans.len;
    return ans;
}
BigInt operator *(const BigInt &a, const int &b){
    BigInt ans;
    for (int i = 1; i <= a.len; ++i)
        ans.data[i] = b * a.data[i];
    ans.len = a.len;
    for (int i = 1; i <= ans.len; ++i){
        if (ans.data[i] / 10 != 0){
            ans.data[i + 1] += ans.data[i] / 10;
            ans.data[i] %= 10;
        }
    }
    while (ans.data[ans.len + 1] > 0){
        ++ans.len;
        if (ans.data[ans.len] >= 10){
            ans.data[ans.len + 1] += ans.data[ans.len] / 10;
            ans.data[ans.len] %= 10;
        }
    }
    return ans;
}
ostream& operator <<(ostream &os, const BigInt &a){
    for (int i = a.len; i >= 1; --i)
        os << a.data[i];
    return os;
}

BigInt one("1"), two, aft, ans("1");
int main(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    while (n--){
        BigInt tmp(one * a + two * b + aft * c);
        ans = ans + tmp;
        aft = aft + two;
        two = one;
        one = tmp;
    }
    cout << ans << endl;
   // cout << ans.getl() << endl;
}
