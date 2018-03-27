/* ÇóºÍÓÎÏ· */
#include <iostream>
using namespace std;

int main(){
    int n, t;
    cin >> n;
    cin >> t;
    int MinSum = t, CurSum = t, ans = t;
    for (int i = 2; i <= n; ++i){
        cin >> t;
        CurSum += t;
        ans = max(ans, CurSum - MinSum);
        MinSum = min(MinSum, CurSum - t);
    }
    if (ans > 0) cout << ans << endl;
    else cout << "Game Over" << endl;
    //cout << ans << endl;
    return 0;
}
