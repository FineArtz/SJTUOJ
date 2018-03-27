/* 二哥种花生 */
#include <iostream>
using namespace std;

int sum[1005][1005] = {0};

int main(){

    int m, n, t;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> t;
            sum[i][j] = t + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    int a, b, ans = 0;
    cin >> a >> b;
    for (int i = a; i <= m; ++i)
        for (int j = b; j <= n; ++j)
            ans = max(ans, sum[i][j] - sum[i - a][j] - sum[i][j - b] + sum[i - a][j - b]);
    cout << ans << endl;
    return 0;
}
