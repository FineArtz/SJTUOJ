/* 小M的实验室 */
#include <iostream>
using namespace std;

const int INF = 2000000000;

int main(){
    int n;
    int a[3][2005] = {0}, sum[3][2005] = {0};
    int maxx = -INF, ans = -INF;
    cin >> n;
    for (int i = 1; i <= 2; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            sum[i][j]  = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    for (int i = 3; i <= n; ++i){
        int t = INF, tsum = 0;
        for (int j = i - 2; j >= 1; --j){
            tsum += a[1][j + 1];
            t = min(t, tsum);
            tsum = min(tsum, 0);
            ans = max(ans, sum[2][i] - sum[2][j - 1] - t);
        }
    }
    cout << ans << endl;
    return 0;
}
