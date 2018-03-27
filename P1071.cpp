/* 小M的回文串 */
#include <iostream>
#include <cstring>
using namespace std;

const long long INF = 100000000000000LL;

int main(){
    char s[51];
    cin >> s;
    int n, m = strlen(s);
    cin >> n;
    long long a[256], e[256], c[256][256];
    long long cost[256];
    for (int i = 0; i < 256; ++i){
        a[i] = INF;
        e[i] = INF;
        cost[i] = INF;
        for (int j = 0; j < 256; ++j){
            if (i == j)
                c[i][j] = 0;
            else
                c[i][j] = INF;
        }
    }
    for (int i = 1; i <= n; ++i){
        char t[10];
        char x, y;
        int w;
        cin >> t;
        switch(t[0]){
        case 'a':
            cin >> x >> w;
            a[x] = w;
            break;
        case 'e':
            cin >> x >> w;
            e[x] = w;
            break;
        case 'c':
            cin >> x >> y >> w;
            c[x][y] = w;
            break;
        }
    }
    for (int k = 0; k < 256; ++k){
        for (int i = 0; i < 256; ++i){
            for (int j = 0; j < 256; ++j){
                if (i != j && i != k && j != k)
                    if (c[i][j] > c[i][k] + c[k][j])
                        c[i][j] = c[i][k] + c[k][j];
            }
        }
    }
    for (int i = 0; i < 256; ++i){
        for (int j = 0; j < 256; ++j){
            cost[i] = min(cost[i], min(a[i], e[i]));
            cost[i] = min(cost[i], c[i][j] + min(a[j], e[j]));
            cost[i] = min(cost[i], a[j] + c[j][i]);
            for (int k = 0; k < 256; ++k)
                cost[i] = min(cost[i], c[i][j] + a[k] + c[k][j]);
        }
    }
    long long f[51][51] = {0};
    for (int i = m - 2; i >= 0; --i){
        for (int j = i + 1; j < m; ++j){
            if (s[i] == s[j])
                f[i][j] = f[i + 1][j - 1];
            else{
                f[i][j] = INF;
                f[i][j] = min(f[i][j], f[i + 1][j] + cost[s[i]]);
                f[i][j] = min(f[i][j], f[i][j - 1] + cost[s[j]]);
                f[i][j] = min(f[i][j], f[i + 1][j - 1] + min(c[s[j]][s[i]], c[s[i]][s[j]]));
                for (int k = 0; k < 256; ++k)
                    f[i][j] = min(f[i][j], f[i + 1][j - 1] + c[s[i]][k] + c[s[j]][k]);
            }
        }
    }
    if (f[0][m - 1] == INF)
        cout << "-1" << endl;
    else
        cout << f[0][m - 1] << endl;
    return 0;
}
