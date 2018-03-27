/* ´÷ÂÌÃ±×ÓµÄ¿Õ¹Ü */
#include <iostream>
#include <algorithm>
using namespace std;

class plane{
public:
    int i = 0, u = 0, g = 0;
};

plane timee[1000005];
int down[1005];
int n, m, s;

bool canDown(int t1, int t2){
    if (t2 == -1) return true;
    if ((t1 + timee[t1].u) - (t2 + timee[t2].u) >= s) return true;
    return false;
}

int main(){
    cin >> n >> m >> s;
    bool flag = false;
    for (int i = 1; i <= n; ++i){
        int t;
        plane tp;
        cin >> t >> tp.u >> tp.g;
        tp.i = i;
        if (t > m){
            flag = true;
            continue;
        }
        if (timee[t].i != 0){
            cout << "CHANGE BOYFRIEND" << endl;
            return 0;
        }
        timee[t] = tp;
    }
    int lastDown = -1;
    for (int t = 0; t <= m; ++t){
        if (timee[t].i == 0) continue;
        if (canDown(t, lastDown)){
            lastDown = t;
            int tt = t + timee[t].u;
            if (tt > m) flag = true;
            else (down[timee[t].i] = tt);
        }
        else{
            int tt = t + timee[t].g;
            if (tt > m){
                flag = true;
                continue;
            }
            if (timee[tt].i != 0){
                cout << "CHANGE BOYFRIEND" << endl;
                return 0;
            }
            timee[tt] = timee[t];
        }
    }
    if (flag) cout << "GO DATING" << endl;
    else
        for (int i = 1; i <= n; ++i)
            cout << down[i] << endl;
    return 0;
}
