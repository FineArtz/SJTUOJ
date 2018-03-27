/* pilots */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 2147483647;

int k, n, a[3000005];
pair<int, int> qmin[3000005], qmax[3000005];

bool check(int len){
    memset(qmin, 0, sizeof(qmax));
    memset(qmax, 0, sizeof(qmax));
    int frontMin = 0, rearMin = 0;
    int frontMax = 0, rearMax = 0;
    qmin[rearMin++] = make_pair(0, 0);
    qmax[rearMax++] = make_pair(0, INF);
    for (int i = 1; i <= n; ++i){
        while (frontMin != rearMin && qmin[frontMin].first <= i - len)
            ++frontMin;
        while (frontMax != rearMax && qmax[frontMax].first <= i - len)
            ++frontMax;
        while (frontMin != rearMin && a[i] <= qmin[rearMin - 1].second)
            --rearMin;
        qmin[rearMin++] = make_pair(i, a[i]);
        while (frontMax != rearMax && a[i] >= qmax[rearMax - 1].second)
            --rearMax;
        qmax[rearMax++] = make_pair(i, a[i]);
        if (i < len)
            continue;
        if (qmax[frontMax].second - qmin[frontMin].second <= k)
            return true;
    }
    return false;
}

int main(){
    cin >> k >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 1, r = n, mid;
    while (l < r){
        mid = (l + r) / 2 + (l + r) % 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
