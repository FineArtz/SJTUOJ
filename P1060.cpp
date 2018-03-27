/* 小X的机器人 */
#include <iostream>
using namespace std;

const int INF = 0x7fffff;

int c[201][201];
int f1[201][201], f2[201][201];
int a[1005];

int minn(initializer_list<int> il){
    int ret = INF;
    for (int i : il)
        if (ret > i)
            ret = i;
    return ret;
}

int main(){
    int n, l;
    cin >> l >> n;
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= l; ++j)
            cin >> c[i][j];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int j = 1; j <= l; ++j)
        for (int k = 1; k <= l; ++k)
            f1[j][k] = f2[j][k] = INF;
    f1[2][3] = f1[3][2] = 0;
    a[0] = 1;
    for (int i = 0; i < n; ++i){
        for (int j = 1; j <= l; ++j){
            for (int k = 1; k <= l; ++k){
                if (a[i] == j || a[i] == k || j == k)
                    continue;
                f2[j][k] = minn({f1[j][k] + c[a[i]][a[i + 1]], f2[j][k], INF});
                f2[a[i]][k] = minn({f1[j][k] + c[j][a[i + 1]], f2[a[i]][k], INF});
                f2[a[i]][j] = minn({f1[j][k] + c[k][a[i + 1]], f2[a[i]][j], INF});
            }
        }
        for (int j = 1; j <= l; ++j)
            for (int k = 1; k <= l; ++k){
                f1[j][k] = f2[j][k];
                f2[j][k] = INF;
            }
    }
    int ans = INF;
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= l; ++j)
            if (ans > f1[i][j])
                ans = f1[i][j];
    cout << ans << endl;
    return 0;
}
