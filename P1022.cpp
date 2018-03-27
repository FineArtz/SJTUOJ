/* Fib数列 */
#include <iostream>
using namespace std;

const int MOD = 2010;

class Mat{
public:
    //constructor
    Mat(const int &x, const int &y, const int &p, const int &q)
        : a11(x), a12(y), a21(p), a22(q) {}
    Mat() : Mat(0, 0, 0, 0) {};
    Mat(const Mat &m) : a11(m.a11), a12(m.a12), a21(m.a21), a22(m.a22) {};

    long long a11, a12, a21, a22;
};
Mat operator *(const Mat &lhs, const Mat &rhs){
    long long a11 = (lhs.a11 * rhs.a11 + lhs.a12 * rhs.a21) % MOD;
    long long a12 = (lhs.a11 * rhs.a12 + lhs.a12 * rhs.a22) % MOD;
    long long a21 = (lhs.a21 * rhs.a11 + lhs.a22 * rhs.a21) % MOD;
    long long a22 = (lhs.a21 * rhs.a12 + lhs.a22 * rhs.a22) % MOD;
    return Mat(a11, a12, a21, a22);
}

Mat QuickPow(Mat a, long long pow){
    Mat ret(1, 0, 0, 1);
    while (pow != 0){
        if (pow & 1) ret = ret * a;
        a = a * a;
        pow >>= 1;
    }
    return ret;
}

int main(){
    long long n;
    cin >> n;
    if (n == 1 || n == 2){
        cout << 1 << endl;
        return 0;
    }
    Mat f0(1, 0, 1, 0), f(1, 1, 1, 0);
    Mat ans = QuickPow(f, n - 2);
    cout << (ans.a11 + ans.a12) % MOD << endl;
    return 0;
}
