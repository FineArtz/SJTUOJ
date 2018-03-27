/* 二哥买草 */
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int x, int y){
    return x > y;
}

int main(){
    int m, n;
    int a[10005], b[10005];
    cin >> n >> m;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i){
        cin >> b[i];
    }
    sort(a, a + n, cmp);
    sort(b, b + m, cmp);
    int ans = n, j = 0;
    for (int i = 0; i < n; ++i){
        while (j < m && a[i] <= b[j])
            ++j;
        if (j == m)
            break;
        ++ans;
        ++j;
    }
    cout << ans << endl;
    return 0;
}
