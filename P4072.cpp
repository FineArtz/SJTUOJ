/* 日天卖面包 */
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
using namespace std;

class Point{
public:
    map<int, int> edge;
};

Point a[100005];
set<int> s;
bool is[100005];
int n, m, k;

int main(){
    cin >> n >> m >> k;
    if (k == 0){
        cout << "-1" << endl;
        return 0;
    }
    if (n >= 50){
    memset(is, 0, sizeof(is));
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        if (a[u].edge.find(u) == a[u].edge.end()){
            a[u].edge[v] = w;
            a[v].edge[u] = w;
        }
        else{
            if (a[u].edge[v] > w){
                a[u].edge[v] = w;
                a[v].edge[u] = w;
            }
        }
    }
    int ans = 2147483647;
    int t;
    for (int i = 1; i <= k; ++i){
        cin >> t;
        s.insert(t);
        is[t] = true;
    }
    for (auto i : s){
        for (auto j : a[i].edge){
            if (!is[j.first]){
                ans = min(ans, j.second);
            }
        }
    }
    if (ans == 2147483647)
        cout << "-1" << endl;
    else
        cout << ans << endl;
    }
    else{
        int a[25][25];
        for (int i = 0; i < 25; ++i)
            for (int j = 0; j < 25; ++j)
                a[i][j] = -1;
        for (int i = 1; i <= m; ++i){
            int u, v, w;
            cin >> u >> v >> w;
            if (a[u][v] == -1){
                a[u][v] = w;
                a[v][u] = w;
            }
            else{
                if (a[u][v] > w){
                    a[u][v] = w;
                    a[v][u] = w;
                }
            }
        }
        int s[25];
        bool is[25];
        memset(is, 0, sizeof(is));
        for (int i = 1; i <= k; ++i){
            cin >> s[i];
            is[s[i]] = true;
        }
        int ans = 2147483647;
        for (int i = 1; i <= k; ++i){
            for (int j = 1; j <= n; ++j){
                if (is[j]) continue;
                if (a[s[i]][j] == -1) continue;
                ans = min(ans, a[s[i]][j]);
            }
        }
        if (ans == 2147483647)
            cout << "-1" << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
