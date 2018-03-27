/* 二哥领工资 */
#include <iostream>
#include <string>
using namespace std;

const int MAXS = 205;
class BigNum{
    //friend
    friend BigNum operator +(const BigNum&, const BigNum&);
    friend ostream& operator <<(ostream&, const BigNum&);
public:
    //constructor
    //BigNum();
    BigNum(const string&);
    BigNum(const BigNum&);

    //operator
    //short& operator [](const int& x) { return data[x]; }
   // BigNum& operator =(const BigNum&);

    int GetLen() const { return length; }
private:
    short data[MAXS];
    int length;
};

BigNum::BigNum(const string& s){
    for (int i = 0; i != MAXS - 1; ++i)
        data[i] = 0;
    length = s.size() - 1;
    int i = s.size() - 1;
    data[1] = s[i--] - '0';
    data[2] = s[i] - '0';
    for (int j = 3; j <= length; ++j)
        data[j] = s[s.size() - j - 1] - '0';

}
BigNum::BigNum(const BigNum& b){
    length = b.length;
    for (int i = 0; i != MAXS; ++i)
        data[i] = b.data[i];
}

ostream& operator <<(ostream& os, const BigNum& b){
    for (int i = b.length; i != 2; --i)
        os << b.data[i];
    os << '.' << b.data[2] << b.data[1];
    return os;
}

BigNum operator +(const BigNum& lhs, const BigNum& rhs){
    BigNum ans("0.00");
    int len = max(lhs.length, rhs.length);
    for (int i = 1; i <= len; ++i){
        ans.data[i] += lhs.data[i] + rhs.data[i];
        if (ans.data[i] >= 10){
            ans.data[i] -= 10;
            ++ans.data[i + 1];
        }
    }
    if (ans.data[len + 1] != 0) ++len;
    ans.length = len;
    return ans;
}

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    BigNum a(s1), b(s2);
    cout << a + b << endl;
    return 0;
}
