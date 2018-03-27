#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> bucket;
    int f[10005] = {0};
    int v, n;
    cin >> v >> n;
    while (n--){
        int vi, wi;
        cin >> vi >> wi;
        if (bucket.find(vi) != bucket.end()){
            if (bucket[vi] < wi) bucket[vi] = wi;
        }
        else bucket[vi] = wi;
    }
    for (auto i = bucket.begin(); i != bucket.end(); ++i)
        for (int j = i->first; j <= v; ++j)
            f[j] = max(f[j], f[j - i->first] + i->second);
    cout << f[v] << endl;
    return 0;
}
