/* P1108 LCA method */
#include <iostream>
#include <map>
using namespace std;

class Node{
public:
    map<int, int> edge;
    int inT = 0, outT = 0;
    int len = 0;
    int father = 0;
};

Node a[10000];
int n;
int Tstamp = 0;

void makeTree(int x){
    a[x].inT = Tstamp;
    for (pair<int, int> i : a[x].edge){
        if (i.first != a[x].father){
            a[i.first].len = a[x].len + i.second;
            a[i.first].father = x;
            ++Tstamp;
            makeTree(i.first);
        }
    }
    a[x].outT = Tstamp;
}

int query(int u, int v){
    int x = 1;
    bool flag = true;
    while (flag){
        flag = false;
        for (pair<int, int> i : a[x].edge){
            if (i.first != a[x].father){
                if (a[i.first].inT <= a[u].inT && a[i.first].inT <= a[v].inT
                && a[i.first].outT >= a[u].outT && a[i.first].outT >= a[v].outT){
                    x = i.first;
                    flag = true;
                    break;
                }
            }
        }
    }
    return (a[u].len + a[v].len - 2 * a[x].len);
}

int main(){
    cin >> n;
    for (int i = 1; i <= n - 1; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].edge[v] = w;
        a[v].edge[u] = w;
    }
    makeTree(1);
    int q;
    cin >> q;
    while (q--){
        int u, v;
        cin >> u >> v;
        cout << query(u, v) << endl;
    }
    return 0;
}
