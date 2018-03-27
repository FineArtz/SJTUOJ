/* 黄昏之时 */
#include <iostream>
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
    long long n, i, j;
    cin >> n >> i >> j;
    cout << step(n, n - i + 1, j) << ' ' << step(n, i, n - j + 1) << endl;
    return 0;
}
