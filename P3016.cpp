/* ¾ù·ÖÖ½ÅÆ */
#include <iostream>
using namespace std;

int main(){
    int n;
    int a[105] = {0};
    cin >> n;
    int ave = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        ave += a[i];
    }
    ave /= n;
    int ans = 0;
    for (int i = 0; i < n - 1; ++i){
        if (a[i] < ave){
            ++ans;
            a[i + 1] -= ave - a[i];
            a[i] = ave;
        }
        else if (a[i] > ave){
            ++ans;
            a[i + 1] += a[i] - ave;
            a[i] = ave;
        }
    }
    cout << ans << endl;
    return 0;
}
