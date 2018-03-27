/* Tanning Salon */
#include <iostream>
#include <cstring>
using namespace std;

void solve(int n){
    int a[27] = {0}, b[27] = {0};
    char s[1000];
    cin >> s;
    int m = 0, ans = 0, len = strlen(s);
    for (int i = 0; i < len; ++i){
        char ch = s[i];
        if (m < n){
            if (a[ch - 'A'] == 0){
                ++m;
                a[ch - 'A'] = 1;
            }
            else{
                --m;
                a[ch - 'A'] = 0;
            }
        }
        else{
            if (a[ch - 'A'] == 1){
                --m;
                a[ch - 'A'] = 0;
            }
            else if (b[ch - 'A'] == 0){
                ++ans;
                b[ch - 'A'] = 1;
            }
        }
    }
    if (ans)
        cout << ans << " customer(s) walked away." << endl;
    else
        cout << "All customers tanned successfully." << endl;
}

int main(){
    int n;
    cin >> n;
    while (n != 0){
        solve(n);
        cin >> n;
    }
    return 0;
}
