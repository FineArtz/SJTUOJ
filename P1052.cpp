/* 二哥学集合论 */
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool a[105][205];
    int N, M, n[105], t;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> n[i];
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= n[i]; ++j){
            cin >> t;
            a[i][t] = true;
        }
    }
    cin >> M;
    char ch;
    int x, y;
    while (M--){
        cin >> ch >> x >> y;
        switch(ch){
        case '+':
            for (int i = 0; i <= 200; ++i){
                if (a[y][i])
                    a[x][i] = true;
            }
            break;
        case '-':
            for (int i = 0; i <= 200; ++i){
                if (a[y][i])
                    a[x][i] = false;
            }
            break;
        case '*':
            for (int i = 0; i <= 200; ++i){
                if (!a[y][i])
                    a[x][i] = false;
            }
            break;
        }
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 0; j <= 200; ++j)
            if (a[i][j]) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
