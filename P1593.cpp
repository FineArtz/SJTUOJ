/* Mouse */
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

class Mouse{
public:
    Mouse() = default;
    Mouse(int x, int y, int z) : id(x), score(y), abi(z) {}
    int id = 0, score = 0, abi = 0;
    bool operator <(const Mouse &m){
        return (score > m.score || score == m.score && id < m.id);
    }
};

int n, r;
Mouse win[200005], draw[200005], lose[200005], rk[200005];

void merge(int ww, int dd, int ll){
    int w = 1, d = 1, l = 1, p = 0;
    while (p <= 2 * n){
        if (win[w] < draw[d] && win[w] < lose[l]){
            rk[++p] = win[w++];
        }
        else if (draw[d] < win[w] && draw[d] < lose[l]){
            rk[++p] = draw[d++];
        }
        else if (lose[l] < win[w] && lose[l] < draw[d]){
            rk[++p] = lose[l++];
        }
        else break;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> r;
    for (int i = 1; i <= 2 * n; ++i){
        cin >> rk[i].score;
        rk[i].id = i;
    }
    for (int i = 1; i <= 2 * n; ++i)
        cin >> rk[i].abi;
    sort(rk + 1, rk + 2 * n + 1);
    int w, d, l;
    for (int round = 1; round <= r; ++round){
        w = 0, d = 0, l = 0;
        for (int race = 1; race <= n; ++race){
            if (rk[race * 2 - 1].abi > rk[race * 2].abi){
                rk[race * 2 - 1].score += 2;
                win[++w] = rk[race * 2 - 1];
                lose[++l] = rk[race * 2];
            }
            else if (rk[race * 2 - 1].abi == rk[race * 2].abi){
                ++rk[race * 2 - 1].score;
                ++rk[race * 2].score;
                draw[++d] = rk[race * 2 - 1];
                draw[++d] = rk[race * 2];
            }
            else{
                rk[race * 2].score += 2;
                win[++w] = rk[race * 2];
                lose[++l] = rk[race * 2 - 1];
            }
        }
        win[w + 1] = Mouse(0, -1, 0);
        draw[d + 1] = Mouse(0, -1, 0);
        lose[l + 1] = Mouse(0, -1, 0);
        merge(w, d, l);
    }
    for (int i = 1; i <= 2 * n; ++i)
        cout << rk[i].id << " ";
    cout << '\n';
    return 0;
}
