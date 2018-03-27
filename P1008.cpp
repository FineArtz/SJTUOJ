/* ¶ş¸çÂòÆÚ»õ */
#include <iostream>
#include <string>
using namespace std;

bool LeapYear[10000] = {0}, CanTrade[10000][13][32] = {0};
const short Day[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
short Week[10000][13][32] = {0}, CanTradeDays[10000] = {0};

struct Date{
    //constructor
    Date(const string&);
    Date(int, int, int);

    Date& operator ++();
    friend inline bool operator ==(const Date&, const Date&);
    friend inline bool operator !=(const Date&, const Date&);
    int yy, mm, dd;
};
Date::Date(const string& s){
    yy = mm = dd = 0;
    for (int i = 0; i != 4; ++i)
        yy = yy * 10 + s[i] - '0';
    mm = (s[5] - '0') * 10 + s[6] - '0';
    dd = (s[8] - '0') * 10 + s[9] - '0';
}
Date::Date(int y, int m, int d) : yy(y), mm(m), dd(d){}
Date& Date::operator ++(){
    ++dd;
    if (mm != 2){
        if (dd > Day[mm]){
            dd = 1;
            ++mm;
            if (mm > 12){
                mm = 1;
                ++yy;
            }
        }
    }
    else{
        if (dd > (LeapYear[yy] ? 29 : 28)){
            dd = 1;
            mm = 3;
        }
    }
    return *this;
}
inline bool operator ==(const Date& lhs, const Date& rhs){
    return (lhs.yy == rhs.yy && lhs.mm == rhs.mm && lhs.dd == rhs.dd);
}
inline bool operator !=(const Date& lhs, const Date& rhs){
    return !(lhs == rhs);
}

inline int succ(int x) { return ((x + 1) % 7 == 0) ? 7 : ((x + 1) % 7); }

void PreTreatment(){
    for (int i = 1900; i <= 9999; ++i)
        LeapYear[i] = (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0));
    Week[1900][1][1] = 1;
    for (int yy = 1900; yy <= 9999; ++yy){
        int day = 0, lday = 0, year = yy;
        for (int mm = 1; mm <= 12; ++mm)
        {
            if (mm != 2) day = Day[mm];
            else day = (LeapYear[year] ? 29 : 28);
            if (mm > 1) Week[yy][mm][1] = succ(Week[yy][mm - 1][lday]);
            else if (yy != 1900) Week[yy][mm][1] = succ(Week[yy - 1][12][31]);
            for (int dd = 2; dd <= day; ++dd)
                Week[yy][mm][dd] = succ(Week[yy][mm][dd - 1]);
            lday = day;
            day = 0;
        }
    }
    for (int yy = 1900; yy <= 9999; ++yy)
        for (int mm = 1; mm <= 12; ++mm){
            int day;
            if (mm != 2) day = Day[mm];
            else day = (LeapYear[yy] ? 29 : 28);
            for (int dd = 1; dd <= day; ++dd){
                CanTrade[yy][mm][dd] = !((Week[yy][mm][dd] == 6) || (Week[yy][mm][dd] == 7)
                                        || (mm == 1 && dd == 1) || (mm == 5 && dd <= 3) || (mm == 10 && dd <= 7));
				if (CanTrade[yy][mm][dd]) ++CanTradeDays[yy];
			}
        }
}

int gap(const Date& d1, const Date& d2){
    int ret = 0;
    if (d1.yy + 1 >= d2.yy){
    	for (Date d(d1.yy, d1.mm, d1.dd); d != d2; ++d)
            if (CanTrade[d.yy][d.mm][d.dd]) ++ret;
        return (CanTrade[d2.yy][d2.mm][d2.dd] ? ++ret : ret);
    }
	for (Date d(d1.yy, d1.mm, d1.dd); d != Date(d1.yy + 1, 1, 1); ++d)
        if (CanTrade[d.yy][d.mm][d.dd]) ++ret;
    for (Date d(d2.yy, 1, 1); d != d2; ++d)
        if (CanTrade[d.yy][d.mm][d.dd]) ++ret;
    if (CanTrade[d2.yy][d2.mm][d2.dd]) ++ret;
    for (int yy = d1.yy + 1; yy != d2.yy; ++yy)
        ret += CanTradeDays[yy];
    return ret;
}

int main(){
    PreTreatment();
    int n;
    cin >> n;
    for (int data = 0; data != n; ++data){
        string s1, s2;
        cin >> s1 >> s2;
        Date date1(s1), date2(s2);
        cout << gap(date1, date2) << endl;
    }
    return 0;
}
