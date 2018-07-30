/* 撤退 */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 20000;

int n, A, B, C;
int head[MAXN + 5] = {0}, ed[MAXN + 5] = {0}, nxt[MAXN + 5] = {0}, len[MAXN + 5] = {0};
int cnt = 0;
int h[MAXN + 5] = {0}, e[MAXN + 5] = {0}, nn[MAXN + 5] = {0}, l[MAXN + 5] = {0};
int m = 0;
int dist[MAXN + 5] = {0}, depth[MAXN + 5] = {0}, fa[MAXN + 5][20] = {0};

inline void addEdge(int u, int v, int w){
    ++cnt;
    nxt[cnt] = head[u];
    ed[cnt] = v;
    head[u] = cnt;
    len[cnt] = w;
}

inline void addedge(int u, int v, int w){
    ++m;
    nn[m] = h[u];
    e[m] = v;
    h[u] = m;
    l[m] = w;
}

void calcDist(int x){
    int q[MAXN + 5];
    bool b[MAXN + 5]= {0};
    int front = 0, rear = 0;
    q[rear++] = x;
    dist[x] = 0;
    depth[x] = 1;
    b[x] = true;
    while (front != rear){
        int now = q[front];
        ++front;
        for (int i = head[now]; i != 0; i = nxt[i]){
            int next = ed[i];
            if (!b[next]){
                b[next] = true;
                addedge(now, next, len[i]);
                fa[next][0] = now;
                depth[next] = depth[now] + 1;
                dist[next] = dist[now] + len[i];
                q[rear++] = next;
            }
        }
    }
}

inline int lca(int p, int q){
    if (depth[p] > depth[q]){
        int t = p;
        p = q;
        q = t;
    }
    int def = depth[q]  - depth[p];
    for (int i = 0; (1 << i) <= def; ++i){
        if ((1 << i) & def)
            q = fa[q][i];
    }
    if (p != q){
        for (int i = (int)log2(n); i >= 0; --i){
            if (fa[p][i] != fa[q][i]){
                p = fa[p][i];
                q = fa[q][i];
            }
        }
        p = fa[p][0];
    }
    return p;
}

inline int dis(int p, int q){
    int x = lca(p, q);
    return dist[p] + dist[q] - 2 * dist[x];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> A >> B >> C;
    for (int i = 1; i < n; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    calcDist(1);
    for (int j = 1; (1 << j) <= n; ++j){
        for (int i = 1; i <= n; ++i)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    }
    int ans = 2147483647, ansi = 0;
    for (int i = 1; i <= n; ++i){
        int d = dis(i, A) + dis(i, B) + dis(i, C);
        if (ans > d){
            ans = d;
            ansi = i;
        }
    }
    cout << ansi << '\n' << ans << '\n';
    return 0;
}
