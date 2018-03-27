/* Count On Tree*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node{
public:
    int father = 0;
    vector<int> edge;
    long long w = 0, sumw = 0;
    int depth = 0;
    int inT = 0, outT = 0;
};
Node a[50005];
vector<int> dep[50105];

void makeTree(){
    queue<int> q;
    q.push(1);
    int now, next;
    while (!q.empty()){
        now = q.front();
        q.pop();
        for (int i : a[now].edge){
            if (i != a[now].father){
                a[i].father = now;
                if (a[i].edge.size() != 1)
                    q.push(i);
            }
        }
    }
}
/*void print(int root){
    if (root == 0) return;
    cout << root << ' ' << a[root].sumw << endl;
    print(a[root].lchild);
    print(a[root].rchild);
}*/
long long calcw(int root){
    a[root].sumw = a[root].w;
    for (auto i : a[root].edge){
        if (i != a[root].father){
            if (a[i].edge.size() != 1)
                a[root].sumw += calcw(i);
            else{
                a[i].sumw = a[i].w;
                a[root].sumw += a[i].w;
            }
        }
    }
    return a[root].sumw;
}
void calcDepth(int root, int d){
    if (root == 0) return;
    a[root].depth = d;
    dep[d].push_back(root);
    for (auto i : a[root].edge){
        if (i != a[root].father){
            calcDepth(i, d + 1);
        }
    }
}

int timeStamp = 1;
void makeStamp(int root){
    a[root].inT = timeStamp;
    for (auto i : a[root].edge){
        if (i != a[root].father){
            ++timeStamp;
            makeStamp(i);
        }
    }
    a[root].outT = timeStamp;
}

long long query(int root, int h){
    long long ret = 0;
    for (auto i : dep[a[root].depth + h]){
        if (a[i].inT >= a[root].inT && a[i].outT <= a[root].outT)
            ret += a[i].sumw;
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q, u, v;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i].w;
    for (int i = 1; i < n; ++i){
        cin >> u >> v;
        a[u].edge.push_back(v);
        a[v].edge.push_back(u);
    }
    makeTree();
    calcw(1);
    //print(1);
    calcDepth(1, 1);
    makeStamp(1);
    int x, k;
    for (int i = 1; i <= q; ++i){
        cin >> x >> k;
        cout << query(x, k) << '\n';
    }
    return 0;
}
