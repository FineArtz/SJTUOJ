/* 足球游戏 */
#include <iostream>
#include <cstring>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

pair<int, int> q[205], tmp;
int f[205][205];
bool a[205][205];
int n, m, k, x, y, ans = 0;

void dp(int x, int y, int l, int d) {
    int front = 0, rear = 0;
    int i = 0;
    while (x >= 1 && x <= n && y >= 1 && y <= m){
        if (!a[x][y]){
            front = 0;
            rear = 0;
        }
        else{
            tmp = make_pair(f[x][y], i);
            while (front < rear && q[rear - 1].first + i - q[rear - 1].second <= tmp.first)
                --rear;
            q[rear++] = tmp;
            while (front < rear && i - q[front].second > l)
                ++front;
            f[x][y] = q[front].first + i - q[front].second;
            ans = max(ans, f[x][y]);
        }
        ++i;
        x += dx[d];
        y += dy[d];
    }
}

int main(){
    cin >> n >> m >> x >> y >> k;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            char ch;
            cin >> ch;
            if (ch == '.')
                a[i][j] = true;
            else
                a[i][j] = false;
        }
    }
    memset(f, 0x80, sizeof(f));
    f[x][y] = 0;
    while (k--){
        int s, e, d, l;
        cin >> s >> e >> d;
        l = e - s + 1;
        if (d == 1)
            for (int j = 1; j <= m; ++j)
                dp(n, j, l, 0);
        else if (d == 2)
            for (int j = 1; j <= m; ++j)
                dp(1, j, l, 1);
        else if (d == 3)
            for (int i = 1; i <= n; ++i)
                dp(i, m, l, 2);
        else
            for (int i = 1; i <= n; ++i)
                dp(i, 1, l, 3);
    }
    cout << ans << endl;;
    return 0;
}
