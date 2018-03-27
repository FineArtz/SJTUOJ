/* 春樱对决 */
#include <iostream>
using namespace std;

class Node{
public:
    int sum = 0, l = 0, r = 0;
};

int n, m, ans = 0;
Node a[100005 * 4];
bool b[100005];

void buildTree(int x, int l, int r){
    if (l == r){
        a[x].sum = 1;
        a[x].l = l;
        a[x].r = r;
        return;
    }
    a[x].l = l;
    a[x].r = r;
    int mid = (l + r) / 2;
    buildTree(x * 2, l, mid);
    buildTree(x * 2 + 1, mid + 1, r);
    a[x].sum = a[x * 2].sum + a[x * 2 + 1].sum;
}

int sum(int l, int r, int x = 1){
    if (l <= a[x].l && r >= a[x].r)
        return a[x].sum;
    int mid = (a[x].l + a[x].r) / 2;
    int ret = 0;
    if (l <= mid)
        ret += sum(l, r, x * 2);
    if (r > mid)
        ret += sum(l, r, x * 2 + 1);
    return ret;
}

void del(int y, int x = 1){
    if (a[x].l == y && a[x].r == y){
        a[x].sum = 0;
        return;
    }
    int mid = (a[x].l + a[x].r) / 2;
    if (y <= mid)
        del(y, x * 2);
    else
        del(y, x * 2 + 1);
    a[x].sum = a[x * 2].sum + a[x * 2 + 1].sum;
}

int count(int k, int p, int &d){
    if (d == 1){
        int l = k, r = n - 1, mid;
        while (l <= r){
            mid = (l + r) / 2;
            int t = sum(k, mid);
            if (t == p + 1){
                if (b[mid])
                    break;
                else
                    r = mid - 1;
            }
            else if (t < p + 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        del(mid);
        b[mid] = false;
        if (sum(mid, n - 1) != 0){
            l = mid + 1;
            r = n - 1;
            int mid2;
            while (l < r){
                mid2 = (l + r) / 2;
                if (sum(mid, mid2) >= 1)
                    r = mid2;
                else
                    l = mid2 + 1;
            }
            k = l;
        }
        else{
            l = 0;
            r = mid - 1;
            int mid2;
            while (l < r){
                mid2 = (l + r) / 2 + (l + r) % 2;
                if (sum(mid2, mid) >= 1)
                    l = mid2;
                else
                    r = mid2 - 1;
            }
            k = r;
            d = -1;
        }
    }
    else{
        int l = 0, r = k, mid;
        while (l <= r){
            mid = (l + r) / 2;
            int t = sum(mid, k);
            if (t == p + 1){
                if (b[mid])
                    break;
                else
                    l = mid + 1;
            }
            else if (t > p + 1)
                l = mid + 1;
            else
                r = mid - 1;
        }
        del(mid);
        b[mid] = false;
        if (sum(0, mid) != 0){
            l = 0;
            r = mid - 1;
            int mid2;
            while (l < r){
                mid2 = (l + r) / 2 + (l + r) % 2;
                if (sum(mid2, mid) >= 1)
                    l = mid2;
                else
                    r = mid2 - 1;
            }
            k = l;
        }
        else{
            l = mid + 1;
            r = n - 1;
            int mid2;
            while (l < r){
                mid2 = (l + r) / 2;
                if (sum(0, mid2) >= 1)
                    r = mid2;
                else
                    l = mid2 + 1;
            }
            k = r;
            d = 1;
        }
    }
    return k;
}

int main(){
    cin >> n >> m;
    --m;
    for (int i = 0; i < n; ++i)
        b[i] = true;
    buildTree(1, 0, n - 1);
    int d = 1, k = 0;
    for (int i = n; i > 1; --i){
        int p = m % (2 * i - 2);
        if (d == 1){
            int t = sum(k, n - 1);
            if (p + 1 <= t)
                k = count(k, p, d);
            else if (p + 1 <= t + i - 1){
                int l = 0, r = n - 1, mid;
                while (l < r){
                    mid = (l + r) / 2 + (l + r) % 2;
                    if (sum(mid, n - 1) >= 1)
                        l = mid;
                    else
                        r = mid - 1;
                }
                d = -1;
                k = count(r, p - t + 1, d);
            }
            else{
                int l = 0, r = n - 1, mid;
                while (l < r){
                    mid = (l + r) / 2;
                    if (sum(0, mid) >= 1)
                        r = mid;
                    else
                        l = mid + 1;
                }
                k = count(l, p - t - i + 2, d);
            }
        }
        else{
            int t = sum(0, k);
            if (p + 1 <= t)
                k = count(k, p, d);
            else if (p + 1 <= t + i - 1){
                int l = 0, r = n - 1, mid;
                while (l < r){
                    mid = (l + r) / 2;
                    if (sum(0, mid) >= 1)
                        r = mid;
                    else
                        l = mid + 1;
                }
                d = 1;
                k = count(l, p - t + 1, d);
            }
            else{
                int l = 0, r = n - 1, mid;
                while (l < r){
                    mid = (l + r) / 2 + (l + r) % 2;
                    if (sum(mid, n - 1) >= 1)
                        l = mid;
                    else
                        r = mid - 1;
                }
                k = count(r, p - t  - i + 2, d);
            }
        }
    }
    cout << ++k << endl;
    return 0;
}
