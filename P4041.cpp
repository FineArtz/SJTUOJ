/* STL-vector */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    //cin >> n >> m;
    vector<vector<int>> v;
    int last3 = -1;
    v.resize(n);
    while (m--){
        int t, i, x;
        scanf("%d", &t);
        switch(t){
            case 1:
                scanf("%d%d", &i, &x);
                //cin >> i >> x;
                if (last3 == -1) v[i].push_back(x);
                else v[i].push_back(x ^ last3);
                break;
            case 2:
                scanf("%d", &i);
                //cin >> i;
                v[i].erase(v[i].end() - 1);
                break;
            case 3:
                scanf("%d%d", &i, &x);
                //cin >> i >> x;
                last3 = v[i][x];
                printf("%d\n", v[i][x]);
                //cout << v[i][x] << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
