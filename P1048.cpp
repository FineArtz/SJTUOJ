/* 二叉树遍历 */
#include <iostream>
using namespace std;

class Node{
public:
    int l = 0, r = 0;
};

Node a[1025];
bool b[1025] = {0};

void hie(int root){
    int q[1025] = {0}, front = 0, rear = 0;
    q[rear++] = root;
    while (front != rear){
        int now = q[front++];
        cout << now << endl;
        if (a[now].l != 0){
            q[rear++] = a[now].l;
        }
        if (a[now].r != 0){
            q[rear++] = a[now].r;
        }
    }
}

int main(){
    int n;
    cin >> n;
    n >>= 1;
    for (int i = 1; i <= n; ++i){
        int x, y, z;
        cin >> x >> y >> z;
        a[x].l = y;
        a[x].r = z;
        b[y] = true;
        b[z] = true;
    }
    int root = 0;
    for (int i = 1; i <= n * 2 + 1; ++i){
        if (!b[i]){
            root = i;
            break;
        }
    }
    hie(root);
    return 0;
}
