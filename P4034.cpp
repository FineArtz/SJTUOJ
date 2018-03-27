/* NaivePalindrome */
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int MAXS = 105;
int n = 10;
inline int change(const char &ch){
    if (isalpha(ch)) return (ch - 'A' + 10);
    else return (ch - '0');
}
class BigInt{
    //friend
    friend void add(BigInt&);
public:
    //constructor
    BigInt();
    BigInt(const string&);
    BigInt(const BigInt&);
    int len;
    int data[MAXS];
};
BigInt::BigInt() : len(0){
    memset(data, 0, sizeof(data));
}
BigInt::BigInt(const string &s){
    memset(data, 0, sizeof(data));
    len = s.size();
    for (int i = 1; i <= len; ++i)
        data[i] = change(s[len - i]);
}
BigInt::BigInt(const BigInt &rhs) : len(rhs.len) {
    memset(data, 0, sizeof(data));
    for (int i = 1; i <= len; ++i) data[i] = rhs.data[i];
}
void add(BigInt &x){
    BigInt ret;
    ret.len = x.len;
    for (int i = 1; i <= x.len; ++i)
        ret.data[i] = x.data[i] + x.data[x.len - i + 1];
    for (int i = 1; i <= x.len; ++i){
        if (ret.data[i] >= n){
            ret.data[i] -= n;
            ++ret.data[i + 1];
        }
    }
    if (ret.data[ret.len + 1] != 0)
    	++ret.len;
    x.len = ret.len;
    for (int i = 1; i <= ret.len; ++i)
        x.data[i] = ret.data[i];
}
bool check(const BigInt &x){
    for (int i = 1; i <= x.len / 2; ++i)
        if (x.data[i] != x.data[x.len - i + 1]) return false;
    return true;
}
int main(){
    cin >> n;
    string num;
    cin >> num;
    BigInt x(num);
    int step = 0;
    while (!check(x)){
        add(x);
        ++step;
        if (step >= 30){
            cout << "Impossible!" << endl;
            return 0;
        }
    }
    cout << "STEP=" << step << endl;
    return 0;
}
