/* traverse */
#include <iostream>
using namespace std;

struct Node{
    int child = 0, sibling = 0;
    int val = 0;
};

Node a[100005];
bool b[100005] = {0};
int n;

void foretra(int x){
    if (x == 0)
        return;
    cout << a[x].val << ' ';
    int t = a[x].child;
    while (t){
        foretra(t);
        t = a[t].sibling;
    }
}

void backtra(int x){
    if (x == 0)
        return;
    int t = a[x].child;
    while (t){
        backtra(t);
        t = a[t].sibling;
    }
    cout << a[x].val << ' ';
}

void hieatra(int root){
    int q[100005];
    int front = 0, rear = 0;
    q[rear++] = root;
    while (front != rear){
        int now = q[front];
        front++;
        cout << a[now].val << ' ';
        int t = a[now].child;
        while (t){
            q[rear++] = t;
            t = a[t].sibling;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].child >> a[i].sibling >> a[i].val;
        b[a[i].child] = true;
        b[a[i].sibling] = true;
    }
    int root = 0;
    for (int i = 1; i <= n; ++i){
        if (!b[i]){
            root = i;
            break;
        }
    }
    foretra(root);
    cout << '\n';
    backtra(root);
    cout << '\n';
    hieatra(root);
    cout << '\n';
    return 0;
}
