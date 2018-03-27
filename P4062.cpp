/* 日天圈地 */
#include <iostream>
using namespace std;

long long f(long long x, long long y){
    long long t, ret;
    if (x > y){
        t = x;
        x = y;
        y = t;
    }
    ret = 4 * x * (y / x);
    y = y % x;
    if (y == 0) return ret;
    else return ret + f(y, x);
}

int main(){
    long long x, y, ans;
    cin >> x >> y;
    ans = f(x, y);
    cout << ans << endl;
    return 0;
}
