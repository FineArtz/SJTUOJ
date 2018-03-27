/* 二哥在黄山 */
#include <iostream>
#include <queue>
using namespace std;

class Point{
public:
    Point() = default;
    Point(int xx, int yy) : x(xx), y(yy) {}
    int x = 0, y = 0;
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, a[105][105];

bool check(int low, int high){
    if (a[1][1] < low || a[1][1] > high || a[n][n] < low || a[n][n] > high)
        return false;
    bool v[105][105] = {0};
    queue<Point> q;
    Point now(1, 1), next;
    q.push(now);
    v[1][1] = true;
    while (!q.empty()){
        now = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k){
            next.x = now.x + dx[k];
            next.y = now.y + dy[k];
            if (next.x < 1 || next.x > n || next.y < 1 || next.y > n || v[next.x][next.y])
                continue;
            if (a[next.x][next.y] < low || a[next.x][next.y] > high)
                continue;
            if (next.x == n && next.y == n)
                return true;
            q.push(next);
            v[next.x][next.y] = true;
        }
    }
    return false;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    int r = 110, l = 0;
    while (l < r){
        int mid = (l + r) / 2;
        bool flag = false;
        for (int i = 0; i <= 110 - mid; ++i)
            if (check(i, i + mid)){
                flag = true;
                break;
            }
        if (flag)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
    return 0;
}
