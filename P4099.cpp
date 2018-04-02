/* Love and Auto Memories Doll */
#include <iostream>
#include <cstring>
using namespace std;

inline void lowercase(char *s, int len){
    for (int i = 0; i < len; ++i)
        if (s[i] < 'a')
            s[i] = s[i] + 'a' - 'A';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char s[255], w[255];
    cin >> s;
    int n, lens = strlen(s);
    lowercase(s, lens);
    cin >> n;
    int ans = 0, cnt = 0;
    while (n--){
        cin >> w;
        int l = strlen(w);
        lowercase(w, l);
        if (lens != l){
            if (cnt == 0)
                ans += l;
        }
        else{
            bool flag = true;
            for (int i = 0; i < l; ++i){
                if (s[i] != w[i]){
                    flag = false;
                    break;
                }
            }
            if (flag){
                ++cnt;
            }
            else{
                if (cnt == 0)
                    ans += l;
            }
        }
    }
    if (cnt == 0)
        cout << "-1\n";
    else
        cout << cnt << ' ' << ans << '\n';
    return 0;
}
