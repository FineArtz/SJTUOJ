/* ¶þ¸çµÄ½ðÁ´ */
#include <iostream>
#include <deque>
using namespace std;

void pop_back(deque<int> &d){
    while ((d.end() - d.begin()) >= 1 && d.back() >= d.front())
        d.pop_front();
    if (!d.empty()) d.pop_back();
}

int main(){
    int n, k, a[400005];
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
	for (int i = n + 1; i <= n + k; ++i)
		a[i] = a[i - n];
    deque<int> f, ff;
    for (int i = 1; i <= k; ++i)
    {
    	while (!f.empty() && a[i] > f.back()){
    		pop_back(f);
		}
        f.push_back(a[i]);
        ff.push_back(a[i]);
    }
    int maxmin = f[0];
    for (int i = k + 1; i <= n + k; ++i){
        while (!f.empty() && a[i] > f.back()){
            pop_back(f);
        }
        f.push_back(a[i]);
        if (f[0] == ff[0]) f.pop_front();
        ff.pop_front();
        ff.push_back(a[i]);
		if (maxmin > f[0]) maxmin = f[0];
    }
    cout << maxmin << endl;
    return 0;
}
