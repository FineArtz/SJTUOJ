/* Nene tchi's Disaster */
#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
    int l = 0, r = 0, sum = 0;

    Node() = default;
};

Node a[1000010 * 4];
long long b[1000010], ans[1000010];
int t, n;

void buildTree(int x, int l, int r){
    a[x].l = l;
    a[x].r = r;
    if (l == r)
        a[x].sum = 1;
    else{
        int mid = (l + r) / 2;
        buildTree(x * 2, l, mid);
        buildTree(x * 2 + 1, mid + 1, r);
        a[x].sum = a[x * 2].sum + a[x * 2 + 1].sum;
    }
}

int findk(int x, int k){
    if (a[x].l == a[x].r)
        return a[x].l;
    if (a[x * 2].sum >= k)
        return findk(x * 2, k);
    else
        return findk(x * 2 + 1, k - a[x * 2].sum);
}

void remove(int x, int k){
    if (a[x].l == a[x].r){
        a[x].sum = 0;
        return;
    }
    int mid = (a[x].l + a[x].r) / 2;
    if (k <= mid)
        remove(x * 2, k);
    else
        remove(x * 2 + 1, k);
    --a[x].sum;
}

void solve(){
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(ans, 0, sizeof(ans));
    cin >> n;
    buildTree(1, 1, n);
    for (int i = 1; i <= n; ++i)
        cin >> b[i];
    for (int i = n; i > 1; --i){
        int d = b[i] - b[i - 1];
        ans[i] = findk(1, i - d);
        remove(1, ans[i]);
    }
    ans[1] = findk(1, 1);
    cout << 1 << endl;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ' ';
    cout << endl;
}

int main(){
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
