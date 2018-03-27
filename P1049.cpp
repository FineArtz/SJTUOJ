/* 火车调度 */
#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        int stack[1005], size = 0;
        int a[1005];
        bool flag = true;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        int i = 0, j = 1;
        while (i < n){
            if (a[j] > i){
                stack[++size] = i;
                if (size > m){
                    flag = false;
                    break;
                }
                ++i;
            }
            else if (a[j] == i){
                ++i;
                ++j;
            }
            else{
                if (size == 0 || stack[size] != a[j]){
                    flag = false;
                    break;
                }
                --size;
                ++j;
            }
        }
        if (flag){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}
