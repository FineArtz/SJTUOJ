/* 操作数组 */
#include <iostream>
using namespace std;

const int MAXN = 100000;

struct Node{
    int l = 0, r = 0;
    long long lazy = 0, sum = 0;
};

int n, q;
long long t[MAXN + 5];
Node a[MAXN * 4 + 5];

inline void pushUp(int x){
    a[x].sum = a[x * 2].sum + a[x * 2 + 1].sum;
}

inline void pushDown(int x){
    if (a[x].lazy != 0){
        a[x * 2].lazy += a[x].lazy;
        a[x * 2].sum += a[x].lazy * (a[x * 2].r - a[x * 2].l + 1);
        a[x * 2 + 1].lazy += a[x].lazy;
        a[x * 2 + 1].sum += a[x].lazy * (a[x * 2 + 1].r - a[x * 2 + 1].l + 1);
        a[x].lazy = 0;
    }
}

void buildTree(int x, int l, int r){
    a[x].l = l;
    a[x].r = r;
    if (l == r){
        a[x].sum = t[l];
        return;
    }
    int mid = (l + r) / 2;
    buildTree(x * 2, l, mid);
    buildTree(x * 2 + 1, mid + 1, r);
    pushUp(x);
}

void update(int x, int l, int r, int c){
    if (a[x].l >= l && a[x].r <= r){
        a[x].sum += c * (a[x].r - a[x].l + 1);
        a[x].lazy += c;
        return;
    }
    pushDown(x);
    int mid = (a[x].l + a[x].r) / 2;
    if (l <= mid)
        update(x * 2, l, r, c);
    if (r > mid)
        update(x * 2 + 1, l, r, c);
    pushUp(x);
}

long long query(int x, int l, int r){
    if (a[x].l >= l && a[x].r <= r)
        return a[x].sum;
    pushDown(x);
    int mid = (a[x].l + a[x].r) / 2;
    long long ret = 0;
    if (l <= mid)
        ret += query(x * 2, l, r);
    if (r > mid)
        ret += query(x * 2 + 1, l, r);
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> t[i];
    buildTree(1, 1, n);
    while (q--){
        char op;
        int x, y, z;
        cin >> op;
        if (op == 'Q'){
            cin >> x >> y;
            cout << query(1, x, y) << '\n';
        }
        else{
            cin >> x >> y >> z;
            update(1, x, y, z);
        }
    }
    return 0;
}
