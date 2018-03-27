/* ππ‘Ï¡‚–Œ */
#include <iostream>
using namespace std;

int main(){
    char ch;
    int n;
    cin >> ch >> n;
    for (int i = 1; i <= n / 2 + 1; ++i){
        for (int j = 1; j <= n; ++j){
            if ((j >= n / 2 - i + 2) && (j <= n / 2 + i)) cout << ch;
            else cout << ' ';
        }
        cout << endl;
    }
    for (int i = n / 2; i >= 1; --i){
        for (int j = 1; j <= n; ++j){
            if ((j >= n / 2 - i + 2) && (j <= n / 2 + i)) cout << ch;
            else cout << ' ';
        }
        cout << endl;
    }
    return 0;
}
