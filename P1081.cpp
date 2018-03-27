/* 选课 */
#include <iostream>
#include <cstring>
using namespace std;

const int INF = 100000000;

class Node{
public:
    int edge[201] = {0}, ecnt = 0, score = 0;
    int child = 0, sibling = 0, father = 0;
};

Node a[205];
int m, n;
int f[205][205] = {0};

void makeTree(int x){
    for (int i = 1; i <= a[x].ecnt; ++i){
        if (a[x].child == 0)
            a[x].child = a[x].edge[i];
        else{
            int t = a[x].child;
            while (a[t].sibling != 0)
                t = a[t].sibling;
            a[t].sibling = a[x].edge[i];
        }
        makeTree(a[x].edge[i]);
    }
}

void printTree(int x){
    cout << x << endl;
    if (a[x].child != 0)
        printTree(a[x].child);
    if (a[x].sibling != 0)
        printTree(a[x].sibling);
}

int dp(int x, int k){
    if (f[x][k] != -1)
        return f[x][k];
    int ret = -INF;
    for (int i = 0; i < k; ++i){
        int t = dp(a[x].child, i) + dp(a[x].sibling, k - i - 1) + a[x].score;
        ret = max(ret, t);
    }
    ret = max(ret, dp(a[x].sibling, k));
    f[x][k] = ret;
    return ret;
}

int main(){
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        int v, w;
        cin >> v >> w;
        a[v].edge[++a[v].ecnt] = i;
        a[i].score = w;
        a[i].father = v;
    }
    makeTree(0);
    //printTree(0);
    memset(f, -1, sizeof(f));
    for (int i = 0; i <= m; ++i)
        f[i][0] = 0;
    for (int i = 0; i <= n; ++i)
        f[0][i] = 0;
    cout << dp(a[0].child, n) << endl;
    return 0;
}
