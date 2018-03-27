/* 环式扶贫 */
#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, t;
    long long sum = 0;
    map<long long, int> m;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> t;
        sum += t;
        ++m[sum];
    }
    //for (auto i : m)
    //    cout << i.first << ' ' << i.second << endl;
    int cnt = 0;
    for (auto i : m){
        if (cnt < i.second) cnt = i.second;
    }
    cout << n - cnt << endl;
    return 0;
}
