/* 二哥炒股票 */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int EndOfTrade = 100000005;
struct TradeRecord{
    //constructor
    TradeRecord() : t(0), a(0), d(0) {};
    TradeRecord(const TradeRecord &TR) : t(TR.t), a(TR.a), d(TR.d) {}
    int t, a;
    short d;
};

double profit(const TradeRecord &trade, const int &v){
	double ret = 0.0;
	if (trade.d == 1){
        double outcome = 100.0 * v * trade.a;
        outcome += (outcome - 2500 > -1e-6) ? outcome * 0.002 : 5.0;
        outcome += trade.a / 10.0;
        outcome += 1.0;
        ret -= outcome;
    }
    else{
        double income = 100.0 * v * trade.a;
        double t = income;
        income -= t * 0.001;
		income -= (t - 2500 > -1e-6) ? t * 0.002 : 5.0;
        income -= trade.a / 10.0;
        income -= 1.0;
    	ret += income;
    }
    return ret;
}

int main(){
    TradeRecord tr[55];
    int m = 0;
    cin >> m;
    for (int i = 1; i <= m; ++i){
        cin >> tr[i].t >> tr[i].a >> tr[i].d;
    }
    int n = 0;
    cin >> n;
    int t[10005], v[10005];
    for (int i = 1; i <= n; ++i)
        cin >> t[i] >> v[i];
    int j = 1;
    double NetProfit = 0.0;
    for (int i = 1; i <= n; ++i){
        if (t[i] < tr[j].t) continue;
        while (j <= m && tr[j].t < t[i]){
            NetProfit += profit(tr[j], v[i - 1]);
            ++j;
        }
        if (j > m) break;
    }
    for (int i = j; i <= m; ++i){
        NetProfit += profit(tr[i], v[n]);
    }
    cout << setiosflags(ios::fixed) << setprecision(2) << NetProfit << endl;
    return 0;
}
