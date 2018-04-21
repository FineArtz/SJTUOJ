/* Spice and Wolf */
#include <iostream>
#include <cstring>
using namespace std;

int t, n;
long long a[1005], p[1005], f[1005], s[1005];

int main(){
    cin >> t;
    while (t--){
        memset(a, 0, sizeof(a));
        memset(p, 0, sizeof(p));
        memset(f, 0, sizeof(f));
        memset(s, 0, sizeof(s));
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i] >> p[i];
            s[i] = a[i] + s[i - 1];
        }
        f[1] = (a[1] + 10) * p[1];
        for (int i = 2; i <= n; ++i){
            f[i] = 2147483647;
            for (int j = 0; j < i; ++j){
                f[i] = min(f[i], f[j] + (s[i] - s[j] + 10) * p[i]);
            }
        }
        cout << f[n] << endl;
    }
    return 0;
}
