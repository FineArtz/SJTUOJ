/* 邮递员小F */
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 2000000000;

int n;
int a[16][16];
int f[16][32768];

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= (1 << n) - 1; i += 2){
        for (int j = 2; j <= n; ++j){
            if (i & (1 << (j - 1))){
                if (i ^ ((1 << (j - 1)) + 1)){
                    f[j][i] = INF;
                    for (int k = 2; k <= n; ++k){
                        if (k != j && i & (1 << (k - 1))){
                            f[j][i] = min(f[j][i], f[k][i ^ (1 << (j - 1))] + a[k][j]);
                        }
                    }
                }
                else
                    f[j][i] = a[1][j];
            }
        }
    }
    int ans = INF;
    for (int i = 2; i <= n; ++i){
        ans = min(ans, f[i][(1 << n) - 1] + a[i][1]);
    }
    cout << ans << endl;
    return 0;
}
