/* Seven Apples 0n a Witch's Tree */
#include <iostream>
using namespace std;

const int MAXN = 100000;

int head[MAXN + 5], nxt[MAXN + 5], e[MAXN + 5], cnt = 0;
bool b[MAXN + 5] = {false};
int n, m, root = 0;
int in[MAXN + 5], out[MAXN + 5], seq[MAXN + 5], t = 0;
bool apple[MAXN + 5] = {false};

struct Node{
    int l = 0, r = 0, sum = 0;
};

Node a[MAXN * 4 + 5];

void addEdge(int u, int v){
    ++cnt;
    nxt[cnt] = head[u];
    e[cnt] = v;
    head[u] = cnt;
}

void dfs(int x){
    in[x] = t;
    seq[t] = x;
    for (int i = head[x]; i != 0; i = nxt[i]){
        ++t;
        dfs(e[i]);
    }
    out[x] = t;
}

void buildTree(int x, int l, int r){
    a[x].l = l;
    a[x].r = r;
    if (l == r){
        a[x].sum = 1;
        return;
    }
    int mid = (l + r) / 2;
    buildTree(x * 2, l, mid);
    buildTree(x * 2 + 1, mid + 1, r);
    a[x].sum = a[x * 2].sum + a[x * 2 + 1].sum;
};

void update(int x, int p, int d){
    if (a[x].l == a[x].r){
        a[x].sum += d;
        return;
    }
    int mid = (a[x].l + a[x].r) / 2;
    if (p <= mid)
        update(x * 2, p, d);
    else
        update(x * 2 + 1, p, d);
    a[x].sum = a[x * 2].sum + a[x * 2 + 1].sum;
}

int query(int x, int l, int r){
    if (a[x].l >= l && a[x].r <= r)
        return a[x].sum;
    int mid = (a[x].l + a[x].r) / 2;
    int ret = 0;
    if (mid >= l)
        ret += query(x * 2, l, r);
    if (mid < r)
        ret += query(x * 2 + 1, l, r);
    return ret;
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
        b[v] = true;
    }
    for (int i = 1; i <= n; ++i){
        if (!b[i]){
            root = i;
            break;
        }
    }
    t = 1;
    dfs(root);
    for (int i = 1; i <= n; ++i)
        apple[i] = true;
    buildTree(1, 1, n);

    cin >> m;
    while (m--){
        char op;
        int x;
        cin >> op >> x;
        if (op == 'C'){
            if (apple[x]){
                apple[x] = false;
                update(1, in[x], -1);
            }
            else{
                apple[x] = true;
                update(1, in[x], 1);
            }
        }
        else if (op == 'Q'){
            cout << query(1, in[x], out[x]) << '\n';
        }
    }
    return 0;
}
