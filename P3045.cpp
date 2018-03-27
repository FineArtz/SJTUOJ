/* 大鱼 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Fish{
public:
    //constructor
    Fish() : x(0), y(0), r(0) {};
    Fish(const Fish& f) : x(f.x), y(f.y), r(f.r) {};
    Fish(const int &xx, const int &yy, const int &rr) : x(xx), y(yy), r(rr) {};

    int x, y, r;
};
inline bool cmp(const Fish &f1, const Fish &f2){
	if (f1.y < f2.y) return true;
        if (f1.y == f2.y && f1.x < f2.x) return true;
        return false;
}

int unsafe[1005] = {0};
int ans = 0;
Fish fish[5005];

class Interval{
public:
    //constructor
    Interval() : l(0), r(0) {}
    Interval(int x, int y) : l(x), r(y) {}
    Interval(const Interval &i) : l(i.l), r(i.r) {}

    int l, r;
};
inline bool comp(Interval i1, Interval i2){
    return (i1.l < i2.l || i1.l == i2.l && i1.r > i2.r);
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i){
        cin >> fish[i].x >> fish[i].y >> fish[i].r;
    }
    sort(fish, fish + k, cmp);
    for (int i = 1; i <= n; ++i){
        Interval f[5005];
        int cnt = 0;
        for (int j = 0; j < k; ++j){
            if (abs(fish[j].x - i) > fish[j].r) continue;
            int dy = trunc(sqrt(fish[j].r * fish[j].r - (i - fish[j].x) * (i - fish[j].x)));
            f[cnt].l = max(1, fish[j].y - dy);
            f[cnt].r = min(m, fish[j].y + dy);
            ++cnt;
        }
        if (cnt == 0) continue;
        sort(f, f + cnt, comp);
        int nowl = f[0].l, nowr = f[0].r;
        for (int j = 1; j < cnt; ++j){
            if (nowl <= f[j].l && f[j].l <= nowr){
                if (nowr < f[j].r) nowr = f[j].r;
            }
            else{
                ans += nowr - nowl + 1;
                nowl = f[j].l;
                nowr = f[j].r;
            }
        }
        ans += nowr - nowl + 1;
    }
    cout << ans << endl;
    return 0;
}
