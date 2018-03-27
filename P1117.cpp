/* Code */
#include <iostream>
using namespace std;

int a[100005], heap[100005];
int degree[100005] = {0};
bool b[100005];
int head[100005], nxt[200005], prv[200005], e[200005];
int heapsize = 0, n = 0, cnt = 0;

void addEdge(int u, int v){
    nxt[++cnt] = head[u];
    if (head[u] != 0)
        prv[head[u]] = cnt;
    head[u] = cnt;
    e[cnt] = v;
    ++degree[u];
    ++degree[v];
}

void delEdge(int u, int x){
    //cout << e[x] << ' ' << e[prv[x]] << ' ' << e[nxt[x]] << endl;
    if (nxt[x] != 0)
        prv[nxt[x]] = prv[x];
    if (prv[x] != 0)
        nxt[prv[x]] = nxt[x];
    else
        head[u] = nxt[x];
    prv[x] = nxt[x] = 0;
}

void swap(int x, int y){
    int t = heap[x];
    heap[x] = heap[y];
    heap[y] = t;
}

void siftup(){
    int i = heapsize;
    while (i != 1){
        if (heap[i] < heap[i / 2]){
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
        if (i + 1 <= heapsize && heap[i + 1] < heap[i])
            ++i;
        if (heap[i / 2] > heap[i]){
            swap(i / 2, i);
            i *= 2;
        }
        else
            break;
    }
}

void remove(){
    swap(1, heapsize);
    --heapsize;
    siftdown();
}

void insert(int x){
    heap[++heapsize] = x;
    siftup();
}

void buildTree(int x){
    char ch;
    int num = 0;
    cin >> ch;
    while (isdigit(ch)){
        num = num * 10 + ch - '0';
        cin >> ch;
    }
    if (num > n)
        n = num;
    if (x){
        addEdge(num, x);
        addEdge(x, num);
    }
    a[num] = num;
    while (ch == '('){
        buildTree(num);
        cin >> ch;
    }
}

int main(){
    char ch;
    cin >> ch;
    buildTree(0);
    for (int i = 1; i <= n; ++i){
        if (degree[a[i]] == 2)
            insert(a[i]);
        b[i] = true;
    }
    for (int i = 1; i < n; ++i){
        int t = heap[1];
        cout << e[head[t]] << ' ';
        b[t] = false;
        remove();
        int j = head[t];
        int u = e[j];
        delEdge(t, j);
        if (j % 2)
            delEdge(u, j + 1);
        else
            delEdge(u, j - 1);
        degree[u] -= 2;
        if (degree[u] == 2)
            insert(u);
    }
    return 0;
}
