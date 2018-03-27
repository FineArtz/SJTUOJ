/* 括号匹配 11.07 */
#include <iostream>
using namespace std;

const int MOD = 19301;

int main(){
    long long f[3335] = {0};
    int n;
    cin >> n;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; ++i){
        f[i] += f[i - 1];
        for (int j = 1; j <= i - 1; ++j){
            f[i] += f[j - 1] *  f[i - j - 1];
            f[i] %= MOD;
        }
        f[i] %= MOD;
    }
    cout << f[n] << endl;
    return 0;
}
