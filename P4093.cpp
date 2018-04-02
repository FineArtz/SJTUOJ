/* Candy */
#include <iostream>
using namespace std;

class Node{
public:
    int pack = 0, candy = 0;

    Node() = default;
    Node(int p, int c) : pack(p), candy(c) {}

    bool operator <(const Node &n){
        return candy < n.candy;
    }
};

class Heap{
public:
    Node a[200005];
    int heapsize = 0;

    void swap(int x, int y){
        Node t = a[x];
        a[x] = a[y];
        a[y] = t;
    }

    void siftup(int x){
        while (x > 1){
            if (a[x / 2] < a[x]){
                swap(x, x / 2);
                x /= 2;
            }
            else
                break;
        }
    }

    void siftdown(){
        int i = 2;
        while (i <= heapsize){
            if (i + 1 <= heapsize && a[i] < a[i + 1])
                ++i;
            if (a[i / 2] < a[i]){
                swap(i, i / 2);
                i *= 2;
            }
            else
                break;
        }
    }

    void insert(const Node &n){
        a[++heapsize] = n;
        siftup(heapsize);
    }

    void remove(){
        swap(1, heapsize);
        --heapsize;
        siftdown();
    }

    Node getMax(){
        return a[1];
    }
};

Heap heap;
int n, m;

int main(){
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        heap.insert(Node(x, y));
    }
    long long ans = 0;
    while (n != 0 && heap.heapsize != 0){
        Node t = heap.getMax();
        if (n < t.pack){
            ans += n * (long long)t.candy;
            break;
        }
        else{
            ans += (long long)t.pack * t.candy;
            n -= t.pack;
            heap.remove();
        }
    }
    cout << ans << endl;
    return 0;
}
