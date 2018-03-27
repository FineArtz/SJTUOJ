/* °£À­ÍĞÉ«ÄáÉ¸·¨ */
#include <iostream>
using namespace std;

bool isp[2000001];

int main(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i){
        if (!isp[i]){
            cout << i << ' ';
            for (int j = i; j <= n; j = j + i){
                isp[j] = true;
            }
        }
    }
    return 0;
}
