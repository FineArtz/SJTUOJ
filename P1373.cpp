/* 收集红旗比赛 */
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 2147483647;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Point{
public:
    Point() = default;
    Point(int xx, int yy) : x(xx), y(yy) {}

    bool operator ==(Point p){
        return (x == p.x && y == p.y);
    }
    int x = 0, y = 0, minh = INF;
};

int h[505][505];
bool v[505][505];
vector<Point> fl;
int m, n;
int ans = 0, cnt = 0;

bool check(Point p){
    if (p.x < 1 || p.x > m || p.y < 1 || p.y > n || v[p.x][p.y]) return false;
    return true;
}

bool bfs(Point s, int lim){
    memset(v, 0, sizeof(v));
    queue<Point> q;
    q.push(s);
    v[s.x][s.y] = true;
    while (!q.empty()){
        Point now = q.front();
        q.pop();
        for (int i = 0; i != 4; ++i){
            Point next(now.x + dx[i], now.y + dy[i]);
            if (check(next)){
                int dh = abs(h[now.x][now.y] - h[next.x][next.y]);
                if (dh > lim) continue;
                q.push(next);
                v[next.x][next.y] = true;
            }
        }
    }
    for (auto f : fl){
        if (!v[f.x][f.y]) return false;
    }
    return true;
}

int main(){
    memset(h, 0, sizeof(h));
    cin >> m >> n;
    int minn = INF, maxx = 0;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> h[i][j];
            minn = min(minn, h[i][j]);
            maxx = max(maxx, h[i][j]);
        }
    int flag;
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> flag;
            if (flag == 1){
                fl.emplace_back(i, j);
            }
        }
	Point s = *(fl.begin());
	fl.erase(fl.begin());
	s.minh = 0;
    int low = 0, high = maxx - minn, mid = (low + high) / 2;
    while (low < high){
    	mid = (low + high) / 2;
    	if (bfs(s, mid))
    		high = mid;
		else
			low = mid + 1;
	}
    cout << low << endl;
    return 0;
}
