/* 小M的奶牛 */
#include <iostream>
using namespace std;

const int DEL = 100000;
const int INF = 2000000000;

int main(){
    int n;
    int s[105], f[105];
    int a[100005 + DEL];
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> s[i] >> f[i];
    }
    for (int i = 0; i <= 100000 + DEL; ++i)
        a[i] = -INF;
    a[DEL] = 0;
    for (int i = 1; i <= n; ++i){
        if (s[i] > 0){
            for (int j = 100000 + DEL; j >= s[i]; --j)
                if (a[j - s[i]] != -INF)
                    a[j] = max(a[j], a[j - s[i]] + f[i]);
        }
        else{
            for (int j = 0; j <= s[i] + 100000 + DEL; ++j)
                if (a[j - s[i]] != -INF)
                    a[j] = max(a[j], a[j - s[i]] + f[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100000; ++i)
        if (a[i + DEL] >= 0)
            ans = max(ans, a[i + DEL] + i);
    cout << ans << endl;
    return 0;
}
