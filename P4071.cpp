/* Fibonacci数列 */
#include <iostream>
using namespace std;

const long long MOD = 1000000007;

class matrix{
public:
    matrix(long long a, long long b, long long c, long long d)
    : a11(a), a12(b), a21(c), a22(d) {}
    matrix(const matrix &a) : a11(a.a11), a12(a.a12), a21(a.a21), a22(a.a22) {}
    long long a11, a12, a21, a22;
};
inline matrix operator *(const matrix &m1, const matrix &m2){
    matrix ret(0, 0, 0, 0);
    ret.a11 = (m1.a11 * m2.a11 % MOD + m1.a12 * m2.a21 % MOD) % MOD;
    ret.a12 = (m1.a11 * m2.a12 % MOD + m1.a12 * m2.a22 % MOD) % MOD;
    ret.a21 = (m1.a21 * m2.a11 % MOD + m1.a22 * m2.a21 % MOD) % MOD;
    ret.a22 = (m1.a21 * m2.a12 % MOD + m1.a22 * m2.a22 % MOD) % MOD;
    return ret;
}
matrix pow(matrix x, long long n){
    matrix ret(1, 0, 0, 1), t(x);
    while (n != 0){
        if (n & 1){
            ret = ret * t;
        }
        t = t * t;
        n >>= 1;
    }
    return ret;
}
int main(){
    long long n;
    cin >> n;
    matrix f(1, 1, 1, 0);
    f = pow(f, n + 1);
    cout << f.a21 << endl;
}
