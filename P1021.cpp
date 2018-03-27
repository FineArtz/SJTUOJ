/* 从前有座山 */
#include <iostream>
#include <iomanip>
using namespace std;

inline long long min(long long a, long long b, long long c, long long d){
    long long ret = a;
    if (ret > b) ret = b;
    if (ret > c) ret = c;
    if (ret > d) ret = d;
    return ret;
}

long long step(long long n, long long x, long long y){
    if (y == 1) return x - 1;
    if (x == n) return n + y - 2;
    if (y == n) return n * 3 - x - 2;
    if (x == 1) return n * 4 - y - 3;
    long long k = min(x - 1, y - 1, n - x, n - y);
    return 4 * k * (n - k) + step(n - 2 * k, x - k, y - k);
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cout << setw(6) << step(n, j, i) + 1;
        }
        cout << endl;
    }
    return 0;
}
