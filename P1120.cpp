/* 二哥的嘲讽 */
#include <iostream>
using namespace std;

struct Node{
    int data = 0;
    int layer = 0;
    Node *next = nullptr;

    Node(int d = 0, int l = 0, Node *n = nullptr)
        : data(d), layer(l), next(n) {}
};

struct LinkStack{
    Node *head = new Node();
    int size = 0;

    void push(int d, int l){
        Node *p = new Node(d, l, head);
        head = p;
        ++size;
    }

    int top(){
        return head->data;
    }

    int topLayer(){
        return head->layer;
    }

    void pop(){
        Node *p = head;
        head = p->next;
        delete p;
    }

    void resetTop(int x){
        head->data = x;
    }

    void clear(){
        Node *p = head, *q;
        while (p){
            q = p;
            p = p->next;
            delete q;
        }
    }
};

LinkStack a[1005], b[200005];
int n, k, layer = 0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    while (k--){
        int op, x;
        cin >> op;
        switch (op){
        case -1:
            ++layer;
            break;
        case -2:
            while (b[layer].top() != 0){
                a[b[layer].top()].pop();
                b[layer].pop();
            }
            --layer;
            break;
        case 0:
            cin >> x;
            cout << a[x].top() << '\n';
            break;
        default:
            cin >> x;
            if (a[op].topLayer() == layer)
                a[op].resetTop(x);
            else{
                a[op].push(x, layer);
                b[layer].push(op, 0);
            }
            break;
        }
    }
    return 0;
}
