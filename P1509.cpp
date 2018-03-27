/* ½ÚÈÕ¼ÆËãÆ÷ */
#include <iostream>
#include <string>
using namespace std;

inline int succ(int x) { return ((x + 1) % 7 == 0) ? 7 : ((x + 1) % 7); }
inline string f(int x) {
    string ret = "";
    if (x / 10){
        ret += char(x / 10 + '0');
    }
    else ret += "0";
    ret += char(x % 10 + '0');
    return ret;
}
int main(){
    int date[205][15][35] = {0};
    date[0][1][1] = 2;
    for (int yy = 0; yy <= 2050 - 1850; ++yy){
        int day = 0, lday = 0, year = yy + 1850;
        for (int mm = 1; mm <= 12; ++mm)
        {
            switch(mm){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                day = 31;
                break;
            case 4: case 6: case 9: case 11:
                day = 30;
                break;
            case 2:
                day = ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) ? 29 : 28;
                break;
            }
            if (mm > 1) date[yy][mm][1] = succ(date[yy][mm - 1][lday]);
            else if (yy != 0) date[yy][mm][1] = succ(date[yy - 1][12][31]);
            for (int dd = 2; dd <= day; ++dd)
                date[yy][mm][dd] = succ(date[yy][mm][dd - 1]);
            lday = day;
            day = 0;
        }
    }
    int a, b, c, y1, y2;
    cin >> a >> b >> c >> y1 >> y2;
    for (int yy = y1; yy <= y2; ++yy){
        int dd = 1, cnt = 0;
        while (date[yy - 1850][a][dd]){
            if (date[yy - 1850][a][dd] == c) ++cnt;
            if (cnt == b){
                cout << yy << "/" << f(a) << "/" << f(dd) << endl;
                break;
            }
            ++dd;
        }
        if (!date[yy - 1850][a][dd]) cout << "none" << endl;
    }
    return 0;
}
