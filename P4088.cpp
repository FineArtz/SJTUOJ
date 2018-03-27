/* 运动校园 */
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long f, T, t0, a1, t1, p1, a2, t2, p2;
    cin >> f >> T >> t0;
    cin >> a1 >> t1 >> p1;
    cin >> a2 >> t2 >> p2;
    long long c1 = -a1 * (t1 - t0), c2 = -a2 * (t2 - t0), n = -T + f * t0;
    long long ans = 10000000000000000ll, y = 0, z = 0;
    if (n <= 0){
        cout << "0" << endl;
        return 0;
    }
    if (c1 <= 0 && c2 <= 0){
        cout << "-1" << endl;
        return 0;
    }
    if (c1 <= 0){
        z = n / c2;
        if (n % c2 != 0) ++z;
        cout << z * p2 << endl;
        return 0;
    }
    if (c2 <= 0){
        y = n / c1;
        if (n % c1 != 0) ++y;
        cout << y * p1 << endl;
        return 0;
    }
    for (long long y = 0; ; ++y){
        long long t = n - c1 * y;
        if (t <= 0) z = 0;
        else{
            z = t / c2;
            if (t % c2 != 0) ++z;
        }
        long long p = y * p1 + z * p2;
        if (ans > p) ans = p;
        if (t <= 0) break;
    }
    if (ans == 10000000000000000ll)
        cout << "-1" << endl;
    else
        cout << ans << endl;
    return 0;
}
