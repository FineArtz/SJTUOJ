/* palin */
#include <iostream>
using namespace std;

const long long MOD = 1000000007;

long long f[1005] = {0};

int main(){
    int n;
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= n; ++i){
        if (i % 2 == 0){
            f[i] = (1 + f[i / 2]) % MOD;
            for (int j = 2; j < i; j += 2){
                f[i] = (f[i] + f[(i - j) / 2]) % MOD;
            }
        }
        else{
            f[i] = 1;
            for (int j = 1; j <= i; j += 2){
                f[i] = (f[i] + f[(i - j) / 2]) % MOD;
            }
        }
    }
    cout << f[n] << endl;
    return 0;
}
