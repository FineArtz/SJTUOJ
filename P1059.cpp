/* 三元组 */
#include <iostream>
#include <algorithm>
using namespace std;

const unsigned long long MOD = 100000000, MOD2 = 5000005;
const unsigned long long SEED = 13131313131313LL;

int h[5000005], cnt[5000005];

int Hash(int x){
    unsigned long long t = 0;
    while (x){
        t = t * SEED + x % 10;
        x /= 10;
    }
    return (t % MOD2);
}

int find(int x){
    int hs = Hash(x);
    while (h[hs] != 0){
        if (h[hs] == x)
            return cnt[hs];
        hs = (hs + 1) % MOD2;
    }
    return 0;
}

int main(){
    long long a[2005];
    int n;
    bool flag = false;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        int hs = Hash(a[i]);
        while (h[hs] != 0){
            if (h[hs] == a[i]){
                ++cnt[hs];
                flag = true;
                break;
            }
            hs = (hs + 1) % MOD2;
        }
        if (!flag){
            h[hs] = a[i];
            cnt[hs] = 1;
        }
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    long long k = 0;
    for (int i = 1; i <= n - 1; ++i){
        for (int j = i + 1; j <= n; ++j){
            if (i != j){
                k = a[i] * a[j] % MOD;
                int c = find(k);
                if (c != 0){
                    ans += 2 * c;
                    if (a[i] == k) ans -= 2;
                    if (a[j] == k) ans -= 2;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
