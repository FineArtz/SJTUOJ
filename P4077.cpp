/* 玩数 */
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class num{
public:
    num() = default;
    num(int xx, int yy) : x(xx), y(yy) {}
    int x = 0, y = 0;

    bool operator >(const num &n){
        return ((x * log(2) + y * log(3) - n.x * log(2) - n.y * log(3)) > -1e-6);
    }

    friend inline ostream &operator <<(ostream &os, const num &n){
        os << n.x << " " << n.y;
        return os;
    }
};
inline num max(num n1, num n2){
    return num(max(n1.x, n2.x), max(n1.y, n2.y));
}
inline num min(num n1, num n2){
    return num(min(n1.x, n2.x), min(n1.y, n2.y));
}

num a[50005];
num premax[50005], premin[50005], sufmax[50005], sufmin[50005];
num ansmax[50005], ansmin[50005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].x >> a[i].y;
    }
    premax[1] = a[1];
    premin[1] = a[1];
    for (int i = 2; i <= n; ++i){
        premax[i] = max(premax[i - 1], a[i]);
        premin[i] = min(premin[i - 1], a[i]);
    }
    sufmax[n] = a[n];
    sufmin[n] = a[n];
    for (int i = n - 1; i >= 1; --i){
        sufmax[i] = max(sufmax[i + 1], a[i]);
        sufmin[i] = min(sufmin[i + 1], a[i]);
    }
    ansmax[1] = premax[n];
    ansmin[1] = premax[n];
    if (n >= 3){
        num nowmin, minn;
        nowmin = min(a[1], sufmax[2]);
        for (int i = 2; i <= n - 1; ++i){
            minn = max(premax[i - 1], sufmax[i + 1]);
            minn = min(minn, a[i]);
            if (nowmin > minn)
                nowmin = minn;
        }
        minn = min(premax[n - 1], a[n]);
        if (nowmin > minn)
            nowmin = minn;
        ansmin[2] = nowmin;
    }
    if (n > 3){
        ansmax[2] = premax[n];
    }
    for (int k = 3; k <= n - 2; ++k){
        ansmax[k] = premax[n];
        ansmin[k] = premin[n];
    }
    if (n > 3){
        ansmin[n - 1] = premin[n];
    }
    if (n >= 3){
        num nowmax, maxx;
        nowmax = max(a[1], sufmin[2]);
        for (int i = 2; i <= n - 1; ++i){
            maxx = min(premin[i - 1], sufmin[i + 1]);
            maxx = max(maxx, a[i]);
            if (maxx > nowmax)
                nowmax = maxx;
        }
        maxx = max(premin[n - 1], a[n]);
        if (maxx > nowmax)
            nowmax = maxx;
        ansmax[n - 1] = nowmax;
    }
    ansmax[n] = sufmin[1];
    ansmin[n] = sufmin[1];
    for (int i = 1; i <= n; ++i)
        cout << ansmax[i] << " " << ansmin[i] << '\n';
    return 0;
}
