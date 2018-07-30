/* travel */
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

long long FACT[21] = {0};

long long comb(long long n, long long k){
    return FACT[n] / FACT[k] / FACT[n - k];
}

int m;
char s1[25], s2[25];

long long travel(char *s1, long long len1, char *s2, long long len2){
    long long ret = 1, p1 = 1, p2 = 0;
    long long child = 0;
    while (p1 < len1){
        for (int i = 0; i < len2; ++i){
            if (s2[i] == s1[p1]){
                p2 = i;
                break;
            }
        }
        ret *= travel(s1 + p1, p2 - p1 + 2, s2 + p1 - 1, p2 - p1 + 2);
        p1 = p2 + 2;
        ++child;
    }
    ret *= comb(m, child);
    return ret;
}

int main(){
    FACT[0] = 1;
    for (int i = 1; i <= 20; ++i)
        FACT[i] = FACT[i - 1] * i;

    cin >> m >> s1 >> s2;
    long long len1 = strlen(s1), len2 = strlen(s2);
    cout << travel(s1, len1, s2, len2);
    return 0;
}
