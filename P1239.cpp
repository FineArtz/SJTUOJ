/* �����ҹ��� */
#include <iostream>
using namespace std;

int main(){
	int n = 0, ans = 0;
	cin >> n;
	if (n > 3500){
		n -= 3500;
		if (n <= 1500) ans = n * 0.03;
		else if (n <= 4500) ans = 1500 * 0.03 + (n - 1500) * 0.1;
		else if (n <= 9000) ans = 1500 * 0.03 + 3000 * 0.1 + (n - 4500) * 0.2;
		else if (n <= 35000) ans = 1500 * 0.03 + 3000 * 0.1 + 4500 * 0.2 + (n - 9000) * 0.25;
		else if (n <= 55000) ans = 1500 * 0.03 + 3000 * 0.1 + 4500 * 0.2 + 26000 * 0.25 + (n - 35000) * 0.3;
		else if (n <= 80000) ans  = 1500 * 0.03 + 3000 * 0.1 + 4500 * 0.2 + 26000 * 0.25 + 20000 * 0.3 + (n - 55000) * 0.35;
		else ans = 1500 * 0.03 + 3000 * 0.1 + 4500 * 0.2 + 26000 * 0.25 + 20000 * 0.3 + 25000 * 0.35 + (n - 80000) * 0.45;
	}
	cout << ans << endl;
	return 0;
}