/* typist */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int FACT[6] = {100000, 10000, 1000, 100, 10, 1};
const int MAXS = 2000000;

struct String{
    int s = 0, cursor = 0;
    long long step = 0;

    String() = default;

    String(const String &ss){
        s = ss.s;
        step = ss.step;
        cursor = ss.cursor;
    }

    String &operator =(const String &ss){
        s = ss.s;
        step = ss.step;
        cursor = ss.cursor;
        return *this;
    }

    bool operator ==(const String &ss){
        return s == ss.s;
    }

    const int operator [](int x) const {
        return s / FACT[x] % 10;
    }

    void inc(int x){
        s += FACT[x];
    }
    void dec(int x){
        s -= FACT[x];
    }

    void swap(int x, int y){
        int p = s / FACT[x] % 10, q = s / FACT[y] % 10;
        s += (q - p) * FACT[x];
        s += (p - q) * FACT[y];
    }
};

String s, a;
String q[2000005];
bool v[1000000][7] = {0};
int front = 0, rear = 0;

void push(const String &n){
    if (v[n.s][n.cursor])
        return;
    rear = (rear + 1) % MAXS;
    q[rear] = n;
    v[n.s][n.cursor] = true;
}

long long bfs(){
    push(s);
    while (front != rear){
        front = (front + 1) % MAXS;
        String t = q[front];
        if (t == a){
            return t.step;
        }
        String n;
        int i = t.cursor;
        if (i != 0){
            n = t;
            ++n.step;
            n.swap(i, 0);
            push(n);
        }
        if (i != 5){
            n = t;
            ++n.step;
            n.swap(i, 5);
            push(n);
        }
        if (t[i] != a[i]){
            if (t[i] != 0){
                n = t;
                ++n.step;
                n.dec(i);
                push(n);
            }
            if (t[i] != 9){
                n = t;
                ++n.step;
                n.inc(i);
                push(n);
            }
        }
        if (i != 0){
            n = t;
            ++n.step;
            --n.cursor;
            push(n);
        }
        if (i != 5){
            n = t;
            ++n.step;
            ++n.cursor;
            push(n);
        }
    }
    return -1;
}

int main(){
    char p[7], q[7];
    cin >> p >> q;
    for (int i = 0; i < 6; ++i){
        s.s = s.s * 10 + p[i] - '0';
        a.s = a.s * 10 + q[i] - '0';
    }
    long long ans = bfs();
    cout << ans << endl;
    return 0;
}
