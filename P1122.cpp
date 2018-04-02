/* 二哥开房间 */
#include <iostream>
using namespace std;

const int MAXN = 50000;

struct Node{
    int l = 0, r = 0;
    int lsum = 0, rsum = 0, sum = 0;
    int lazy = 0; //0: None, 1: occupied, 2: recycled
};

Node a[MAXN * 4 + 5];
int n, m;

void pushUp(int x){
    a[x].lsum = a[x << 1].lsum;
    a[x].rsum = a[x << 1 | 1].rsum;
    int mid = (a[x].l + a[x].r) >> 1;
    if (a[x << 1].lsum == mid - a[x].l + 1)
        a[x].lsum += a[x << 1 | 1].lsum;
    if (a[x << 1 | 1].rsum == a[x].r - mid)
        a[x].rsum += a[x << 1].rsum;
    a[x].sum = max(a[x << 1].rsum + a[x << 1 | 1].lsum, max(a[x << 1].sum, a[x << 1 | 1].sum));
}

void pushDown(int x){
    if (a[x].lazy == 0)
        return;
    int mid = (a[x].l + a[x].r) >> 1;
    a[x << 1].lazy = a[x << 1 | 1].lazy = a[x].lazy;
    if (a[x].lazy == 1){
        a[x << 1].lsum = a[x << 1].rsum = a[x << 1].sum = 0;
        a[x << 1 | 1].lsum = a[x << 1 | 1].rsum = a[x << 1 | 1].sum = 0;
    }
    else{
        a[x << 1].lsum = a[x << 1].rsum = a[x << 1].sum = mid - a[x].l + 1;
        a[x << 1 | 1].lsum = a[x << 1 | 1].rsum = a[x << 1 | 1].sum = a[x].r - mid;
    }
    a[x].lazy = 0;
}

void buildTree(int x, int l, int r){
    a[x].l = l;
    a[x].r = r;
    if (l == r){
        a[x].lsum = a[x].rsum = a[x].sum = 1;
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(x << 1, l, mid);
    buildTree(x << 1 | 1, mid + 1, r);
    pushUp(x);
}

void update(int x, int l, int r, int lazy){
    if (a[x].l >= l && a[x].r <= r){
        a[x].lazy = lazy;
        if (lazy == 1)
            a[x].lsum = a[x].rsum = a[x].sum = 0;
        else
            a[x].lsum = a[x].rsum = a[x].sum = a[x].r - a[x].l + 1;
        return;
    }
    pushDown(x);
    int mid = (a[x].l + a[x].r) >> 1;
    if (l <= mid)
        update(x << 1, l, r, lazy);
    if (r > mid)
        update(x << 1 | 1, l, r, lazy);
    pushUp(x);
}

int query(int x, int len){
    if (a[x].l == a[x].r)
        return a[x].l;
    pushDown(x);
    int mid = (a[x].l + a[x].r) >> 1;
    if (a[x << 1].sum >= len)
        return query(x << 1, len);
    else if (a[x << 1].rsum + a[x << 1 | 1].lsum >= len)
        return mid - a[x << 1].rsum + 1;
    else
        return query(x << 1 | 1, len);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    buildTree(1, 1, n);
    while (m--){
        int op, x, y;
        cin >> op;
        switch (op){
        case 1:
            cin >> x;
            if (x > a[1].sum)
                cout << 0 << '\n';
            else{
                y = query(1, x);
                cout << y << '\n';
                update(1, y, y + x - 1, 1);
            }
            break;
        case 2:
            cin >> x >> y;
            update(1, x, x + y - 1, 2);
            break;
        }
    }
    return 0;
}
