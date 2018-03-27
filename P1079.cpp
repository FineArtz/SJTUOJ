/* 贪吃的九头龙 */
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int INF = 1000000000;

class Node{
public:
    int child = 0, sibling = 0, father = 0;
    int lenf = 0;
    int ecnt = 0, edge[305] = {0}, w[305] = {0};
};

int n, m, k;
Node a[305];
int f[305][305][2] = {0};

void makeTree(int x, int f){
    a[x].father = f;
    if (a[x].ecnt == 1)
        return;
    for (int i = 1; i <= a[x].ecnt; ++i){
        if (a[x].edge[i] != f){
            if (a[x].child == 0){
                a[x].child = a[x].edge[i];
                a[a[x].child].lenf = a[x].w[i];
            }
            else{
                int t = a[x].child;
                while (a[t].sibling != 0)
                    t = a[t].sibling;
                a[t].sibling = a[x].edge[i];
                a[a[t].sibling].lenf = a[x].w[i];
            }
            makeTree(a[x].edge[i], x);
        }
    }
}

void printTree(int x){
    if (x == 0)
        return;
    cout << x << endl;
    printTree(a[x].child);
    printTree(a[x].sibling);
}

int factor(int x, int y){
    if (x > 0 && y > 0)
        return 1;
    if (x == 0 && y == 0 && m == 2)
        return 1;
    return 0;
}

int dp(int x, int k, int b){
    if (f[x][k][b] != -1)
        return f[x][k][b];
    int ret = INF;
    for (int i = 0; i <= k; ++i){
        int t = dp(a[x].child, i, 0) + dp(a[x].sibling, k - i, b) + factor(b, 0) * a[x].lenf;
        ret = min(ret, t);
    }
    for (int i = 0; i < k; ++i){
        int t = dp(a[x].child, i, 1) + dp(a[x].sibling, k - i - 1, b) + factor(b, 1) * a[x].lenf;
        ret = min(ret, t);
    }
    f[x][k][b] = ret;
    return ret;
}

int main(){
    cin >> n >> m >> k;
    if (m + k - 1 > n){
        cout << "-1" << endl;
        return 0;
    }
    for (int i = 1; i <= n - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].edge[++a[u].ecnt] = v;
        a[u].w[a[u].ecnt] = w;
        a[v].edge[++a[v].ecnt] = u;
        a[v].w[a[v].ecnt] = w;
    }
    makeTree(1, 0);
    memset(f, -1, sizeof(f));
    f[0][0][0] = f[0][0][1] = 0;
    for (int i = 1; i <= k; ++i){
        f[0][i][0] = INF;
        f[0][i][1] = INF;
    }
    cout << dp(a[1].child, k - 1, 1) << endl;
    return 0;
}
