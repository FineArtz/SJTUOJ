/* 二哥去取钱 */
#include <iostream>
using namespace std;

int selectMin(int x, int y, int z){
    int r = 1, m = x;
    if (m > y){
        r = 2;
        m = y;
    }
    if (m > z){
        r = 0;
        m = z;
    }
    return r;
}

int main(){
    int n;
    int a[100005];
    cin >> n;
    long long w1 = 0, t1 = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int p[3] = {n / 3,
        n / 3 + (n % 3 != 0 ? 1 : 0),
        n / 3 + (n % 3 == 2 ? 1 : 0)};
    long long t[3] = {0, 0, 0};
    for (int i = 1; i <= n; ++i){
        w1 += a[i] * (--p[i % 3]);
        t[i % 3] += a[i];
    }
    t1 = max(t[0], max(t[1], t[2]));
    cout << w1 << ' ' << t1 << endl;
    long long w2 = 0, t2 = 0;
    if (n == 1){
        t2 = a[1];
    }
    else if (n == 2){
        t2 = max(a[1], a[2]);
    }
    else{
        int w[3] = {a[3], a[1], a[2]};
        for (int i = 4; i <= n; ++i){
            int j = selectMin(w[1], w[2], w[0]);
            for (int k = 0; k < 3; ++k)
                if (j != k)
                    w[k] -= w[j];
            w2 += (n - i + 1) * w[j];
            t2 += w[j];
            w[j] = a[i];
        }
        t2 += max(w[0], max(w[1], w[2]));
    }
    cout << w2 << ' ' << t2 << endl;
    return 0;
}
