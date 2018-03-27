/* FZ∑∫÷€ */
#include <iostream>
using namespace std;

int main(){
	int x, n;
	cin >> x >> n;
	int p = n / 7 * 5;
	n %= 7;
	for (int i = x; i <= x + n - 1; ++i){
		if ((i % 6 == 0) || (i % 7 == 0)) continue;
		++p;
	}
	cout << p * 250 << endl;
	return 0;
}
