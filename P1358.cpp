/* 分割树 */
#include <iostream>
#include <cassert>
using namespace std;

const int MAXN = 200000;

int head[MAXN + 5] = {0}, ed[MAXN * 2 + 5] = {0}, nxt[MAXN * 2+ 5] = {0}, cnt = 0;
int sum[MAXN + 5] = {0}, fa[MAXN + 5] = {0};
int h[MAXN + 5] = {0}, e[MAXN + 5] = {0}, nx[MAXN + 5] = {0}, m = 0;
int n;
bool b[MAXN + 5] = {0};

void addEdge(int u, int v){
    ++cnt;
    nxt[cnt] = head[u];
    ed[cnt] = v;
    head[u] = cnt;
}

void addedge(int u, int v){
    ++m;
    nx[m] = h[u];
    e[m] = v;
    h[u] = m;
}

int buildTree(int x){
    sum[x] = 1;
    for (int i = head[x]; i != 0; i = nxt[i]){
        if (!b[ed[i]]){
            int k = ed[i];
            b[k] = true;
            addedge(x, k);
            fa[k] = x;
            sum[x] += buildTree(k);
        }
    }
    return sum[x];
}

bool check(int x){
    int k = sum[1] - sum[x];
    if (k > n / 2)
        return false;
    for (int i = h[x]; i != 0; i = nx[i]){
        if (sum[e[i]] > n / 2)
            return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++i){
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        addEdge(v, u);
    }
    b[1] = true;
    buildTree(1);
    for (int i = 1; i <= n; ++i){
        if (check(i)){
            cout << i << '\n';
        }
    }
    return 0;
}
