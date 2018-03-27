/* Dijkstra */
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 10000;

int a[100][100];
int dist[100], pr[100];
int n, m, st;

void dijkstra(int st){
    bool v[100];
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; ++i){
        dist[i] = a[st][i];
        if (dist[i] == INF) pr[i] = -1;
        else pr[i] = st;
    }
    dist[st] = 0;
    v[st] = true;
    for (int i = 2; i <= n; ++i){
        int mind = INF, minp = 0;
        for (int j = 1; j <= n; ++j){
            if (!v[j] && dist[j] < mind){
                mind = dist[j];
                minp = j;
            }
        }
        v[minp] = true;
        for (int j = 1; j <= n; ++j){
            if (!v[j] && a[minp][j] != INF && dist[j] > dist[minp] + a[minp][j]){
                dist[j] = dist[minp] + a[minp][j];
                pr[j] = minp;
            }
        }
    }
}

int main(){
    cin >> n >> m >> st;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            a[i][j] = INF;
    for (int i = 0; i != m; ++i){
        int x, y, d;
        cin >> x >> y >> d;
        if (a[x][y] > d){
            a[x][y] = d;
            a[y][x] = d;
        }
    }
    dijkstra(st);
    for (int i = 1; i <= n; ++i){
        if (dist[i] == INF) cout << -1 << endl;
        else cout << dist[i] << endl;
    }
    return 0;
}
