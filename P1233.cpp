/* Path */
#include <iostream>
using namespace std;

int n, m, start, len;
int head[15] = {0}, nxt[105] = {0}, e[105] = {0};
int cnt = 0, ans = 0;
bool vis[15] = {0};

void addEdge(int u, int v){
    nxt[++cnt] = head[u];
    e[cnt] = v;
    head[u] = cnt;
}

void dfs(int x, int step){
    if (step == len){
        ++ans;
        return;
    }
    for (int i = head[x]; i; i = nxt[i]){
        if (!vis[e[i]]){
            vis[e[i]] = true;
            dfs(e[i], step + 1);
            vis[e[i]] = false;
        }
    }
}

int main(){
    cin >> n >> m >> start >> len;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    vis[start] = true;
    dfs(start, 0);
    cout << ans << endl;
    return 0;
}
