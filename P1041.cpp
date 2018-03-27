/* 二哥打飞机 */
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class cmp{
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2){
        return (p1.second < p2.second || (p1.second == p2.second && p1.first < p2.first));
    }
};

class Plane{
public:
    bool operator <(const Plane &p){
        return (h < p.h || (h == p.h && ind < p.ind));
    }

    int h = 0, ind = 0;
};

int n;
Plane a[100005];
int pos[100005];

void siftup(int x){
    while (x > 1){
        if (a[x] < a[x / 2]){
            a[0] = a[x / 2];
            a[x / 2] = a[x];
            a[x] = a[0];
            pos[a[x].ind] = x;
            pos[a[x / 2].ind] = x / 2;
            x /= 2;
        }
        else
            break;
    }
}

void makeheap(){
    for (int i = n / 2 + 1; i <= n; ++i)
        siftup(i);
}

int dfs(int x, int i){
    if (a[i].h > x)
        return i;
    int r1 = 0, r2 = 0;
    if (i * 2 <= n){
        r1 = dfs(x, i * 2);
    }
    if (i * 2 + 1 <= n){
        r2 = dfs(x, i * 2 + 1);
    }
    if (r1 == 0)
        return r2;
    else if (r2 == 0)
        return r1;
    else
        return (a[r1] < a[r2] ? r1 : r2);
}

void findmin(int x){
    int r = dfs(x, 1);
    cout << a[r].ind << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<pair<int, int>, cmp> s;
    cin >> n;
if (n <= 70000){
    for (int i = 1; i <= n; ++i){
        int h;
        cin >> h;
        s.insert(make_pair(i, h));
    }
    char ss[10];
    while (cin >> ss){
        if (ss[0] == 'd'){
            int x, d;
            cin >> x >> d;
            auto it = find_if(s.begin(), s.end(), [x](pair<int, int> p){return p.first == x;});
            auto t = *it;
            t.second -= d;
            s.erase(it);
            s.insert(t);
        }
        else if (ss[0] == 'f'){
            int x;
            cin >> x;
            auto it = find_if(s.begin(), s.end(), [x](pair<int, int> p){return p.second > x;});
            cout << it->first << '\n';
        }
    }
}
else{
    for (int i = 1; i <= n; ++i){
        cin >> a[i].h;
        a[i].ind = i;
        pos[i] = i;
    }
    makeheap();
    char s[10];
    while (cin >> s){
        if (s[0] == 'd'){
            int x, d;
            cin >> x >> d;
            a[pos[x]].h -= d;
            siftup(pos[x]);
        }
        else if (s[0] == 'f'){
            int x;
            cin >> x;
            findmin(x);
        }
    }
}
    return 0;
}
