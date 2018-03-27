/* 二哥打游戏 */
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class Unit{
public:
    char name[25];
    int food = 0, wood = 0, priority = 0;

    bool operator <(const Unit &u){
        return priority > u.priority;
    }
};

int main(){
    Unit a[15];
    int k, n;
    cin >> k;
    for (int i = 1; i <= k; ++i){
        cin >> a[i].name >> a[i].food >> a[i].wood >> a[i].priority;
    }
    sort(a + 1, a + k + 1);
//    for (int i = 1; i <= k; ++i)
//        cout << a[i].name << ' ' << a[i].food << ' ' << a[i].wood << ' ' << a[i].priority << endl;
    int wood = 0, food = 0, bonus = 0;
    int wq[10005], fq[10005], wfront = 0, wrear = 0, ffront = 0, frear = 0;
    cin >> n;
    for (int t = 1; t <= n; ++t){
        char source[5];
        int amount;
        cin >> source >> amount;
        amount += bonus;
        if (source[0] == 'f'){
            fq[frear++] = amount;
            food += amount;
        }
        else if (source[0] == 'w'){
            wq[wrear++] = amount;
            wood += amount;
        }
        for (int i = 1; i <= k; ++i){
            if (food >= a[i].food && wood >= a[i].wood){
                cout << "#" << t << ": a " << a[i].name << " was created." << '\n';
                int f = 0, w = 0;
                while (f < a[i].food){
                    f += fq[ffront++];
                }
                food -= f;
                while (w < a[i].wood){
                    w += wq[wfront++];
                }
                wood -= w;
                if (strcmp(a[i].name, "farmer") == 0)
                    ++bonus;
            }
        }
    }
    cout << "food: " << food << ", wood: " << wood << '\n';
    return 0;
}
