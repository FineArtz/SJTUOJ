/* ÎªÁË³æÈº */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double INF = 10e7 * 3.0;
double x[100005];
int n, k;

bool check(double p){
    int nowl = 1, cnt = 1;
    for (int i = 2; i <= n; ++i){
        if (x[i] - x[nowl] - 2 * p < 10e-8) continue;
        else{
            ++cnt;
            nowl = i;
            if (cnt > k) return false;
        }
    }
    return true;
}
int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> x[i];
    double ans = INF, lans = INF;
    double l = 0.0, r = x[n] - x[1], m = (l + r) / 2;
    while (l - r < 10e-8){
        if (check(m)){
			lans = ans;
            ans = m;
            r = m;
            if (abs(lans - ans) < 10e-8) break;
        }
        else l = m;
        m = (l + r) / 2;
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}
