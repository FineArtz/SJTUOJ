/* 小F的公寓 */
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 500005, INF = 2147483647;

class Edge{
public:
    Edge() = default;
    Edge(int uu, int vv, int ww, int nn) : u(uu), v(vv), w(ww), next(nn) {}
    int u = 0, v = 0, w = 0, next = 0;
};

Edge e[MAXN];
int head[MAXN], cnt = 0;
int n, s;
int dist[MAXN], father[MAXN];
int p1, p2;

int q[MAXN] = {0};
bool v[MAXN] = {0};

void addEdge(int u, int v, int w){
    e[++cnt] = Edge(u, v, w, head[u]);
    head[u] = cnt;
}

int dis(int x, int indicator){
    memset(q, 0, sizeof(q));
    memset(v, 0, sizeof(v));
    int front = 0, rear = 0, ret = 0;
    if (indicator){
        for (int i = p2; i != 0; i = father[i])
            v[i] = true;
    }
    v[x] = true;
    q[rear++] = x;
    dist[x] = 0;
    if (!indicator)
        father[x] = 0;
    while (front != rear){
        int now = q[front++];
        for (int i = head[now]; i != 0; i = e[i].next){
            int next = e[i].v;
            if (!v[next]){
                dist[next] = dist[now] + e[i].w;
                if (!indicator)
                    father[next] = now;
                if (dist[ret] < dist[next])
                    ret = next;
                q[rear++] = next;
                v[next] = true;
            }
        }
    }
    return ret;
}

int main(){
    cin >> n >> s;
    for (int i = 1; i < n; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    p1 = dis(1, 0);
    p2 = dis(p1, 0);
    int ans = INF, p = p2;
    for (int i = p2; i != 0; i = father[i]){
        while (father[p] != 0 && dist[i] - dist[father[p]] <= s)
            p = father[p];
        ans = min(ans, max(dist[p], dist[p2] - dist[i]));
    }
    for (int i = p2; i != 0; i = father[i])
        dis(i, 1);
    for (int i = 1; i <= n; ++i)
        ans = max(ans, dist[i]);
    cout << ans << endl;
    return 0;
}
