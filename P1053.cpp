/* 二哥的内存 */
#include <iostream>
#include <algorithm>
using namespace std;

class Point{
public:
    Point(int xx = -1, int yy = -1, int d = 0) : x(xx), y(yy), data(d) {}
    bool operator <(const Point &p){
        return (x < p.x || (x == p.x && y < p.y));
    }

    int x = -1, y = -1, data = 0;
};

Point a[10005];
int mapx[100005], mapy[100005];
int n, m;

void qsort(int low, int high){
    int l = low, h = high;
    Point key = a[low];
    while (l < h){
        while (l < h && key < a[h]) --h;
        a[l] = a[h];
        while (l < h && a[l] < key) ++l;
        a[h] = a[l];
    }
    a[l] = key;
    if (low < l)
        qsort(low, l - 1);
    if (high > h)
        qsort(h + 1, high);
}

int find(int x, int y){
    Point t(x, y);
    auto it = lower_bound(a + 1, a + n + 1, t);
    if (it != a + n + 1 && it->x == x && it->y == y)
        return it->data;
    else
        return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < 100005; ++i){
        mapx[i] = i;
        mapy[i] = i;
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i].x >> a[i].y >> a[i].data;
    qsort(1, n);
    cin >> m;
    while (m--){
        int op, x, y, t;
        cin >> op >> x >> y;
        switch(op){
        case 0:
            t = mapx[x];
            mapx[x] = mapx[y];
            mapx[y] = t;
            break;
        case 1:
            t = mapy[x];
            mapy[x] = mapy[y];
            mapy[y] = t;
            break;
        case 2:
            cout << find(mapx[x], mapy[y]) << '\n';
            break;
        }
    }
    return 0;
}
