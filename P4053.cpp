/* Prime Ring */
#include <iostream>
#include <cmath>
using namespace std;

bool canplace[17][17];
bool beplaced[17];
int a[20];
int n;

bool isp(int x){
    if (x == 2) return true;
    for (int i = 2; i <= trunc(sqrt(x)) + 1; ++i)
        if (x % i == 0) return false;
    return true;
}
bool check(int a[], int n){
    for (int i = 0; i <= n - 1; ++i)
        if (!isp(a[i] + a[i + 1])) return false;
    return true;
}

void dfs(int x){
    if (x == n + 1){
        for (int i = 1; i <= n; ++i)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 2 - x % 2; i <= n; i += 2){
        if (!beplaced[i] && canplace[i][a[x - 1]]){
            if (x == n && !canplace[i][1]) continue;
            beplaced[i] = true;
            a[x] = i;
            dfs(x + 1);
            a[x] = 0;
            beplaced[i] = false;
        }
    }
}
int main(){
    cin >> n;
    if (n % 2 != 0){
        cout << "None" << endl;
    }
    for (int i = 2; i <= n; ++i)
        for (int j = 1; j < i; ++j){
            if (isp(i + j)) canplace[i][j] = true;
            else canplace[i][j] = false;
            canplace[j][i] = canplace[i][j];
        }
    a[1] = 1;
    beplaced[1] = true;
    dfs(2);
    return 0;
}
