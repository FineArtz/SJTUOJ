/* 约瑟夫环 */
#include <iostream>
using namespace std;

class Node{
public:
    int index;
    Node *next;
};

int main(){
    int n, m;
    cin >> n >> m;
    Node *head, *p, *q;
    head = p = new Node;
    p->index = 0;
    for (int i = 2; i <= n; ++i){
        q = new Node;
        q->index = i - 1;
        p->next = q;
        p = q;
    }
    p->next = head;
    q = head->next;
    while (q->next != q){
        for (int i = 1; i < m; ++i){
            p = q;
            q = q->next;
        }
        cout << q->index + 1 << " ";
        p->next = q->next;
        delete q;
        q = p->next;
    }
    cout << q->index + 1 << endl;
    delete q;
    return 0;
}
