/* 二哥的硬币 */
#include <iostream>
#include <cstring>
using namespace std;

int a[100005], c[1005], f[100005];

void work(int n, int m){
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    memset(f, -1, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    for (int i = 1; i <= n; ++i){
        for (int j = 0; j <= m; ++j){
            if (f[j] >= 0)
                f[j] = c[i];
            else if (j < a[i] || f[j - a[i]] < 0)
                f[j] = -1;
            else
                f[j] = f[j - a[i]] - 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i)
        if (f[i] >= 0)
            ++ans;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (n != 0 || m != 0){
        work(n, m);
        cin >> n >> m;
    }
    return 0;
}
