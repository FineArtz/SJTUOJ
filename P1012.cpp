/* 增长率问题 */
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<int> CanInc[200005];
int len[200005] = {0};
long long tms[200005] = {0}, cnt[200005] = {0};
//f[i]表示以i结尾的最长序列长度，tms[i]表示以i结尾的最长序列的个数，cnt[i]表示长度为i的序列数

/*void PreTreatment(int s, int t){
    for (int i = s; i != t; ++i)
        for (int p = 1; p <= 99; ++p){
            if (trunc(s * p * 0.01) == (s * p / 100))
                CanInc[i].push_back(p);
        }
}
*/
int main(){
    int s, t;
    cin >> s >> t;
    for (int i = s; i <= t; ++i){
    	len[i] = 1;
    	tms[i] = 1;
	}
    cnt[1] = t - s + 1;
    long long ans = 1;
    for (int i = s; i < t; ++i){
        for (int j = 1; j <= 100; ++j){
            if (i * j % 100 == 0){
                int next = i + i * j / 100;
                if (next > t) continue;
                if (len[next] == len[i] + 1){
                    tms[next] += tms[i];
                }
                else if (len[next] < len[i] + 1){
                    len[next] = len[i] + 1;
                    tms[next] = tms[i];
                }
                ans = (ans > len[next] ? ans : len[next]);
                cnt[len[i] + 1] += tms[i];
            }
        }
    }
    cout << ans << endl;
    cout << cnt[ans] << endl;
    return 0;
}
