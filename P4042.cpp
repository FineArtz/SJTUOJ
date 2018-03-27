/* 面包要约会 */
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

constexpr int MAXN = 3e5 + 5, MOD = 1e9 + 7;
int n;
long long x[MAXN];

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    sort(x + 1, x + n + 1);
    long long ans = 0, doub = 1, sum = 0;
    for (int i = 2; i <= n; ++i){
        sum = sum * 2 % MOD;
        sum = (sum + x[i - 1]) % MOD;
        doub = doub * 2 % MOD;
        ans = (ans + (doub - 1) * x[i] - sum) % MOD;
    }
    cout << ans << endl;
    return 0;
}
