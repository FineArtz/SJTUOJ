/* 王马小吉的谎言 */
#include <iostream>
#include <cmath>
using namespace std;

long long sqr3(long long x){
    long long l = 2, r = 1000000, mid;
    while (l <= r){
        mid = (l + r) / 2;
        if (mid * mid * mid == x) return mid;
        if (mid * mid * mid > x) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--){
        long long a, b;
        cin >> a >> b;
        if (a == 1 && b == 1){
            cout << "Yes" << '\n';
            continue;
        }
        long long t = a * b;
        long long sq = sqr3(t);
        if (sq == -1){
            cout << "No" << '\n';
            continue;
        }
        if (a % sq == 0 && b % sq == 0){
            cout << "Yes" << '\n';
        }
        else cout << "No" << '\n';
    }
    return 0;
}
