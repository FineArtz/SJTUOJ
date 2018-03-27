/* 顺序存储二叉树 */
#include <iostream>
using namespace std;

class Node{
public:
    int l = 0, r = 0, pos = 0, ind = 0;
};

Node a[100005];
int n, root = 0, b[100005], c[100005];

void encode(int root){
    int q[200005], front = 0, rear = 0, cnt = 0, r = 0;
    q[rear++]= root;
    r = rear;
    a[root].pos = ++cnt;
    while (front != r){
        int now = q[front++];
        ++cnt;
        if (now != -1){
            if (a[now].l != -1){
                q[rear++] = b[a[now].l];
                a[b[a[now].l]].pos = cnt;
                r = rear;
            }
            else
                q[rear++] = -1;
        }
        else{
            q[rear++] = -1;
        }
        ++cnt;
        if (now != -1){
            if (a[now].r != -1){
                q[rear++] = b[a[now].r];
                a[b[a[now].r]].pos = cnt;
                r = rear;
            }
            else
                q[rear++] = -1;
        }
        else{
            q[rear++] = -1;
        }
    }
    for (int i = 1; i <= n; ++i){
        c[a[i].ind] = a[i].pos;
    }
    for (int i = 1; i <= n; ++i)
        cout << c[i] << ' ';
    cout << endl;
}

void sufTrans(int x){
    if (a[x].l != -1)
        sufTrans(b[a[x].l]);
    if (a[x].r != -1)
        sufTrans(b[a[x].r]);
    cout << a[x].ind << ' ';
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].ind >> a[i].l >> a[i].r;
        if (a[i].ind == 1)
            root = i;
    }
    for (int i = 1; i <= n; ++i){
        b[a[i].ind] = i;
    }
    encode(root);
    sufTrans(root);
    cout << endl;
    return 0;
}
