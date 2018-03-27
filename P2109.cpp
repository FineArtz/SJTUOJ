/* 二次方程 */
#include <iostream>
#include <cmath>
using namespace std;

int a[100005] = {0};

int search(int low, int high, double dt){
    int l = low, h = high, m = (l + h) / 2;
    while (h > l){
        m = (l + h) / 2;
        if (abs(a[m] - dt) < 10e-6) return m + 1;
        if (a[m] < dt)
            l = m + 1;
        else
            h = m - 1;
    }
    return l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> k;
    for (int i = 1; i <= k; ++i){
        int b, c, cnt = 0;
        cin >> b >> c;
        if (c == 0) cnt = n;
        else{
            double dt = b * b * 1.0 / 4 / c;
            if (a[1] > dt) cnt = 0;
            else cnt = search(1, n, dt);
        }
        cout << cnt << endl;
    }
    return 0;
}
