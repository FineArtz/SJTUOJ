/* 二哥的吊灯 */
#include <iostream>
using namespace std;

class Node{
public:
    int l = 0, r = 0, total = 0, red = 0;
    bool isRed = false;
};

Node a[100005];
int pos[100005];
bool b[100005];
int n, p, q;

int count1(int x){
    int r = 0;
    if (a[x].l != 0)
        r += count1(pos[a[x].l]);
    if (a[x].r != 0)
        r += count1(pos[a[x].r]);
    a[x].total = r + 1;
    return a[x].total;
}

void dye(int t, int x){
    int y = a[pos[a[t].l]].total;
    if (y == x - 1){
        a[t].isRed = true;
        return;
    }
    else if (y < x - 1){
        dye(pos[a[t].r], x - y - 1);
    }
    else{
        dye(pos[a[t].l], x);
    }
}

int count2(int x){
    int r = 0;
    if (a[x].l != 0)
        r += count2(pos[a[x].l]);
    if (a[x].r != 0)
        r += count2(pos[a[x].r]);
    if (a[x].isRed)
        ++r;
    a[x].red = r;
    return a[x].red;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> p >> q;
    for (int i = 1; i <= n; ++i){
        int x, lx, rx;
        cin >> x >> lx >> rx;
        a[i].l = lx;
        a[i].r = rx;
        b[lx] = true;
        b[rx] = true;
        pos[x] = i;
    }
    int root = 0;
    for (int i = 1; i <= n; ++i){
        if (!b[i]){
            root = i;
            break;
        }
    }
    count1(pos[root]);
    while (p--){
        int t, x;
        cin >> t >> x;
        dye(pos[t], x % a[pos[t]].total + 1);
    }
    count2(pos[root]);
    while (q--){
        int x;
        cin >> x;
        cout << a[pos[x]].red << '\n';
    }
    return 0;
}
