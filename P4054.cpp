/* Î±»ØÎÄÊý */
#include <iostream>
#include <cmath>
using namespace std;

inline int firstDigit(long long r){
    while (r >= 10) r /= 10;
    return r;
}

long long f(long long x){
	if (x < 10) return x + 1;
	return (9 + x / 10 + (int)(x % 10 >= firstDigit(x)));
}

int main(){
    long long l, r;
    cin >> l >> r;
    long long ans = f(r) - f(l - 1);
    cout << ans << endl;
    return 0;
}
