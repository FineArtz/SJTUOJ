/* 侠盗罗宾 */
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n, k;
map<int, long long> w;

int main(){
    cin >> n >> k;
    int maxx = 0, minn = 1000000005;
    long long sum = 0;
    for (long long i = 1; i <= n; ++i){
        int t;
        cin >> t;
        ++w[t];
        maxx = max(maxx, t);
        minn = min(minn, t);
        sum += t;
    }
    long long p = 0, pp = 0, r = 0, rr = 0;
    for (auto i = w.begin(); ; ++i){
        if (pp + i->second > n / 2) break;
        pp += i->second;
        p += i->first * i->second;
    }
    for (auto i = w.end(); ; --i){
        if (i == w.end()) continue;
        if (rr + i->second > n / 2) break;
        rr += i->second;
        r += i->first * i->second;
    }
    if (r - p <= 2 * k){
        if (sum % n == 0)
            cout << 0 << endl;
        else
            cout << 1 << endl;
        return 0;
    }
    int kk = k, mp = minn, tp = w[minn];
    for (auto i = w.begin(); ; ++i){
        if (i == w.begin()) continue;
        if ((i->first - mp) * tp > kk){
            mp += kk / tp;
            break;
        }
        kk -= (i->first - mp) * tp;
        mp = i->first;
        tp += i->second;
    }
    int mr = maxx, tr = w[maxx];
    kk = k;
    for (auto i = w.end(); ; --i){
        if (i == w.end()) continue;
        if (i->first == maxx) continue;
        if ((mr - i->first) * tr > kk){
            mr -= kk / tr;
            break;
        }
        kk -= (mr - i->first) * tr;
        mr = i->first;
        tr += i->second;
    }
    cout << mr - mp << endl;
    return 0;
}
