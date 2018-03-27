/* 泰先生的时光机 */
#include <iostream>
using namespace std;

int n, m;
int a[500005] = {0};

long long check(long long l, long long r){
    if (l >= r) return l;
    long long mid = (l + r) / 2;
    int cnt = 0;
    bool flag = true;
    for (int i = 1; i <= n; ++i){
        cnt += a[i] / mid;
        if (a[i] % mid != 0) ++cnt;
        if (cnt > m) {
            return check(mid + 1, r);
            flag = false;
            break;
        }
    }
    if (flag) return check(l, mid);
}

int main(){
    cin >> n >> m;
    long long sum = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
    long long l = sum / m, r = sum;
    cout << check(l, r) << endl;
    return 0;
}
