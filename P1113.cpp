/* 二哥的奖学金 */
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 2000000005;

class Heap{
private:
    int a[200005] = {0};
    int heapsize = 0;

    void swap(int x, int y){
        int t = a[x];
        a[x] = a[y];
        a[y] = t;
    }

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
            if (a[i / 2] < a[i]){
                swap(i, i / 2);
                i *= 2;
            }
            else
                break;
        }
    }

public:
    void insert(int x){
        a[++heapsize] = x;
        siftup(heapsize);
    }

    void remove(){
        swap(1, heapsize);
        --heapsize;
        siftdown();
    }

    int getMax(){
        return a[1];
    }

    void removeAndInsert(int x){
        a[1] = x;
        siftdown();
    }
};

pair<int, int> a[200005];
int sum1[200005] = {0}, sum2[200005] = {0};
int n, c, f;
Heap heap1, heap2;

void qsort(int l, int h){
    if (l >= h)
        return;
    int i = l, j = h;
    pair<int, int> key = a[l];
    while (i < j){
        while (i < j && a[j] > key)
            --j;
        a[i] = a[j];
        while (i < j && a[i] < key)
            ++i;
        a[j] = a[i];
    }
    a[i] = key;
    qsort(l, i - 1);
    qsort(i + 1, h);
}

int main(){
    cin >> n >> c >> f;
    for (int i = 1; i <= c; ++i){
        cin >> a[i].first >> a[i].second;
    }
    sort(a + 1, a + c + 1);
//    for (int i = 1; i <= c; ++i)
//        cout << a[i].first << ' ' << a[i].second << endl;
    for (int i = 1; i <= n / 2; ++i){
        sum1[n / 2] += a[i].second;
        heap1.insert(a[i].second);
    }
    for (int i = n / 2 + 1; i <= c; ++i){
        int t = a[i].second;
        if (t > heap1.getMax())
            sum1[i] = sum1[i - 1];
        else{
            sum1[i] = sum1[i - 1] - heap1.getMax() + t;
            heap1.remove();
            heap1.insert(t);
        }
    }
    for (int i = c; i >= c - n / 2 + 1; --i){
        sum2[c - n / 2 + 1] += a[i].second;
        heap2.insert(a[i].second);
    }
    for (int i = c - n / 2; i >= 1; --i){
        int t = a[i].second;
        if (t > heap2.getMax())
            sum2[i] = sum2[i + 1];
        else{
            sum2[i] = sum2[i + 1] - heap2.getMax() + t;
            heap2.remove();
            heap2.insert(t);
        }
    }
    int ans = -1;
    for (int i = n / 2 + 1; i <= c - n / 2; ++i){
        int t = sum1[i - 1] + sum2[i + 1] + a[i].second;
        if (t <= f && ans < a[i].first)
            ans = a[i].first;
    }
    cout << ans << endl;
    return 0;
}
