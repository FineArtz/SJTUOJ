/* 我把助教团的平均智商拉低了 */
#include <iostream>
using namespace std;

const int INF = 2000000;
const int MAXH = 33000;

int n;
int hp, iq;
int a[405], b[405];
int f[405][MAXH + 5] = {0};

int main(){
    cin >> n;
    cin >> hp >> iq;
    for (int i = 1; i <= n; ++i)
        cin >> a[i] >> b[i];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= MAXH; ++j)
            f[i][j] = -INF;
    f[0][hp] = iq;
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= MAXH - 1000; ++j){
            if (j >= a[i] && f[i - 1][j - a[i]] != -INF && f[i - 1][j - a[i]] + b[i] > f[i - 1][j]){
                f[i][j] = f[i - 1][j - a[i]] + b[i];
            }
            else
                f[i][j] = f[i - 1][j];
        }
    }
    int ans = -INF;
    for (int i = 1; i <= MAXH; ++i){
        if (f[n][i] > 70 && f[n][i] * i > ans)
            ans = f[n][i] * i;
    }
    if (ans == -INF)
        cout << "Death" << endl;
    else
        cout << ans << endl;
    return 0;
}
