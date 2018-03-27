/* 二哥的约瑟夫 */
#include <iostream>
using namespace std;

int main(){
    int m, k[10005];
    cin >> m;
    for (int i = 1; i < m; ++i)
        cin >> k[i];
    int ans = 0;
    for (int i = 2; i <= m; ++i)
        ans = (ans + k[m - i + 1]) % i;
    cout << ++ans << endl;
    return 0;
}
