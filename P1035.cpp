/* 二哥炒股票 */
#include <iostream>
#include <algorithm>
using namespace std;

class Stroke{
public:
    bool operator <(const Stroke &s){
        return (price < s.price || price == s.price && ind > s.ind);
    }

    int ind = 0, price = 0;
};

Stroke a[20005];
int n, k;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        a[i].ind = i;
        cin >> a[i].price;
    }
    cin >> k;
    while (k--){
        char ch;
        cin >> ch;
        if (ch == 'Q'){
            Stroke b[20005];
            for (int i = 1; i <= n; ++i){
                b[i] = a[i];
            }
            sort(b + 1, b + n + 1);
            int r;
            cin >> r;
            while (r--){
                int t;
                cin >> t;
                cout << b[n - t + 1].ind << ' ';
            }
            cout << '\n';
        }
        else{
            int x, y;
            cin >> x >> y;
            a[x].price = y;
        }
    }
    return 0;
}
