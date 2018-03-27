/* 有序分数数列 */
#include <iostream>
using namespace std;

int a[10000] = {0}, b[10000] = {0};
double c[10000] = {0.0};

int gcd(int x, int y){
    if (x % y == 0) return y;
    return gcd(y, x % y);
}

inline void swap(int &x, int &y){ int t = x; x = y; y = t; }
inline void swap(double &x, double &y) { double t = x; x = y; y = t; }

void qsort(int low, int high){
    if (low >= high) return;
    int i = low, j = high, keya = a[i], keyb = b[i];
    double key = c[i];
    while (i < j){
        while (i < j && c[j] >= key) --j;
        a[i] = a[j];
        b[i] = b[j];
        c[i] = c[j];
        while (i < j && c[i] <= key) ++i;
        a[j] = a[i];
        b[j] = b[i];
        c[j] = c[i];
    }
    a[i] = keya;
    b[i] = keyb;
    c[i] = key;
    qsort(i + 1, high);
    qsort(low, j - 1);
}

int main(){
    int n, cnt = 0;
    cin >> n;
    a[0] = 0;
    b[0] = 1;
    //cout << gcd(3, 2) << endl;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < i; ++j){
            if (gcd(i, j) == 1){
                ++cnt;
                a[cnt] = j;
                b[cnt] = i;
                c[cnt] = double(j) / double(i);
            }
        }
    qsort(1, cnt);
    a[++cnt] = 1;
    b[cnt] = 1;
    c[cnt] = 1.0;
    for (int i = 0; i <= cnt; ++i){
        cout << a[i] << '/' << b[i] << endl;
    }
    return 0;
}
