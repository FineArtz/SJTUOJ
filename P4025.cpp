/* ºéË®À´Ï® */
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

//const long long INF = 2000000000000;

int main(){
    int m, n;
    cin >> m >> n;
    int a[250005] = {0};
	int sub[250005] = {0};
    for (int i = 1; i <= m * n; ++i)
        cin >> a[i];
    long long v;
    cin >> v;
    sort(a + 1, a + m * n + 1);
    if (v == 0){
    	cout << setiosflags(ios::fixed) << setprecision(2) << double(a[1]) << endl;
    	cout << "0.00" << endl;
    	return 0;
	}
	double SeaLevel = 0.0;
	int cnt = 0;
	if (m <= 10 && n <= 10){
    /*for (int i = 1; i <= m * n; ++i)
        cout << a[i] << ' ';
    cout << endl;*/
    	sub[1] = 0;
    	for (int i = 2; i <= m * n; ++i)
        	sub[i] = (a[i] - a[i - 1]) * (i - 1) + sub[i - 1];
	/*for (int i = 1; i <= m * n; ++i)
		cout << sub[i] << endl;*/
		cnt = 1;
		for (; cnt <= m * n; ++cnt)
			if (v <= sub[cnt]) break;
		--cnt;
		v -= sub[cnt];
		SeaLevel = a[cnt] + v * 1.0 / cnt;
	//cout << cnt << endl;
	}
	else {
		for (int i = 1; i <= m * n - 1; ++i)
        	sub[i] = a[i + 1] - a[i];
    	sub[m * n] = -1;
    	cnt = 1;
    	SeaLevel = a[1];
    	while (1){
        	if (v != 0 && cnt < m * n && v >= cnt * sub[cnt]){
            	v -= cnt * sub[cnt];
            	SeaLevel = a[++cnt];
        	}
        	else if (cnt >= m * n){
        		cnt = m * n;
            	SeaLevel += v * 1.0 / cnt;
            	break;
        	}
        	else{
            	SeaLevel += v * 1.0 / cnt;
            	if (v == 0) --cnt;
            	break;
        	}
    	}
	}
    cout << setiosflags(ios::fixed) << setprecision(2) << SeaLevel << endl
                                                       << cnt * 100.0 / (m * n) << endl;
    return 0;
}
