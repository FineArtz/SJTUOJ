/* 泷的旅途 */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

class Point{
public:
    int x = 0, y = 0, step = 0, hp = 0;
};

int a[310][310];
int v[310][310];
int n, m;
Point st, ed;

inline bool check(const Point &p){
    return (a[p.x][p.y] != 0 && p.hp > v[p.x][p.y]);
}

int bfs(Point s, Point e){
    queue<Point> q;
    q.push(s);
    v[s.x][s.y] = s.hp;
    Point now;
    while (!q.empty()){
        now = q.front();
        q.pop();
        if (a[now.x][now.y] == 4) now.hp = 6;
        if (now.x == e.x && now.y == e.y) return now.step;
        for (int i = 0; i < 4; ++i){
            Point next;
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            next.hp = now.hp - 1;
            next.step = now.step + 1;
            if (check(next)){
                v[next.x][next.y] = next.hp;
                q.push(next);
            }
        }
    }
    return -1;
}

int main(){
    memset(a, 0, sizeof(a));
    memset(v, 0, sizeof(v));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            switch(a[i][j]){
                case 0:
                    v[i][j] = 10;
                    break;
                case 2:
                    st.x = i;
                    st.y = j;
                    break;
                case 3:
                    ed.x = i;
                    ed.y = j;
                    break;
                default:
                    break;
            }
        }
    }
    st.hp = 6;
    cout << bfs(st, ed) << endl;;
    return 0;
}
