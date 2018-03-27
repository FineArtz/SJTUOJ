/* 小X的生物实验 */
#include <iostream>
using namespace std;

int pos[1000005][5], a[1000005];
int n;

inline int lowbit(int x){
    return x & (-x);
}

void change(int x, int y){
    while (x <= n){
        a[x] = max(a[x], y);
        x += lowbit(x);
    }
}

int find(int x){
    int ret = 0;
    while (x != 0){
        ret = max(ret, a[x]);
        x -= lowbit(x);
    }
    return ret;
}

int main(){
    cin >> n;
    n *= 5;
    for (int i = 1; i <= n; ++i){
        int x, j = 0;
        cin >> x;
        while (pos[x][j])
            ++j;
        pos[x][j] = i;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        for (int j = 4; ~j; --j){
            int t = find(pos[x][j] - 1) + 1;
            ans = max(t, ans);
            change(pos[x][j], t);
        }
    }
    cout << ans << endl;
    return 0;
}
