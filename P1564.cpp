/* 深度优先搜索问题 */
#include <iostream>
#include <cstring>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int a[6][6];
bool v[6][6];
int ans = 0;

bool check(int x, int y){
    if (x < 0 || x > 5 || y < 0 || y > 5 || v[x][y]) return false;
    else return true;
}

void dfs(int x, int y, int ex, int ey, int cost, int state){
    if (x == ex && y == ey){
        ans = min(ans, cost);
        return;
    }
    for (int k = 0; k < 4; ++k){
        int nextx = x + dx[k];
        int nexty = y + dy[k];
        if (check(nextx, nexty)){
            int newcost = a[nextx][nexty] * state;
            int newstate = newcost % 4 + 1;
            v[x][y] = true;
            dfs(nextx, nexty, ex, ey, cost + newcost, newstate);
            v[x][y] = false;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                cin >> a[i][j];
        memset(v, 0, sizeof(v));
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        v[sx][sy] = true;
        ans = 2147483647;
        dfs(sx, sy, ex, ey, 0, 1);
        cout << ans << endl;
    }
    return 0;
}
