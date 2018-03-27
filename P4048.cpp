/* Evensgn的坚定之桌 */
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Leg{
public:
    int d = 0, l = 0;
};
bool cmp(Leg l1, Leg l2){
    return (l1.l < l2.l || (l1.l == l2.l && l1.d < l2.d));
}
/*bool cmp2(Leg l1, Leg l2){
    return (l1.d < l2.d);
}*/

Leg leg[100005];
int f[100005], d[205];
int n;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> leg[i].l;
    for (int i = 1; i <= n; ++i)
        cin >> leg[i].d;
    sort(leg + 1, leg + n + 1, cmp);
    f[1] = 0;
    int nowl = 1;
    for (int i = 2; i <= n; ++i){
        if (leg[i].l == leg[i - 1].l) ++nowl;
        else{
            for (int k = i - 1; k >= i - nowl; --k)
                ++d[leg[k].d];
            nowl = 1;
        }
        if (nowl > i / 2) f[i] = 0;
        else{
            int tmp1 = f[i - 1] + leg[i].d;
            int tmp2 = 0, cnt = 0, lim = i - 2 * nowl + 1;
            for (int k = 0; k <= 200; ++k){
                if (cnt + d[k] >= lim){
                    tmp2 += k * (lim - cnt);
                    break;
                }
                else{
                    tmp2 += k * d[k];
                    cnt += d[k];
                }
            }
            f[i] = min(tmp1, tmp2);
        }
    }
    cout << f[n] << endl;
    return 0;
}
