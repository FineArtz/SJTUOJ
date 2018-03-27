/* ¾ØÕóĞı×ª */
#include <iostream>
using namespace std;

int main(){
    int m, n;
    int a[15][15];
    cin >> m >> n;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; ++i){
        for (int j = m; j >= 1; --j)
            cout << a[j][i] << ' ';
        cout << endl;
    }
    return 0;
}
