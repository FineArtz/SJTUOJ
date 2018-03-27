/* 完全二叉树 */
#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    int lchild = -1, rchild = -1;
};

Node a[1000005];

bool check(int root){
    queue<int> q;
    q.push(root);
    int t = q.front();
    q.pop();
    while (t != -1){
        q.push(a[t].lchild);
        q.push(a[t].rchild);
        t = q.front();
        q.pop();
    }
    while (!q.empty()){
        t = q.front();
        q.pop();
        if (t != -1) return false;
    }
    return true;
}

int main(){
    int n, t;
    cin >> n;
    for (int i = 1; i < n; ++i){
        cin >> t;
        if (a[t].lchild == -1) a[t].lchild = i;
        else a[t].rchild = i;
    }
    if (check(0)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
