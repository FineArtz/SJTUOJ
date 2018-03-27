/* 四通八达 */
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

class edge{
public:
    edge(int xx, int yy) : x(xx), y(yy) {}
    int x = 0, y = 0;
};

int parent[1000005];
int v[1000005] = {0};
vector<edge> e;
map<int, set<int>> ee;
int n, m, cnt = 0;
long long ans;

int find(int x){
    while (parent[x] != x){
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >>y;
        if (x == y) continue;
        if (ee.find(x) != ee.end()){
            if (ee[x].find(y) != ee[x].end())
                continue;
        }
        ++cnt;
        e.emplace_back(x, y);
        ee[x].insert(y);
        ee[y].insert(x);
    }
    for (int i = 0; i <= n; ++i)
        parent[i] = i;
    for (auto i : e){
        int p = find(i.x);
        int q = find(i.y);
        if (p != q)
            parent[p] = q;
    }
    for (int i = 0; i <= n; ++i)
        parent[i] = find(i);
    for (int i = 0; i <= n; ++i)
        ++v[parent[i]];
    for (int i = 0; i <= n; ++i){
        if (v[i] != 0){
            ans += v[i] * (v[i] - 1) / 2;
        }
    }
    cout << ans - cnt << endl;
    return 0;
}
