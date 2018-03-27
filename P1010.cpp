/* 二哥的储蓄计划 */
#include <iostream>
using namespace std;

int main(){
	int bd = 0, now = 0, mom = 0;
	for (int i = 1; i <= 12; ++i){
		cin >> bd;
		now += 300;
		if (now < bd){
			cout << '-' << i << endl;
			return 0;
		}
		mom += (now - bd) / 100 * 100;
		now = (now - bd) % 100;
	}
	now += mom * 1.2;
	cout << now << endl;
	return 0;
}
