/* 小M爱炒股 */
#include <iostream>
#include <cassert>
using namespace std;

class Bignum{
public:
    int len = 1;
    long long data[1005] = {0};

    long long &operator [](int x){
        return data[x];
    }

    void clear(){
        for (int i = 1; i <= len; ++i)
            data[i] = 0;
        len = 1;
    }

    Bignum &operator =(const Bignum &b){
        clear();
        len = b.len;
        for (int i = 1; i <= len; ++i)
            data[i] = b.data[i];
        return *this;
    }
};

Bignum operator +(const Bignum &b1, const Bignum &b2){
    Bignum c;
    c.len = max(b1.len, b2.len);
    for (int i = 1; i <= c.len; ++i){
        c.data[i] = c.data[i] + b1.data[i] + b2.data[i];
        c.data[i + 1] += c.data[i] / 10;
        c.data[i] %= 10;
    }
    ++c.len;
    while (c.data[c.len] != 0){
        c.data[c.len + 1] += c.data[c.len] / 10;
        c.data[c.len] %= 10;
        ++c.len;
    }
    if (c.data[c.len] == 0 && c.len != 1)
        --c.len;
    return c;
}

long long a[5005], len;
int n;
long long t[5005];
Bignum c, cnt[5005];

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        t[i] = 1;
        cnt[i][1] = 1;
    }
    len = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j < i; ++j){
            if (a[j] > a[i]){
                if (t[i] < t[j] + 1){
                    t[i] = t[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if (t[i] == t[j] + 1)
                    cnt[i] = cnt[i] + cnt[j];
            }
        }
        for (int j = 1; j < i; ++j){
            if (a[i] == a[j] && t[i] == t[j])
                cnt[j].clear();
        }
        if (t[i] > len)
            len = t[i];
    }
    for (int i = 1; i <= n; ++i){
        if (t[i] == len)
            c = c + cnt[i];
    }
    cout << len << ' ';
    for (int i = c.len; i >= 1; --i)
        cout << c[i];
    cout << endl;
    return 0;
}
