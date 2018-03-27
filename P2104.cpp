/* ´óÁ³ÉÏ¿Î */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int D = 502;

bool v[1005][1005];

int lBound = 0, rBound = 1005, uBound = 1005, dBound = 0;

class Point{
public:
    Point() = default;
    Point(int xx, int yy) : x(xx), y(yy), step(0) {}
    int x = 0, y = 0, step = 0;
};

bool check(const Point &p){
    if (p.x < lBound || p.x > rBound || p.y < lBound || p.y > uBound || v[p.x][p.y]) return false;
    else return true;
}

int main(){
    memset(v, 0, sizeof(v));
	v[D][D] = true;
    int x, y, n;
    cin >> x >> y >> n;
    x += D;
    y += D;
    /*lBound = min(lBound, x - 1);
    rBound = max(rBound, x + 1);
    uBound = max(uBound, y + 1);
    dBound = min(dBound, y - 1);*/
    for (int i = 1; i <= n; ++i){
        int a, b;
        cin >> a >> b;
        a += D;
        b += D;
        v[a][b] = true;
        /*lBound = min(lBound, a - 1);
        rBound = max(rBound, a + 1);
        uBound = max(uBound, b + 1);
        dBound = min(dBound, b - 1);*/
    }
    queue<Point> q;
    Point s(D, D);
    q.push(s);
    while (!q.empty()){
        Point now = q.front(), next;
        q.pop();
        if (now.x == x && now.y == y){
            cout << now.step << endl;
            return 0;
        }
        for (int i = 0; i != 4; ++i){
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            next.step = now.step + 1;
            if (check(next)){
                q.push(next);
                v[next.x][next.y] = true;
            }
        }
    }
    return 0;
}
