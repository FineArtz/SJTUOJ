/* This is a NP-Hard Problem */
#include <cstdio>
#include <cstring>
using namespace std;

int n, m;
int be[100005], head[100005], nxt[400005], edg[400005], cnt;

inline void addEdge(int u, int v){
    ++cnt;
    nxt[cnt] = head[u];
    edg[cnt] = v;
    head[u] = cnt;
}

bool check(int st){
    int q[100005] = {0};
    int front = 0, rear = 0;
    be[st] = 1;
    q[rear++] = st;
    while (front != rear){
        int now = q[front++];
        for (int i = head[now]; i; i = nxt[i]){
            if (be[edg[i]] == 0){
                int v = edg[i];
                be[v] = (be[now] == 1 ? -1 : 1);
                q[rear++] = v;
            }
            else if (be[edg[i]] != -be[now])
                return false;
        }
    }
    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t--){
        scanf("%d%d", &n, &m);
        memset(be, 0, sizeof(be));
        memset(head, 0, sizeof(head));
        memset(nxt, 0, sizeof(nxt));
        memset(edg, 0, sizeof(edg));
        cnt = 0;
        for (int i = 1; i <= m; ++i){
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        bool flag = true;
        for (int i = 1; i <= n; ++i){
            if (head[i] != 0 && be[i] == 0){
                if (!check(i)){
                    flag = false;
                    printf("-1\n");
                    break;
                }
            }
        }
        if (flag)
            printf("1\n");
    }
    return 0;
}