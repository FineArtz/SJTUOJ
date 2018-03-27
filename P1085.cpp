/* 绿色通道 */
#include <iostream>
#include <cstring>
using namespace std;

int f[201110], a[201110];
pair<int, int> q[201110];
int n, t;

bool check(int lim){
    memset(f, 0, sizeof(f));
    memset(q, 0, sizeof(q));
    int front = 0, rear = 0;
    q[rear++] = make_pair(0, 0);
    for (int i = 1; i <= n; ++i){
        while (front != rear && q[front].first < i - lim - 1)
            ++front;
        f[i] = q[front].second + a[i];
        while (front != rear && f[i] <= q[rear - 1].second)
            --rear;
        q[rear++] = make_pair(i, f[i]);
    }
    for (int i = n - lim; i <= n; ++i)
        if (f[i] <= t)
            return true;
    return false;
}

int main(){
    cin >> n >> t;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int l = 0, r = n, mid;
    while (l < r){
        mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
