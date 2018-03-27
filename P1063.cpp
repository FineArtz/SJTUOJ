/* 小M爱滑雪 */
#include <iostream>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int a[505][505], f[505][505] = {0};
int r, c;

int search(int x, int y){
    if (f[x][y] != 0)
        return f[x][y];
    int t[4] = {0};
    for (int i = 0; i < 4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && ny >= 1 && nx <= r && ny <= c)
            if (a[x][y] > a[nx][ny])
                t[i] = 1 + search(nx, ny);
    }
    int ret = 1;
    for (int i = 0; i < 4; ++i)
        if (ret < t[i])
            ret = t[i];
    f[x][y] = ret;
    return ret;
}

int main(){
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            ans = max(ans, search(i, j));
    cout << ans << endl;
    return 0;
}
