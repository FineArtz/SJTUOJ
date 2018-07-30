/* 二哥切巧克力 */
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int T;
    cin >> T;
    while (T--){
        int c, r;
        char ch;
        int a[305][305], sum[305][305];
        int sumx[305][305], sumy[305][305];
        cin >> r >> c;
        for (int i = 0; i <= r; ++i){
            sum[i][0] = 0;
            sumx[i][0] = 0;
            sumy[i][0] = 0;
        }
        for (int j = 0; j <= c; ++j){
            sum[0][j] = 0;
            sumx[0][j] = 0;
            sumy[0][j] = 0;
        }
        for (int i = 1; i <= r; ++i){
            for (int j = 1; j <= c; ++j){
                cin >> ch;
                a[i][j] = ch - '0';
                sum[i][j] = a[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= r; ++i){
            for (int j = 1; j <= c; ++j){
                sumx[i][j] = sumx[i - 1][j] + i * (sum[i][j] - sum[i - 1][j]);
                sumy[i][j] = sumy[i][j - 1] + j * (sum[i][j] - sum[i][j - 1]);
            }
        }
        bool flag = false;
        for (int k = min(r, c); k >= 3; --k){
            for (int i = 1; i <= r - k + 1; ++i){
                for (int j = 1; j <= c - k + 1; ++j){
                    int x = i + k - 1, y = j + k - 1;
                    int s = sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1]
                            - a[i][j] - a[i][y] - a[x][j] - a[x][y];
                    double wx = sumx[x][y] - sumx[i - 1][y] - sumx[x][j - 1] + sumx[i - 1][j - 1]
                            - i * a[i][j] - i * a[i][y] - x * a[x][j] - x * a[x][y];
                    double wy = sumy[x][y] - sumy[i - 1][y] - sumy[x][j - 1] + sumy[i - 1][j - 1]
                            - j * a[i][j] - y * a[i][y] - j * a[x][j] - y * a[x][y];
                    if (s == 0){
                        flag = true;
                        cout << k << '\n';
                        break;
                    }
                    wx = wx / s;
                    wy = wy / s;
                    if (abs(2 * wx - i - x) < 1e-8 && abs(2 * wy - j - y) < 1e-8){
                        flag = true;
                        cout << k << '\n';
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (!flag) cout << "IMPOSSIBLE\n";
    }
    return 0;
}
