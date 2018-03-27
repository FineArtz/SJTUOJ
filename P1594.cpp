/* 求和 */
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXS = 5e3 + 5;
long long sum[MAXS][MAXS] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int m, n, q, t;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> t;
            sum[i][j] = t + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }
    int x1, x2, y1, y2;
    long long ans = 0;
    while (q--){
        cin >> x1 >> y1 >> x2 >> y2;
        ans = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
        cout << ans << '\n';
    }
    return 0;
}
