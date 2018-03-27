/* 加分二叉树 */
#include <iostream>
#include <cstring>
using namespace std;

int n;
int a[35] = {0}, r[35][35] = {0};
int f[35][35] = {0};

int calc(int l, int h){
    if (l > h)
        return 1;
    if (f[l][h] >= 0)
        return f[l][h];
    if (l == h){
        r[l][h] = l;
        f[l][h] = a[l];
        return f[l][h];
    }
    for (int k = l; k <= h; ++k){
        int p = calc(l, k - 1), q = calc(k + 1, h);
        if (f[l][h] < p * q + a[k]){
            f[l][h] = p * q + a[k];
            r[l][h] = k;
        }
    }
    return f[l][h];
}

void ldr(int l, int h){
    if (l > h)
        return;
    cout << r[l][h] << ' ';
    ldr(l, r[l][h] - 1);
    ldr(r[l][h] + 1, h);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    memset(f, -1, sizeof(f));
    memset(r, -1, sizeof(r));
    calc(1, n);
    cout << f[1][n] << endl;
    ldr(1, n);
    cout << endl;
    return 0;
}
