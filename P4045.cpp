/* 日天要读书 */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    vector<int> q(p.begin(), p.end());
    int l, r, x;
    while (m--){
        q = p;
        cin >> l >> r >> x;
        sort(q.begin() + l, q.begin() + r + 1);
        auto ite = find(q.begin(), q.end(), p[x]);
        if (distance(q.begin(), ite) == x) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
