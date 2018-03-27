/* 二哥的爬树 */
#include <iostream>
using namespace std;

int main(){
    int n;
    int a[105][105];
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                a[i][j] = 1000000000;
    for (int i = 1; i <= n - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (i != j)
                    if (a[i][k] + a[k][j] < a[i][j])
                        a[i][j] = a[i][k] + a[k][j];
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        cout << a[u][v] << endl;
    }
    return 0;
}
