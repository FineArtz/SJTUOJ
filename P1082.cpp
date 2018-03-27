/* 二哥的鹅塘 */
#include <iostream>
#include <set>
using namespace std;

const int INF = 2147483647;

class Node{
public:
    int w = 0;
    set<int> child;
};

Node a[100005];
int n, root = 0;
int f[100005][3] = {0};
bool b[100005] = {0};

void dp(int x){
    int t = INF;
    for (int i : a[x].child){
        dp(i);
        f[x][0] += min(min(f[i][0], f[i][1]), f[i][2]);
        f[x][1] += min(f[i][0], f[i][1]);
        f[x][2] += min(f[i][0], f[i][1]);
        t = min(t, f[i][0] - min(f[i][0], f[i][1]));
    }
    f[x][0] += a[x].w;
    f[x][1] += t;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int x, w, c;
        cin >> x >> w >> c;
        a[x].w = w;
        for (int i = 1; i <= c; ++i){
            int y;
            cin >> y;
            a[x].child.insert(y);
            b[y] = true;
        }
    }
    for (int i = 1; i <= n; ++i){
        if (!b[i]){
            root = i;
            break;
        }
    }
    dp(root);
    cout << min(f[root][0], f[root][1]) << endl;
    return 0;
}
