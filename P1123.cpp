/* 折线统计 Problem */
#include <iostream>
using namespace std;

const int MOD = 100007;

struct Point{
    int x = 0, y = 0;

    bool operator <(const Point &p) const{
        return x < p.x;
    }
};

int n, k, maxy;
Point a[50005];
long long f[50005][11][2] = {0}, t[100005][11][2] = {0};

int lowbit(int x){
    return (x & (-x));
}

void qsort(int l, int r){
    int i = l, j = r;
    Point key = a[i];
    while (i < j){
        while (i < j && key < a[j])
            --j;
        a[i] = a[j];
        while (i < j && a[i] < key)
            ++i;
        a[j] = a[i];
    }
    a[i] = key;
    if (l < i)
        qsort(l, i - 1);
    if (r > j)
        qsort(j + 1, r);
}

void add(int x, int j, int k, long long d){
    for (int i = x; i <= maxy; i += lowbit(i))
        t[i][j][k] = (t[i][j][k] + d) % MOD;
}

long long sum(int x, int j, int k){
    long long ret = 0;
    for (int i = x; i != 0; i -= lowbit(i))
        ret = (ret + t[i][j][k]) % MOD;
    return ret;
}

int main(){
    cin >> n >> k;
    maxy = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].x >> a[i].y;
        if (a[i].y > maxy)
            maxy = a[i].y;
    }
    qsort(1, n);
    for (int i = 1; i <= n; ++i){
        f[i][0][0] = 1;
        f[i][0][1] = 1;
        add(a[i].y, 0, 0, 1);
        add(a[i].y, 0, 1, 1);
        for (int j = 1; j <= k; ++j){
            f[i][j][0] += sum(a[i].y - 1, j, 0) + sum(a[i].y - 1, j - 1, 1);
            f[i][j][1] += sum(maxy, j, 1) - sum(a[i].y, j, 1) +
                          sum(maxy, j - 1, 0) - sum(a[i].y, j - 1, 0);
            f[i][j][0] = (f[i][j][0] % MOD + MOD) % MOD;
            f[i][j][1] = (f[i][j][1] % MOD + MOD) % MOD;
            add(a[i].y, j, 0, f[i][j][0]);
            add(a[i].y, j, 1, f[i][j][1]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = (ans + f[i][k][0] + f[i][k][1]) % MOD;
    cout << ans << endl;
    return 0;
}
