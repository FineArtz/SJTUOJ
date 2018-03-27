/* 小M爱机器人队形 */
#include <iostream>
using namespace std;

int a[1000005], n;
int ans1[1000005], ans2[1000005], t[1000005];
int len;

int bisearch(int i){
    int l = 1, r = len, mid;
    while (l < r){
        mid = (l + r) / 2;
        if (t[mid] >= a[i])
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        ans1[i] = 1;
        ans2[i] = 1;
    }
    t[1] = a[1];
    len = 1;
    for (int i = 2; i <= n; ++i){
        if (a[i] > t[len]){
            t[++len] = a[i];
        }
        else{
            int p = bisearch(i);
            t[p] = a[i];
        }
        ans1[i] = len;
    }
    len = 1;
    t[1] = a[n];
    for (int i = n - 1; i >= 1; --i){
        if (a[i] > t[len]){
            t[++len] = a[i];
        }
        else{
            int p = bisearch(i);
            t[p] = a[i];
        }
        ans2[i] = len;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans = max(ans, ans1[i] + ans2[i] - 1);
    cout << n - ans << endl;
    return 0;
}
