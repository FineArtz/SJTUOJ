/* Problem A */
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 300005;

class Node{
public:
    int sum = 0, l = 0, r = 0;
};

int a[MAXN], s[MAXN], root[MAXN] = {0};
int cnt = 0;
Node tree[MAXN << 5];

int createNode(int sum, int l, int r){
    tree[++cnt].sum  = sum;
    tree[cnt].l = l;
    tree[cnt].r = r;
    return cnt;
}

void insert(int &root, int preroot, int pos, int l, int r){
    root = createNode(tree[preroot].sum + 1, tree[preroot].l, tree[preroot].r);
    if (l == r)
        return;
    int mid = (l + r) / 2;
    if (pos <= mid)
        insert(tree[root].l, tree[preroot].l, pos, l, mid);
    else
        insert(tree[root].r, tree[preroot].r, pos, mid + 1, r);
}

int query(int left, int right, int k, int l, int r){
    if (l == r)
        return l;
    int mid = (l + r) / 2;
    int sum = tree[tree[right].l].sum - tree[tree[left].l].sum;
    if (k <= sum)
        return query(tree[left].l, tree[right].l, k, l, mid);
    else
        return query(tree[left].r, tree[right].r, k - sum, mid + 1, r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        s[i] = a[i];
    }
    sort(s + 1, s + n + 1);
    int num = unique(s + 1, s + n + 1) - (s + 1);
    for (int i = 1; i <= n; ++i){
        int pos = lower_bound(s + 1, s + num + 1, a[i]) - s;
        insert(root[i], root[i - 1], pos, 1, num);
    }
    cin >> m;
    while (m--){
        int x, y, k;
        cin >> x >> y >> k;
        int t = query(root[x - 1], root[y], k, 1, num);
        cout << s[t] << '\n';
    }
    return 0;
}
