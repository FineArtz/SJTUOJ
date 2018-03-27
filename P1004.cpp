/* 西西弗斯式的命运 */
#include <iostream>
using namespace std;

int main(){
    int m, t, u, f, d;
    cin >> m >> t >> u >> f >> d;
    char road;
    int NowTime = 0;
    for (int i = 0; i != t; ++i){
        cin >> road;
        switch(road){
            case 'u': case 'd':
                NowTime = NowTime + u + d;
                break;
            case 'f':
                NowTime += 2 * f;
                break;
            default:
                break;
        }
        if (NowTime > m){
            cout << i << endl;
            return 0;
        }
    }
    cout << t << endl;
    return 0;
}
