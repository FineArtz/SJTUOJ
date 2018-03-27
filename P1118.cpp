/* Travel */
#include <iostream>
using namespace std;

int n, m;
int parent[10005], now[10005], nowat[10005], sum[10005], trl[10005], ex[10005];

int find(int x){
    if (parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void merge(int x, int y){
    int p = find(x), q = find(y);
    sum[q] += sum[p];
//    if (sum[p] > sum[q]){
//        int t = p;
//        p = q;
//        q = t;
//    }
    for (int i = 1; i <= n; ++i){
        int t = find(i);
        if (t == p || t == q)
            trl[i] += ex[t];
    }
    ex[p] = ex[q] = 0;
    parent[p] = q;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        parent[i] = i;
        now[i] = i;
        nowat[i] = i;
        sum[i] = 1;
        trl[i] = 0;
        ex[i] = 0;
    }
    while (m--){
        char ch;
        int x, y, p, q, a, b;
        cin >> ch;
        switch(ch){
        case 'T':
            cin >> x >> y;
            p = find(x); //the set contains x
            q = find(y); //the set contains y
            if (p != q){
                a = nowat[p]; //where p is
                b = nowat[q]; //where q is
                now[a] = -1;
                nowat[p] = b;
                ++ex[p];
                merge(y, x);
            }
            break;
        case 'Q':
            cin >> x;
            p = find(x);
            cout << nowat[p] << ' ' << sum[p] << ' ' << trl[x] + ex[p] << '\n';
            break;
        }
    }
    return 0;
}
