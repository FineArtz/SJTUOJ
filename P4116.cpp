/* 刀位分配 */
#include <iostream>
using namespace std;

int n, s;
int a[100005];

void qsort(int l, int r){
    int i = l, j = r;
    int mid = a[(i + j) / 2];
    while (i <= j){
        while (a[i] < mid)
            ++i;
        while (a[j] > mid)
            --j;
        if (i <= j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            ++i;
            --j;
        }
    }
    if (i < r)
        qsort(i, r);
    if (j > l)
        qsort(l, j);
}

bool check(int ans){
    int i = 1, j = 2, t = s - 1;
    while (j <= n){
        if (a[j] - a[i] >= ans){
            --t;
            i = j;
        }
        if (t == 0)
            return true;
        ++j;
    }
    return false;
}

int main(){
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    qsort(1, n);
    int l = 1, r = a[n] - a[1], mid;
    while (l < r){
        mid = (l + r) / 2 + (l + r) % 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
