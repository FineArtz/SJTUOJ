/* ±´Ñ§³¤°Ú±´¿Ç */
#include <iostream>
using namespace std;

int reflection[100005] = {0}, a[100005] = {0}, ans[100005] = {0};

int bisearch(int low, int high, int sought){
    if (low >= high) return low;
    int m = (low + high) / 2;
    if (ans[m] < sought) return bisearch(m + 1, high, sought);
    else return bisearch(low, m, sought);
}

int main(){
    int n, len = 0, j = 0, t = 0;;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> t;
        reflection[t] = i;
    }
    for (int i = 1; i <= n; ++i){
        cin >> t;
        a[i] = reflection[t];
        if (a[i] > ans[len]) j = ++len;
        else j = bisearch(1, len, a[i]);
        ans[j] = a[i];
    }
   // for (int i = 1; i <= n; ++i) cout << a[i] << ' ';
    //cout << endl;
    cout << len << endl;
    return 0;
}
