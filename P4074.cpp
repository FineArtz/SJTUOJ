/* 洪水来袭 */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class Point{
public:
    int x = 0, y = 0;
};

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int m, n;
int a[105][105];
bool b[105][105];
bool v[105][105];
long long ans = 0;

bool check(const int &x, const int &y){
    return (x >= 0 && y >= 0 && x <= m + 1 && y <= n + 1);
}

void ff(int x, int y){
    Point st;
    st.x = x;
    st.y = y;
    queue<Point> q;
    q.push(st);
    Point now, next;
    while (!q.empty()){
        now = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k){
            next.x = now.x + dx[k];
            next.y = now.y + dy[k];
            if (check(next.x, next.y)){
                if (!b[next.x][next.y] && a[now.x][now.y] <= a[next.x][next.y]){
                    b[next.x][next.y] = true;
                    q.push(next);
                }
            }
        }
    }
}

bool checkw(int x, int y){
    Point st;
    st.x = x;
    st.y = y;
    bool vis[105][105];
    memset(vis, 0, sizeof(vis));
    queue<Point> q;
    q.push(st);
    v[st.x][st.y] = true;
    Point now, next;
    while (!q.empty()){
        now = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k){
            next.x = now.x + dx[k];
            next.y = now.y + dy[k];
            if (check(next.x, next.y) && !vis[next.x][next.y]){
                if (a[next.x][next.y] < a[now.x][now.y]) return false;
                if (a[next.x][next.y] == a[now.x][now.y]){
                    if (b[next.x][next.y]) return false;
                    vis[next.x][next.y] = true;
                    q.push(next);
                }
            }
        }
    }
    return true;
}
bool fill(){
	for (int i = 2; i <= m - 1; ++i)
		for (int j = 2; j <= n - 1; ++j)
			if (!b[i][j]) return false;
	return true;
}

int main(){
    cin >> m >> n;
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    memset(b, 0, sizeof(b));
	ff(0, 0);
    for (int water = 1; water <= 10000; ++water){
        for (int i = 2; i <= m - 1; ++i)
            for (int j = 2; j <= n - 1; ++j)
                if (!b[i][j] && water > a[i][j]){
                    ++ans;
                    ++a[i][j];
                    for (int k = 0; k < 4; ++k){
						int xx = i + dx[k];
						int yy = j + dy[k];
						if (a[xx][yy] <= a[i][j] && b[xx][yy]){
							ff(xx, yy);
							break;
						}
					}
                }
		if (fill()) break;
    }
    cout << ans << endl;
    return 0;
}
