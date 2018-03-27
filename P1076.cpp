/* 小F的苹果树 */
#include <iostream>
#include <set>
using namespace std;

class Node{
public:
    set<int> edge;
    int father = 0;
    int apple = 0, sumApple = 0, sum = 0;
};

class Edge{
public:
    int u = 0, v = 0, w = 0;
};

Node a[105];
Edge e[105];
int n, q;
int f[105][105] = {0};

void buildTree(int x, int f){
    a[x].father = f;
    for (int i : a[x].edge){
        if (i != f)
            buildTree(i, x);
    }
}

void countApple(int x){
    a[x].sumApple = a[x].apple;
    a[x].sum = 1;
    for (int i : a[x].edge){
        if (i != a[x].father){
            countApple(i);
            a[x].sumApple += a[i].sumApple;
            a[x].sum += a[i].sum;
        }
    }
}

int dp(int x, int m){
    if (f[x][m] != 0)
        return f[x][m];
    if (m == 0){
        f[x][m] = 0;
        return 0;
    }
    if (m >= a[x].sum){
        f[x][m] = a[x].sumApple;
        return f[x][m];
    }
    if (a[x].edge.size() == 1){
        f[x][m] = a[x].apple;
        return f[x][m];
    }
    int s1 = 0, s2 = 0;
    for (int i : a[x].edge){
        if (i != a[x].father){
            if (s1 == 0)
                s1 = i;
            else
                s2 = i;
        }
    }
    for (int k = 0; k < m; ++k){
        f[x][m] = max(f[x][m], dp(s1, k) + dp(s2, m - k - 1) + a[x].apple);
    }
    return f[x][m];
}

void print(int x){
    cout << x << ' ' << a[x].father << ' ' << a[x].apple << ' ' << a[x].sumApple << ' ' << a[x].sum << endl;
    for (int i : a[x].edge)
        if (i != a[x].father)
            print(i);
}

int main(){
    cin >> n >> q;
    for (int i = 1; i < n; ++i){
        cin >> e[i].u >> e[i].v >> e[i].w;
        a[e[i].u].edge.insert(e[i].v);
        a[e[i].v].edge.insert(e[i].u);
    }
    buildTree(1, 0);
    for (int i = 1; i < n; ++i){
        if (a[e[i].u].father == e[i].v)
            a[e[i].u].apple = e[i].w;
        else
            a[e[i].v].apple = e[i].w;
    }
    countApple(1);
    //print(1);
    ++q;
    dp(1, q);
    cout << f[1][q] << endl;
    return 0;
}
