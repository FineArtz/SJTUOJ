/* 简单链表 */
#include <iostream>
#include <cmath>
using namespace std;

const int MAXS = 1000;

int n, m, maxs;

class Block{
public:
    Block *prev = nullptr, *next = nullptr;
    int data[MAXS];
    int len = 0;

    Block(Block *p = nullptr, Block *q = nullptr) : prev(p), next(q) {}

    void split(int pos){
        if (pos >= len || pos < 0)
            return;
        Block *b = new Block(this, next);
        if (next != nullptr)
            next->prev = b;
        next = b;
        b->len = len - pos;
        for (int i = 0; i < len - pos; ++i)
            b->data[i] = data[i + pos];
        len = pos;
    }

    bool merge(){
        Block *b = next;
        if (b == nullptr)
            return false;
        if (len + b->len > maxs)
            return false;
        next = b->next;
        if (next != nullptr)
            next->prev = this;
        for (int i = 0; i < b->len; ++i)
            data[len++] = b->data[i];
        delete b;
        return true;
    }

    void delNext(){
        Block *b = next;
        if (b == nullptr)
            return;
        next = b->next;
        if (next != nullptr)
            next->prev = this;
        delete b;
    }
};

ostream &operator <<(ostream &os, const Block &b){
    for (int i = 0; i < b.len; ++i)
        os << b.data[i] << ' ';
    return os;
}

Block *head = new Block();

void insert(int x, int y){
    Block *p = head->next;
    while (p && x > p->len){
        x -= p->len;
        p = p->next;
    }
    p->split(x);
    p->data[p->len++] = y;
}

void remove(int x){
    Block *p = head->next;
    while (p && x > p->len){
        x -= p->len;
        p = p->next;
    }
    p->split(x);
    --p->len;
}

void maintain(){
    Block *p = head->next;
    while (p){
        p->merge();
        p = p->next;
    }
}

int main(){
    cin >> n >> m;
    maxs = (int)(sqrt(n)) + 1;
    Block *p = head->next = new Block();
    for (int i = 1; i <= n; ++i){
        int t;
        cin >> t;
        p->data[p->len++] = t;
        if (p->len == maxs){
            p->next = new Block();
            p = p->next;
        }
    }
    while (m--){
        int op;
        cin >> op;
        if (op == 1){
            int x, y;
            cin >> x >> y;
            insert(x, y);
        }
        else{
            int x;
            cin >> x;
            remove(x);
        }
        maintain();
    }
    p = head->next;
    while (p){
        cout << *p;
        p = p->next;
    }
    cout << endl;
    return 0;
}
