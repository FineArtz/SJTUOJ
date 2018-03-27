/* 静态查找表 */
#include <iostream>
using namespace std;

class Node{
public:
    Node *pred = nullptr, *succ = nullptr;
    int data = 0;
};

int main(){
    Node *head = new Node, *p = head;
    int n, m, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        Node *t = new Node;
        cin >> t->data;
        p->succ = t;
        t->pred = p;
        p = t;
    }
    cin >> m;
    while (m--){
        int x;
        cin >> x;
        p = head->succ;
        while (p){
            ++cnt;
            if (p->data == x)
                break;
            p = p->succ;
        }
        if (p){
            p->pred->succ = p->succ;
            if (p->succ)
                p->succ->pred = p->pred;
            p->pred = head;
            p->succ = head->succ;
            if (p->succ)
                p->succ->pred = p;
            head->succ = p;
        }
    }
    p = head;
    Node *q = head;
    while (p){
        q = p->succ;
        delete p;
        p = q;
    }
    cout << cnt << endl;
    return 0;
}
