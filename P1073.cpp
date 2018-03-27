/* 能量项链 */
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 2147483647;

int main(){
    int n;
    cin >> n;
    int a[205], m[205][205];
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[n + i] = a[i];
    }
    int ans = 0;
    for (int t = 0; t <= n - 1; ++t){
        memset(m, 0, sizeof(0));
        for (int l = 2; l <= n; ++l){
            for (int i = t + 1; i <= t + n - l + 1; ++i){
                int j = i + l - 1;
                m[i][j] = 0;
                for (int k = i; k <= j - 1; ++k){
                    int tmp = m[i][k] + m[k + 1][j] + a[i] * a[k + 1] * a[j + 1];
                    if (tmp > m[i][j])
                        m[i][j] = tmp;
                }
            }
        }
        if (m[t + 1][t + n] > ans)
            ans = m[t + 1][t + n];
    }
    cout << ans << endl;
    return 0;
}
