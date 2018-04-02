/* Problem C */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 40000;

struct Node{
    int l = 0, r = 0;
    long long sum1 = 0, sum2 = 0;
    bool lazy1 = false, lazy2 = false;
};

struct Line{
    long long x[2], y[2];
    int d = 0;
    int index = 0;

    bool operator <(const Line &l){
        if (l.x[0] >= x[0] && l.x[0] <= x[1]){
            double yy = (double)((y[1] - y[0]) * (l.x[0] - x[0])) / (x[1] - x[0]) + y[0];
            return yy > l.y[0];
        }
        if (l.x[1] >= x[0] && l.x[1] <= x[1]){
            double yy = (double)((y[1] - y[0]) * (l.x[1] - x[0])) / (x[1] - x[0]) + y[0];
            return yy > l.y[1];
        }
        if (x[0] >= l.x[0] && x[0] <= l.x[1]){
            double yy = (double)((l.y[1] - l.y[0]) * (x[0] - l.x[0])) / (l.x[1] - l.x[0]) + l.y[0];
            return yy < y[0];
        }
        if (x[1] >= l.x[0] && x[1] <= l.x[1]){
            double yy = (double)((l.y[1] - l.y[0]) * (x[1] - l.x[0])) / (l.x[1] - l.x[0]) + l.y[0];
            return yy < y[1];
        }
        return (y[d] > l.y[l.d] || (y[d] == l.y[l.d] && x[1] < l.x[0]));
    }
};

Line line[MAXN + 5];
Node a[MAXN * 8 + 5];
int s[MAXN * 2 + 5];
int n;
int ans[MAXN + 5] = {0};

void pushup(int x){
    a[x].sum1 = a[x << 1].sum1 + a[x << 1 | 1].sum1;
    a[x].sum2 = a[x << 1].sum2 + a[x << 1 | 1].sum2;
}

void buildTree(int x, int l, int r){
    a[x].l = l;
    a[x].r = r;
    if (l == r){
        a[x].sum1 = s[l] - s[l - 1];
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(x << 1, l, mid);
    buildTree(x << 1 | 1, mid + 1, r);
    pushup(x);
}

void pushdown(int x){
    if (a[x].lazy1){
        a[x << 1].lazy1 = true;
        a[x << 1 | 1].lazy1 = true;
        a[x << 1].sum1 = a[x].sum1;
        a[x << 1 | 1].sum1 = a[x].sum1;
        a[x].lazy1 = false;
    }
    if (a[x].lazy2){
        a[x << 1].lazy2 = true;
        a[x << 1 | 1].lazy2 = true;
        a[x << 1].sum2 = a[x].sum2;
        a[x << 1 | 1].sum2 = a[x].sum2;
        a[x].lazy2 = false;
    }
}

int sum1(int x, int l, int r){
    if (l > r)
        return 0;
    if (a[x].l == l && a[x].r == r)
        return a[x].sum1;
    pushdown(x);
    int mid = (a[x].l + a[x].r) >> 1;
    if (r <= mid)
        return sum1(x << 1, l, r);
    else if (l > mid)
        return sum1(x << 1 | 1, l, r);
    else
        return sum1(x << 1, l, mid) + sum1(x << 1 | 1, mid + 1, r);
}

int sum2(int x, int l, int r){
    if (l > r)
        return 0;
    if (a[x].l == l && a[x].r == r)
        return a[x].sum2;
    pushdown(x);
    int mid = (a[x].l + a[x].r) >> 1;
    if (r <= mid)
        return sum2(x << 1, l, r);
    else if (l > mid)
        return sum2(x << 1 | 1, l, r);
    else
        return sum2(x << 1, l, mid) + sum2(x << 1 | 1, mid + 1, r);
}

void update1(int x, int l, int r){
    if (a[x].l == l && a[x].r == r){
        a[x].sum1 = 0;
        a[x].lazy1 = true;
        return;
    }
    pushdown(x);
    int mid = (a[x].l + a[x].r) >> 1;
    if (r <= mid)
        update1(x << 1, l, r);
    else if (l > mid)
        update1(x << 1 | 1, l, r);
    else{
        update1(x << 1, l, mid);
        update1(x << 1 | 1, mid + 1, r);
    }
    pushup(x);
}

void update2(int x, int l, int r){
    if (a[x].l == l && a[x].r == r){
        a[x].sum2 = 0;
        a[x].lazy2 = true;
        return;
    }
    pushdown(x);
    int mid = (a[x].l + a[x].r) >> 1;
    if (r <= mid)
        update2(x << 1, l, r);
    else if (l > mid)
        update2(x << 1 | 1, l, r);
    else{
        update2(x << 1, l, mid);
        update2(x << 1 | 1, mid + 1, r);
    }
    pushup(x);
}

void update(int x, int p, int d){
    if (a[x].l == a[x].r){
        a[x].sum2 = d;
        return;
    }
    int mid = (a[x].l + a[x].r) >> 1;
    pushdown(x);
    if (p <= mid)
        update(x << 1, p, d);
    else
        update(x << 1 | 1, p, d);
    pushup(x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> line[i].x[0] >> line[i].y[0] >> line[i].x[1] >> line[i].y[1];
        s[2 * i - 1] = line[i].x[0];
        s[2 * i] = line[i].x[1];
        if (line[i].y[0] > line[i].y[1])
            line[i].d = 1;
        line[i].index = i;
    }
    sort(line + 1, line + n + 1);
    sort(s + 1, s + 2 * n + 1);
    int num = unique(s + 1, s + 2 * n + 1) - (s + 1);
    for (int i = 1; i <= n; ++i){
        int pos1 = lower_bound(s + 1, s + num + 1, line[i].x[0]) - s;
        int pos2 = lower_bound(s + 1, s + num + 1, line[i].x[1]) - s;
        line[i].x[0] = pos1;
        line[i].x[1] = pos2;
    }
    s[0] = s[1];
    buildTree(1, 1, num);
    for (int i = 1; i <= n; ++i){
        long long s = sum1(1, line[i].x[0] + 1, line[i].x[1]) + sum2(1, line[i].x[0], line[i].x[1]);
        update1(1, line[i].x[0] + 1, line[i].x[1]);
        update2(1, line[i].x[0], line[i].x[1]);
        if (line[i].d == 0)
            update(1, line[i].x[0], s);
        else
            update(1, line[i].x[1], s);
        ans[line[i].index] = s;
    }
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << '\n';
    return 0;
}
