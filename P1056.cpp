/* 二哥吃糖 */
#include <iostream>
using namespace std;

class Node{
public:
    int size = 1, ind = 0;
};

bool b[500005];
Node a[500005];
int p[500005], pos[500005];
int n, m, Size = 0;

int getParent(int x){
    if (p[x] != x)
        p[x] = getParent(p[x]);
    return p[x];
}

void siftdown(int i){
    int x = i, mx = a[i].size;
    if (i * 2 <= Size){
        if (a[i * 2].size > mx){
            x = i * 2;
            mx = a[i * 2].size;
        }
    }
    if (i * 2 + 1 <= Size){
        if (a[i * 2 + 1].size > mx){
            x = i * 2 + 1;
            mx = a[i * 2 + 1].size;
        }
    }
    if (x != i){
        a[0] = a[x];
        a[x] = a[i];
        a[i] = a[0];
        pos[a[i].ind] = i;
        pos[a[x].ind] = x;
        siftdown(x);
    }
}

void siftup(int i){
    while (i >= 2){
        if (a[i].size <= a[i / 2].size)
            break;
        a[0] = a[i];
        a[i] = a[i / 2];
        a[i / 2] = a[0];
        pos[a[i].ind] = i;
        pos[a[i / 2].ind] = i / 2;
        i /= 2;
    }
}

void del(int i){
    a[i] = a[Size--];
    siftdown(i);
}

int findk(int k){
    int tmp = Size;
    for (int i = 1; i <= k - 1; ++i){
        a[0] = a[1];
        a[1] = a[Size];
        a[Size] = a[0];
        pos[a[1].ind] = 1;
        pos[a[Size].ind] = Size;
        --Size;
        siftdown(1);
    }
    int ret = a[1].size;
    while (Size < tmp){
        ++Size;
        siftup(Size);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        a[i].ind = i;
        p[i] = i;
        pos[i] = i;
        b[i] = true;
    }
    Size = n;
    while (m--){
        char ch;
        int x, y;
        cin >> ch;
        switch(ch){
        case 'C':{
            cin >> x >> y;
            int px = getParent(x), py = getParent(y);
            if (!b[px] || !b[py] || px == py) break;
            p[px] = py;
            a[pos[py]].size += a[pos[px]].size;
            del(pos[px]);
            siftup(pos[py]);
            break;
        }
        case 'D':{
            cin >> x;
            int px = getParent(x);
            if (!b[px]) break;
            del(pos[px]);
            b[px] = false;
            break;
        }
        case 'Q':{
            cin >> x;
            if (Size < x)
                cout << "0\n";
            else
                cout << findk(x) << '\n';
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
