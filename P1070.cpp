/* 二哥的鹅 */
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 2147483647;

int k, V, n;
int v[305], w[305];
int f[6001][72];
int t1[72], t2[72];

int main(){
    cin >> k >> V >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i] >> w[i];
    for (int i = 0; i <= V; ++i)
        for (int j = 0; j <= k; ++j)
            f[i][j] = -INF;
    f[0][1] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = V; j >= v[i]; --j){
            for (int l = 1; l <= k; ++l){
                t1[l] = f[j - v[i]][l] + w[i];
                t2[l] = f[j][l];
            }
            int x = 1, y = 1;
            for (int z = 1; z <= k; ++z){
                if (t1[x] > t2[y])
                    f[j][z] = t1[x++];
                else
                    f[j][z] = t2[y++];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= k; ++i){
        ans += f[V][i];
    }
    cout << ans << endl;
    return 0;
}
