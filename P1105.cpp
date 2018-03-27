/* path */
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 400000000;

int a[1005][1005][3] = {0};

inline int getNum(char *s){
    int i = 0;
    while (i < strlen(s) && !isdigit(s[i]))
        ++i;
    int ret = 0;
    while (i < strlen(s) && isdigit(s[i])){
        ret = ret * 10 + s[i] - '0';
        ++i;
    }
    return ret;
}

inline void addEdge(int u, int v, int *w){
    for (int i = 0; i < 3; ++i){
        if (a[u][v][i] > w[i]){
            a[u][v][i] = w[i];
            a[v][u][i] = w[i];
        }
    }
}

int dijkstra(int n, int m, int k){
    bool vis[10005] = {0};
    int dis[10005] = {0};
    int q[10005], front = 0, rear = 0;
    for (int i = 1; i <= n; ++i)
        dis[i] = INF;
    dis[1] = 0;
    vis[1] = true;
    q[rear++] = 1;
    while (front != rear){
        int x = q[front++];
        vis[x] = false;
        for (int i = 1; i <= n; ++i){
            if (x != i){
                if (dis[i] > dis[x] + a[x][i][k]){
                    dis[i] = dis[x] + a[x][i][k];
                    if (!vis[i]){
                        q[rear++] = i;
                        vis[i] = true;
                    }
                }
            }
        }
    }
    return (dis[n] != INF ? dis[n] : -1);
}

void solve(int n, int m, int s, int t){
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                for (int k = 0; k < 3; ++k)
                    a[i][j][k] = INF;
    for (int i = 1; i <= m; ++i){
        char ss[1000];
        int len;
        int u, v, w[3];
        char ch;
        len = 0;
        while ((ch = getchar()) != ';'){
            ss[len++] = ch;
        }
        ss[len] = '\0';
        //cout << ss << endl;
        auto p = strstr(ss, "From: ");
        u = getNum(p);
        p = strstr(ss, "To: ");
        v = getNum(p);
        p = strstr(ss, "Length: ");
        w[0] = getNum(p);
        p = strstr(ss, "People number: ");
        w[1] = getNum(p);
        p = strstr(ss, "Light: ");
        w[2] = getNum(p);
        if (u == 1)
            u = s;
        else if (u == s)
            u = 1;
        else if (u == n)
            u = t;
        else if (u == t)
            u = n;
        if (v == 1)
            v = s;
        else if (v == s)
            v = 1;
        else if (v == n)
            v = t;
        else if (v == t)
            v = n;
        if (u != v)
            addEdge(u, v, w);
    }
    for (int i = 0; i < 3; ++i)
        cout << dijkstra(n, m, i) << ' ';
    cout << '\n';
}

int main(){
    int tt;
    cin >> tt;
    while (tt--){
        int n, m, s, t;
        cin >> n >> m >> s >> t;
        solve(n, m, s, t);
    }
    return 0;
}
