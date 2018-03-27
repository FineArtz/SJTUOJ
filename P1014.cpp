/* 高精度加法 */
#include <iostream>
#include <string>
using namespace std;

class BigInt{
    friend BigInt operator +(const BigInt&, const BigInt&);
    friend ostream& operator <<(ostream &, const BigInt&);
public:
//constructor
    BigInt(string);

    int getl() const { return len; }
private:
    short data[100005];
    int len;
};

BigInt::BigInt(string s){
    len = s.size();
    for (int i = 1; i <= len; ++i)
        data[i] = s[len - i] - '0';
}

BigInt operator +(const BigInt &a, const BigInt &b){
    BigInt ans("");
    int l = (a.getl() > b.getl() ? a.getl() : b.getl());
    ans.len = l;
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
    while (ans.data[ans.len] == 0) --ans.len;
    return ans;
}
ostream& operator <<(ostream &os, const BigInt &a){
    for (int i = a.len; i >= 1; --i)
        os << a.data[i];
    return os;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    BigInt a(s1), b(s2);
    cout << a + b << endl;
    return 0;
}
