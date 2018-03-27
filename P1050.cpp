/* 二哥的优先队列 */
#include <iostream>
using namespace std;

class Node{
public:
    int data = 0, dist = -1;
    Node *l = nullptr, *r = nullptr;
};

Node* a[300005];
bool b[300005];
int n, m;

template<class T>
inline void swp(T &x, T &y){
    T t = x; x = y; y = t;
}

Node *merge(Node *x, Node *y){
    if (x == nullptr) return y;
    if (y == nullptr) return x;
    if (x->data > y->data)
        swp(x, y);
    x->r = merge(x->r, y);
    if (x->l == nullptr || x->l->dist < x->r->dist)
        swp(x->l, x->r);
    if (x->r == nullptr)
        x->dist = 0;
    else
        x->dist = x->r->dist + 1;
    return x;
}

void dispose(Node *x){
    if (x == nullptr)
        return;
    if (x->l != nullptr)
        dispose(x->l);
    if (x->r != nullptr)
        dispose(x->r);
    delete x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        Node *t = new Node;
        cin >> t->data;
        t->dist = 0;
        a[i] = t;
        b[i] = true;
    }
    while (m--){
        int imp, x, y;
        cin >> imp;
        switch (imp){
        case 0:
            cin >> x >> y;
            ++x; ++y;
            a[x] = merge(a[x], a[y]);
            b[y] = false;
            break;
        case 1:
            cin >> x;
            ++x;
            if (!b[x] || a[x] == nullptr) cout << "-1" << '\n';
            else{
                cout << a[x]->data << '\n';
                Node *t = a[x];
                a[x] = merge(a[x]->l, a[x]->r);
                delete t;
            }
            break;
        case 2:{
            cin >> x >> y;
            ++x;
            Node *t = new Node;
            t->data = y;
            t->dist = 0;
            a[x] = merge(a[x], t);
            break;
        }
        default:
            break;
        }
    }
    for (int i = 1; i <= n; ++i){
        if (b[i])
            dispose(a[i]);
    }
    return 0;
}
