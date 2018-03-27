/* 小F的地板 */
#include <iostream>
#include <cstring>
using namespace std;

unsigned long long f[10][1 << 9];
int m, n;

void dp(int lim, int col, int now, int last, int exNow, int exLast){
    if (exNow == 1 && exLast == 1){
        exNow = 0;
        exLast = 0;
        ++col;
    }
    if (col > n || (col == n && (exNow || exLast)))
        return;
    if (col == n && exNow == 0 && exLast == 0){
        f[lim][now] += f[lim - 1][last];
        return;
    }
    if (exNow == 0 && exLast == 0){
        dp(lim, col + 1, (now << 1) | 1, last << 1, 0, 0); //2 * 1
        dp(lim, col + 2, (now << 2) | 3, (last << 2) | 3, 0, 0); //1 * 2, exNow = 0
        dp(lim, col + 1, (now << 2) | 3, (last << 1) | 1, 1, 0); //1 * 2, exNow = 1
        dp(lim, col + 1, (now << 1) | 1, last << 2, 0, 1); //bottom right
        dp(lim, col + 2, (now << 2) | 2, last << 2, 0, 0); //bottom right
        dp(lim, col + 2, (now << 2) | 1, last << 2, 0, 0); //bottom left
        dp(lim, col + 1, (now << 2) | 3, last << 1, 1, 0); //top right
        dp(lim, col + 2, (now << 2) | 3, (last << 2) | 1, 0, 0); //top right
        dp(lim, col + 2, (now << 2) | 3, (last << 2) | 2, 0, 0); //top left
        //dp(lim, col, now << 1, last, 1, 0); //none, exNow = 1
        dp(lim, col + 1, now << 1, (last << 1) | 1, 0, 0); //none, exNow = 0
        //dp(lim, col, now, (last << 1) | 1, 0, 1); //none, exLast = 1
    }
    else if (exNow == 1 && exLast == 0){
        //dp(lim, col + 2, (now << 1) | 1, (last << 2) | 2, 0, 0); //2 * 1
        dp(lim, col + 2, (now << 1) | 1, last << 2, 0, 0); //bottom left
    }
    else{
        dp(lim, col + 1, (now << 2) | 3, last, 1, 0); //1 * 2
        dp(lim, col + 2, (now << 2) | 3, (last << 1) | 1, 0, 0); //1 * 2
        dp(lim, col + 2, (now << 2) | 3, last << 1, 0, 0); //top left
        //dp(lim, col + 2, (now << 2) | 1, last << 1, 0, 0); //2 * 1
    }
}

int main(){
    cin >> m >> n;
    if (m > n)
        m ^= n ^= m ^= n;
    memset(f, 0, sizeof(f));
    f[0][(1 << n) - 1] = 1;
    for (int i = 1; i <= m; ++i)
        dp(i, 0, 0, 0, 0, 0);
    cout << f[m][(1 << n) - 1] << endl;
    return 0;
}
