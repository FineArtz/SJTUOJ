/* 小M家的牛们 */
#include <iostream>
#include <cstring>
using namespace std;

int f[2005][2005] = {0};

int main(){
    int n, m;
    cin >> n >> m;
    char s[2005];
    cin >> s;
    int add[26], del[26];
    for (int i = 1; i <= n; ++i){
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        add[ch - 'a'] = x;
        del[ch - 'a'] = y;
    }
    for (int i = m - 2; i >= 0; --i){
        for (int j = i; j < m; ++j){
            if (s[i] == s[j])
                f[i][j] = f[i + 1][j - 1];
            else{
                int t = 200000000;
                t = min(f[i + 1][j] + add[s[i] - 'a'], t);
                t = min(f[i + 1][j] + del[s[i] - 'a'], t);
                t = min(f[i][j - 1] + add[s[j] - 'a'], t);
                t = min(f[i][j - 1] + del[s[j] - 'a'], t);
                f[i][j] = t;
            }
        }
    }
    cout << f[0][m - 1] << endl;
    return 0;
}
