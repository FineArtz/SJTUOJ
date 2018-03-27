/* This is a programme to test red-black tree */
#include <iostream>
#include <stdexcept>
using namespace std;

class RBTree{
public:
    enum Colour {RED, BLACK};
private:
    class Node{
    public:
        int key = 0;
        Colour colour = RED;
        Node *p = nullptr, *l = nullptr, *r = nullptr;

        Node() = default;
        Node(int k, Node *pp = nullptr, Node *ll = nullptr, Node *rr = nullptr) :
            key(k), p(pp), l(ll), r(rr) {}
    };

    Node *root = nullptr;

    void leftRotate(Node *p){
        if (p == nullptr)
            return;
        Node *r = p->r;
        p->r = r->l;
        if (r->l != nullptr)
            r->l->p = p;
        r->p = p->p;
        if (p->p == nullptr)
            root = r;
        else if (p->p->l == p)
            p->p->l = r;
        else
            p->p->r = r;
        r->l = p;
        p->p = r;
    }

    void rightRotate(Node *p){
        if (p == nullptr)
            return;
        Node *l = p->l;
        p->l = l->r;
        if (l->r != nullptr)
            l->r->p = p;
        l->p = p->p;
        if (p->p == nullptr)
            root = l;
        else if (p->p->r == p)
            p->p->r = l;
        else
            p->p->l = l;
        l->r = p;
        p->p = l;
    }

    void fixInsertion(Node *x){
        x->colour = RED;
        while (x != nullptr && x != root && x->p->colour == RED){
            if (x->p == x->p->p->l){
                Node *y = x->p->p->r;
                if (y != nullptr && y->colour == RED){
                    x->p->colour = BLACK;
                    y->colour = BLACK;
                    x->p->p->colour = RED;
                    x = x->p->p;
                }
                else{
                    if (x == x->p->r){
                        x = x->p;
                        leftRotate(x);
                    }
                    x->p->colour = BLACK;
                    x->p->p->colour = RED;
                    rightRotate(x->p->p);
                }
            }
            else{
                Node *y = x->p->p->l;
                if (y != nullptr && y->colour == RED){
                    x->p->colour = BLACK;
                    y->colour = BLACK;
                    x->p->p->colour = RED;
                    x = x->p->p;
                }
                else{
                    if (x == x->p->l){
                        x = x->p;
                        rightRotate(x);
                    }
                    x->p->colour = BLACK;
                    x->p->p->colour = RED;
                    leftRotate(x->p->p);
                }
            }
        }
        root->colour = BLACK;
    }

    void fixDeletion(Node *x){
        while (x != root && x->colour == BLACK){
            if (x == x->p->l){
                Node *sib = x->p->r;
                if (sib->colour == RED){
                    sib->colour = BLACK;
                    x->p->colour = RED;
                    leftRotate(x->p);
                    sib = x->p->r;
                }
                if ((sib->r == nullptr || sib->r->colour == BLACK)
                 && (sib->l == nullptr || sib->l->colour == BLACK)){
                    sib->colour = RED;
                    x = x->p;
                }
                else{
                    if (sib->r == nullptr || sib->r->colour == BLACK){
                        sib->l->colour = BLACK;
                        sib->colour = RED;
                        rightRotate(sib);
                        sib = x->p->r;
                    }
                    sib->colour = x->p->colour;
                    x->p->colour = BLACK;
                    sib->r->colour = BLACK;
                    leftRotate(x->p);
                    x = root;
                }
            }
            else{
                Node *sib = x->p->l;
                if (sib->colour == RED){
                    sib->colour = BLACK;
                    x->p->colour = RED;
                    rightRotate(x->p);
                    sib = x->p->l;
                }
                if ((sib->r == nullptr || sib->r->colour == BLACK)
                 && (sib->l == nullptr || sib->l->colour == BLACK)){
                    sib->colour = RED;
                    x = x->p;
                }
                else{
                    if (sib->l == nullptr || sib->l->colour == BLACK){
                        sib->r->colour = BLACK;
                        sib->colour = RED;
                        leftRotate(sib);
                        sib = x->p->l;
                    }
                    sib->colour = x->p->colour;
                    x->p->colour = BLACK;
                    sib->l->colour = BLACK;
                    rightRotate(x->p);
                    x = root;
                }
            }
        }
        x->colour = BLACK;
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

public:
    void insert(int x){
        Node *t = root;
        if (t == nullptr){
            root = new Node(x);
            root->colour = BLACK;
            return;
        }
        Node *p;
        int cmp = 0;
        do{
            p = t;
            if (x == t->key)
                return;
            else if (x > t->key){
                t = t->r;
                cmp = 1;
            }
            else{
                t = t->l;
                cmp = -1;
            }
        } while (t != nullptr);
        Node *e = new Node(x, p);
        if (cmp == -1)
            p->l = e;
        else
            p->r = e;
        fixInsertion(e);
    }

    Node *search(int x){
        Node *p = root;
        while (p != nullptr){
            if (x < p->key)
                p = p->l;
            else if (x > p->key)
                p = p->r;
            else
                return p;
        }
        return nullptr;
    }

    Node *succ(Node *t){
        if (t == nullptr)
            return nullptr;
        if (t->r != nullptr){
            Node *p = t->r;
            while (p->l != nullptr)
                p = p->l;
            return p;
        }
        else{
            Node *p = t->p, *ch = t;
            while (p != nullptr && ch == p->r){
                ch = p;
                p = p->p;
            }
            return p;
        }
    }

    void remove(int x){
        Node *p = search(x);
        if (p == nullptr)
            return;
        if (p->l != nullptr && p->r != nullptr){
            Node *s = succ(p);
            p->key = s->key;
            p = s;
        }
        Node *t = (p->l != nullptr ? p->l : p->r);
        if (t != nullptr){
            t->p = p->p;
            if (p->p == nullptr)
                root = t;
            else if (p == p->p->l)
                p->p->l = t;
            else
                p->p->r = t;
            p->l = p->r = p->p = nullptr;
            if (p->colour == BLACK)
                fixDeletion(t);
        }
        else if (p->p == nullptr)
            root = nullptr;
        else{
            if (p->colour == BLACK)
                fixDeletion(p);
            if (p->p != nullptr){
                if (p == p->p->l)
                    p->p->l = nullptr;
                else if (p == p->p->r)
                    p->p->r = nullptr;
                p->p = nullptr;
            }
        }
    }

    bool empty(){
        return (root == nullptr);
    }

    void clear(){
        dispose(root);
    }

    int getMax(){
        if (root == nullptr)
            throw runtime_error("");
        Node *p = root;
        while (p->r != nullptr)
            p = p->r;
        return p->key;
    }

    int getMin(){
        if (root == nullptr)
            throw runtime_error("");
        Node *p = root;
        while (p->l != nullptr)
            p = p->l;
        return p->key;
    }
};

RBTree rbtree;

int main(){
    for (int i = 0; i < 10; ++i){
        int t = rand();
        rbtree.insert(t);
        cout << t << ' ';
    }
    cout << endl;
    while (!rbtree.empty()){
        int t = rbtree.getMax();
        cout << t << ' ';
        rbtree.remove(t);
    }
    cout << endl;
    rbtree.clear();
    return 0;
}
