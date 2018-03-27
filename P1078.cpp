/* Jerry的生日礼物 */
#include <iostream>
#include <cstring>
using namespace std;

class Edge{
public:
    Edge() = default;
    Edge(int uu, int vv, int ww, int nn) : u(uu), v(vv), w(ww), next(nn) {}

    int u = 0, v = 0, w = 0, next = 0;
};

Edge e[400005];
int head[200005], cnt = 0;
long long d1[200005] = {0}, d2[200005] = {0};
int n, m;

void addEdge(int u, int v, int w){
    e[++cnt] = Edge(u, v, w, head[u]);
    head[u] = cnt;
}

int distance(int x, long long *a){
    int ret = 0;
    bool v[200005] = {0};
    int q[200005], front = 0, rear = 0;
    a[x] = 0;
    v[x] = true;
    q[rear++] = x;
    while (front != rear){
        int now = q[front++];
        for (int i = head[now]; i != -1; i = e[i].next){
            int next = e[i].v;
            if (!v[next]){
                a[next] = a[now] + e[i].w;
                if (a[ret] < a[next])
                    ret = next;
                q[rear++] = next;
                v[next] = true;
            }
        }
    }
    return ret;
}

int main(){
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    int p1 = distance(1, d1);
    int p2 = distance(p1, d1);
    distance(p2, d2);
    long long ans = 0;
    for (int i = 1; i <= n; ++i){
        ans = max(ans, min(d1[i], d2[i]));
    }
    ans += d1[p2];
    cout << ans << endl;
    return 0;
}
