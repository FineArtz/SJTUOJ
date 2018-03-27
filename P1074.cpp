/* LSZ的雪地脚印 */
#include <iostream>
#include <cstring>
using namespace std;

int a[1235][1235], s[1235][1235], f[1235][1235];

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            char ch;
            cin >> ch;
            a[i][j] = (ch == 'X' ? 1 : 0);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i){
        for (int j = 2; j <= m; ++j){
            if (a[i][j])
                continue;
            for (int t = f[i - 1][j] + 1; t >= 1; --t){
                int x = i - t + 1, y = j - 2 * t + 1;
                if (x <= 0 || y <= 0)
                    continue;
                int p = s[i][j] - s[x - 1][j] - s[i][y - 1] + s[x - 1][y - 1];
                if (p == 0){
                    f[i][j] = t;
                    break;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 2; j <= m; ++j)
            if (f[i][j] > ans)
                ans = f[i][j];
    cout << ans * ans * 2 << endl;
    return 0;
}
