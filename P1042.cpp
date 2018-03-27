/* 左儿子右兄弟 */
#include <iostream>
using namespace std;

class Node{
public:
    int child = 0, brother = 0;
};

Node a[12350];
bool v[12350] = {0};

void dlr(int x){
    cout << x << ' ';
    int i = a[x].child;
    while (i != 0){
        dlr(i);
        i = a[i].brother;
    }
}

void lrd(int x){
    int i = a[x].child;
    while (i != 0){
        lrd(i);
        i = a[i].brother;
    }
    cout << x << ' ';
}

void hie(int x){
    int q[12350], front = 0, rear = 0;
    q[rear++] = x;
    while (front != rear){
        int now = q[front++];
        cout << now << ' ';
        int i = a[now].child;
        while (i != 0){
            q[rear++] = i;
            i = a[i].brother;
        }
    }
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int x, cx, sx;
        cin >> x >> cx >> sx;
        a[x].child = cx;
        a[x].brother = sx;
        v[cx] = true;
        v[sx] = true;
    }
    int root = 0;
    for (int i = 1; i <= n; ++i){
        if (!v[i]){
            root = i;
            break;
        }
    }
    dlr(root);
    cout << endl;
    lrd(root);
    cout << endl;
    hie(root);
    cout << endl;
    return 0;
}
