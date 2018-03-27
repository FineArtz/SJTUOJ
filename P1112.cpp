/* 二哥发论文 */
#include <iostream>
using namespace std;

class Heap{
private:
    int a[1005] = {0};
    int b[1005] = {0};
    int heapsize = 0;

    void swap(int x, int y){
        int t = a[x];
        a[x] = a[y];
        a[y] = t;
        t = b[x];
        b[x] = b[y];
        b[y] = t;
    }

public:
    void siftup(int i){
        while (i != 1){
            if (a[i] > a[i / 2]){
                swap(i, i / 2);
                i /= 2;
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
            if (a[i] > a[i / 2]){
                swap(i, i / 2);
                i *= 2;
            }
            else
                break;
        }
    }

    void insert(int x, int y){
        a[++heapsize] = x;
        b[heapsize] = y;
        siftup(heapsize);
    }

    void remove(){
        swap(1, heapsize);
        --heapsize;
        siftdown();
    }

    int getMax(){
        return b[1];
    }

    bool empty(){
        return (heapsize == 0);
    }
};

Heap heap;
int n, k;
int a[1005], m[1005][1005];
bool v[1005] = {false};

int main(){
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= k; ++i){
        int t;
        cin >> t;
        heap.insert(a[t], t);
        v[t] = true;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> m[i][j];
        }
    }
    while (!heap.empty()){
        int x = heap.getMax();
        cout << x << endl;
        heap.remove();
        for (int i = 1; i <= n; ++i)
            if (m[x][i] && !v[i]){
                heap.insert(a[i], i);
                v[i] = true;
            }
    }
    return 0;
}
