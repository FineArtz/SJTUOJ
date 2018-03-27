/* BJ_drunbier */
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Node{
public:
    vector<int> edge;
    int sub = 1;
};
class Edge{
public:
    int u = 0, v = 0, len = 0;
};

Node a[10005];
Edge e[10005];

int calcSub(int root){
    for (auto i : a[root].edge){
        a[root].sub += calcSub(i);
    }
    return a[root].sub;
}

int main(){
    int n, f, w, root, cnte = 0;
    cin >> n;
    if (n == 1){
        cout << "0.00" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i){
        cin >> f >> w;
        if (f == 0){
            root = i;
        }
        else{
            a[f].edge.push_back(i);
            ++cnte;
            e[cnte].u = f;
            e[cnte].v = i;
            e[cnte].len = w;
        }
    }
    calcSub(root);
    //for (int i = 1; i <= n; ++i)
    //    cout << i << ' ' << a[i].sub << endl;
    double ans = 0, tmp;
    for (int i = 1; i <= cnte; ++i){
        tmp = n - a[e[i].v].sub;
        tmp = tmp * a[e[i].v].sub;
        tmp = tmp * e[i].len;
        ans = ans + tmp;
    }
    ans = ans / n / (n - 1) * 2;
    cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
    return 0;
}
