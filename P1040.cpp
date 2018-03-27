/* 二叉树层次遍历 */
#include <iostream>
using namespace std;

class Node{
public:
    int l = -1, r = -1;
};

Node a[1000005];
int q[1000005] = {0};

void traverse(int root){
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front != rear){
        int now = q[front++];
        cout << now << ' ';
        if (a[now].l != -1)
            q[rear++] = a[now].l;
        if (a[now].r != -1)
            q[rear++] = a[now].r;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i){
        int f;
        cin >> f;
        if (a[f].l == -1)
            a[f].l = i;
        else
            a[f].r = i;
    }
    traverse(0);
    return 0;
}
