/* 绮礼的阴谋 */
#include <iostream>
#include <algorithm>
using namespace std;

class Interval{
public:
    //constructor
    Interval() : l(0), r(0) {}
    Interval(int x, int y) : l(x), r(y) {}
    Interval(const Interval &i) : l(i.l), r(i.r) {}

    int l, r;
};
inline bool cmp(Interval i1, Interval i2){
    return (i1.l < i2.l || i1.l == i2.l && i1.r > i2.r);
}

int main(){
    int n;
    cin >> n;
    Interval a[10005];
    for (int i = 0; i < n; ++i)
        cin >> a[i].l >> a[i].r;
    sort(a, a + n, cmp);
    /*for (int i = 0; i < n; ++i)
        cout << a[i].l << ' ' << a[i].r << endl;*/
    long long nowl = a[0].l, nowr = a[0].r;
    long long ans = 0;
    for (int i = 1; i < n; ++i){
        if (nowl <= a[i].l && a[i].l <= nowr){
            if (nowr < a[i].r) nowr = a[i].r;
        }
        else{
            ans += nowr - nowl;
            nowl = a[i].l;
            nowr = a[i].r;
        }
    }
    ans += nowr - nowl;
    cout << ans << endl;
    return 0;
}
