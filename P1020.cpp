/* 分解质因数 */
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

bool isp(int x){
    for (int i = 2; i <= trunc(sqrt(x)); ++i)
        if (x % i == 0) return false;
    return true;
}

int main(){
    int n;
    cin >> n;
    int nn = n;
    map<int, int> ans;
    for (int i = 2; i <= trunc(sqrt(nn)); ++i){
        if (isp(i)){
            while (n % i == 0){
                ++ans[i];
                n /= i;
            }
        }
    }
    if (n != 1) ++ans[n];
    cout << nn << "=";
    for (map<int, int>::iterator i = ans.begin(); i != ans.end(); ++i)
        cout << i->first << '(' << i->second << ')';
    cout << endl;
    return 0;
}
