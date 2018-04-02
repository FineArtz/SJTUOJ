/* 二哥吵架 */
#include <iostream>
using namespace std;

int n, k, ans = 0;
int op, x, y;
int p[100005], r[100005];

int parent(int x){
    if (x != p[x]){
        int t = p[x];
        p[x] = parent(p[x]);
        r[x] = (r[x] + r[t]) % 3;
    }
    return p[x];
}

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        p[i] = i;
        r[i] = 0;
    }
    while (k--){
        cin >> op >> x >> y;
        if (x > n || y > n){
            ++ans;
            continue;
        }
        if (op == 2 && x == y){
            ++ans;
            continue;
        }
        int px = parent(x), py = parent(y);
        if (px == py){
            if (r[y] != (r[x] + op - 1) % 3)
                ++ans;
        }
        else{
            p[py] = px;
            r[py] = (3 - r[y] + r[x] + op - 1) % 3;
        }
    }
    cout << ans << endl;
}
