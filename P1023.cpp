/* 矩阵反转 */
#include <iostream>
using namespace std;

int mat[605][605] = {0};

void trans(const int &n, const int &k){
    switch(k){
        case 0:
            for (int i = 1; i <= n; ++i){
                for (int j = n; j >= 1; --j)
                    cout << mat[i][j] << ' ';
                cout << "\n";
            }
            break;
        case 1:
            for (int i = n; i >= 1; --i){
                for (int j = 1; j <= n; ++j)
                    cout << mat[i][j] << ' ';
                cout << "\n";
            }
            break;
        case 2:
            for (int j = 1; j <= n; ++j){
                for (int i = 1; i <= n; ++i)
                    cout << mat[i][j] << ' ';
                cout << "\n";
            }
            break;
        default:
            break;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--){
        int a, b;
        cin >> a >> b;
        for (int i = 1; i <= a; ++i)
            for (int j = 1; j <= a; ++j)
                cin >> mat[i][j];
        trans(a, b);
    }
    return 0;
}
