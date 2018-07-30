/* 骆源的哈夫曼树 */
#include <iostream>
using namespace std;

template <class T>
class Heap{
private:
    T a[200005];
    int heapsize = 0;

    void swap(int x, int y){
        T t = a[x];
        a[x] = a[y];
        a[y] = t;
    }

    void siftup(int x){
        while (x != 1){
            if (a[x] < a[x >> 1]){
                swap(x, x >> 1);
                x >>= 1;
            }
            else
                break;
        }
    }

    void siftdown(){
        int i = 2;
        while (i <= heapsize){
            if (i + 1 <= heapsize && a[i + 1] < a[i])
                ++i;
            if (a[i] < a[i >> 1]){
                swap(i, i >> 1);
                i <<= 1;
            }
            else
                break;
        }
    }

public:
    void push(T x){
        a[++heapsize] = x;
        siftup(heapsize);
    }

    void pop(){
        swap(1, heapsize);
        --heapsize;
        siftdown();
    }

    T top(){
        return a[1];
    }

    bool empty(){
        return heapsize == 0;
    }

    int size(){
        return heapsize;
    }
};

int n, m;
Heap<long long> heap;
long long ans = 0;

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        long long t;
        cin >> t;
        heap.push(t);
    }
    long long t = n;
    while (t > m){
        t -= m;
        ++t;
    }
    if (t != 0)
        for (int i = t; i < m; ++i)
            heap.push(0);
    while (heap.size() != 1){
        long long k = 0;
        for (int i = 1; i <= m; ++i){
            k += heap.top();
            heap.pop();
        }
        ans += k;
        heap.push(k);
    }
    cout << ans << endl;
    return 0;
}
