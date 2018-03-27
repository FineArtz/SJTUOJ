/* 郁闷的二哥 */
#include <iostream>
using namespace std;

class Node{
public:
    Node *p = nullptr, *s[2] = {nullptr, nullptr};
    int key = 0, size = 1, num = 1;

    Node(int k) : key(k) { p = s[0] = s[1] = nullptr; size = 1; num = 1; }
    bool whichChild() { return p->s[1] == this; }
    Node *link(int w, Node *x){
        s[w] = x;
        if (x)
            x->p = this;
        return this;
    }
    void update(){
        size = num + (s[0] ? s[0]->size : 0) + (s[1] ? s[1]->size : 0);
    }
};

Node *root = nullptr;
int ans = 0;

void rotate(Node *p){
    Node *q = p->p->p;
    if (p->whichChild())
        p->link(0, p->p->link(1, p->s[0]));
    else
        p->link(1, p->p->link(0, p->s[1]));
    p->p->update();
    if (q)
        q->link(q->s[1] == p->p, p);
    else{
        p->p = nullptr;
        root = p;
    }
}

void splay(Node *p, Node *t = nullptr){
    while (p->p != t && p->p->p != t){
        if (p->whichChild() == p->p->whichChild()){
            rotate(p->p);
            rotate(p);
        }
        else{
            rotate(p);
            rotate(p);
        }
    }
    if (p->p != t)
        rotate(p);
    p->update();
}

Node *find(int x){
    Node *p = root;
    while (p && p->key != x)
        p = p->s[p->key < x];
    if (p)
        splay(p);
    return p;
}

void insert(int x){
    if (!root){
        root = new Node(x);
        return;
    }
    if (find(x)){
        ++root->num;
        root->update();
        return;
    }
    Node *p = root, *q;
    while (p){
        q = p;
        p = p->s[p->key < x];
    }
    p = new Node(x);
    q->link(q->key < x, p);
    splay(p);
}

Node *findk(int k){
    if (root->size < k)
        return nullptr;
    Node *p = root;
    while (!(((p->s[0] ? p->s[0]->size : 0) < k) && ((p->s[0] ? p->s[0]->size : 0) + p->num >= k))){
        if (!p->s[0]){
            k -= p->num;
            p = p->s[1];
        }
        else{
            if (p->s[0]->size >= k)
                p = p->s[0];
            else{
                k -= (p->s[0]->size + p->num);
                p = p->s[1];
            }
        }
    }
    if (p)
        splay(p);
    return p;
}

Node *prev(){
    Node *p = root->s[0];
    if (!p)
        return nullptr;
    while (p->s[1])
        p = p->s[1];
    splay(p);
    return p;
}

Node *succ(){
    Node *p = root->s[1];
    if (!p)
        return nullptr;
    while (p->s[0])
        p = p->s[0];
    splay(p);
    return p;
}

void del(int l, int r){
    if (!find(l)){
        insert(l);
        --ans;
    }
    Node *p = prev();
    if (!find(r)){
        insert(r);
        --ans;
    }
    Node *q = succ();
    if (!p && !q){
        ans += root->size;
        root = nullptr;
        return;
    }
    if (!p){
        if (root->s[0])
            ans += root->s[0]->size;
        root->s[0] = nullptr;
        root->update();
        return;
    }
    if (!q){
        splay(p, 0);
        if (root->s[1])
            ans += root->s[1]->size;
        root->s[1] = nullptr;
        root->update();
        return;
    }
    splay(p, q);
    if (p->s[1])
        ans += p->s[1]->size;
    p->s[1] = nullptr;
    p->update();
    q->update();
}

void dispose(Node *p){
    if (!p) return;
    dispose(p->s[0]);
    dispose(p->s[1]);
    delete p;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, delta = 0;
    cin >> n >> m;
    while (n--){
        char ch;
        int k;
        cin >> ch >> k;
        switch(ch){
        case 'I':
            if (k >= m) insert(k - delta);
            break;
        case 'A':
            delta += k;
            break;
        case 'S':
            delta -= k;
            del(-1000000, m - delta - 1);
            break;
        case 'F':
            if (!root || root->size < k)
                cout << "-1\n";
            else{
                findk(root->size + 1 - k);
                cout << root->key + delta << '\n';
            }
            break;
        }
    }
    dispose(root);
    cout << ans << '\n';
    return 0;
}
