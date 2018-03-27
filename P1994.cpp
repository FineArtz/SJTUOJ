/* ¶þ¸çµÄµØÍ¼ */
#include <iostream>
#include <cstring>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int a[505][505];
int n, m;

bool check(int x, int y){
    if (x < 1 || x > n || y < 1 || y > m || a[x][y] != 0) return false;
    return true;
}

void floodfill(int x, int y, int cnt){
    a[x][y] = cnt;
    for (int i = 0; i != 4; ++i){
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if (check(nextx, nexty)){
            floodfill(nextx, nexty, cnt);
        }
    }
}

int main(){
    memset(a, 0, sizeof(a));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    int cnt = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == 0){
                ++cnt;
                floodfill(i, j, cnt);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
