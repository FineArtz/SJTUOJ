/* 排序 */
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[10005];

void qsort(int l, int h){
    int i = l, j = h;
    int m = a[(l + j) / 2];
    while (i < j){
        while (a[i] < m) ++i;
        while (a[j] > m) --j;
        if (i <= j){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            ++i;
            --j;
        }
    }
    if (i < h) qsort(i, h);
    if (j > l) qsort(l, j);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    qsort(1, n);
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
    cout << endl;
    return 0;
}
