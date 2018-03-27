/* 小X的邮票 */
#include <iostream>
using namespace std;

int k, n, m = 0, ans = 0;
int a[205] = {0}, f[2000005] = {0};

int main(){
    cin >> k >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        f[a[i]] = 1;
        if (a[i] > m)
            m = a[i];
    }
    for (int i = 1; i <= m * k; ++i)
        if (f[i] == 0)
            f[i] = 500;
    ans = m * k;
    for (int i = 1; i <= m * k; ++i){
        for (int j = 1; j <= n; ++j){
            f[i + a[j]] = min(f[i + a[j]], f[i] + 1);
        }
        if (f[i] > k){
            ans = i - 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
