/* ¥Û •«–µ∞∏‚ */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double pi = 3.1415926;

int main(){
    double r, a, ans = 0.0;
    while (cin >> r >> a){
        double tans = acos(a/r) * r * r;
        tans -= a * sqrt(r * r - a * a);
        if (ans < tans) ans = tans;
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    return 0;
}
