/* 炮兵阵地 */
#include <iostream>
using namespace std;

int mapping[1025];
long long f[105][65][65];
long long sum[65], sta[65], a[105];
int cnt = 0, n, m;

inline bool check(int x){
    return !((x & (x << 1)) || (x & (x << 2)));
}

int calcSum(int x){
    int ret = 0;
    while (x){
        ++ret;
        x = x & (x - 1);
    }
    return ret;
}

void init(){
    for (int i = 0; i < (1 << m); ++i){
        if (check(i)){
            sta[++cnt] = i;
            mapping[i] = cnt;
            sum[cnt] = calcSum(i);
        }
    }
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            char ch;
            cin >> ch;
            a[i] <<= 1;
            if (ch == 'H')
                a[i] = a[i] | 1;
        }
    }
    init();
    long long ans = 0;
    for (int i = 1; i <= cnt; ++i){
        if (!(sta[i] & a[1])){
            f[1][i][0] = max(f[1][i][0], sum[i]);
            ans = max(ans, f[1][i][0]);
        }
    }
    if (n == 1){
        cout << ans << endl;
        return 0;
    }
    for (int i = 1; i <= cnt; ++i){
        if (!(sta[i] & a[2])){
            for (int j = 1; j <= cnt; ++j){
                if (!(sta[j] & a[1])){
                    f[2][i][j] = max(f[2][i][j], f[1][j][0] + sum[i]);
                    ans = max(ans, f[1][i][0]);
                }
            }
        }
    }
    if (n == 2){
        cout << ans << endl;
        return 0;
    }
    for (int l = 3; l <= n; ++l){
        for (int i = 1; i <= cnt; ++i){
            if (!(sta[i] & a[l])){
                for (int j = 1; j <= cnt; ++j){
                    if (!(sta[j] & a[l - 1])){
                        for (int k = 1; k <= cnt; ++k){
                            if (!(sta[k] & a[l - 2])){
                                if (!((sta[i] & sta[j]) | (sta[i] & sta[k]) | (sta[j] & sta[k]))){
                                    f[l][i][j] = max(f[l][i][j], f[l - 1][j][k] + sum[i]);
                                    ans = max(ans, f[l][i][j]);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
