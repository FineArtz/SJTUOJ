/* 面包比可爱 */
#include <iostream>
using namespace std;

int main(){
	int n = 0, a[100], ans[100] = {0};
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j <= i - 1; ++j)
			if (a[i] > a[j]) ++ans[i];
	for (int i = 0; i < n; ++i) cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
