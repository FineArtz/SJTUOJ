/* °οηχΒ¶ΕµΌΣΓά */
#include <iostream>
using namespace std;

int main(){
	char ch;
	int ans = 0, i = 0;
	while (cin.get(ch)){
		++i;
		int p = 0;
		if ((ch >= 'A') && (ch <= 'Z')) p = ch - 'A' + 1;
		if ((ch >= 'a') && (ch <= 'z')) p = ch - 'a' + 27;
		ans += p * i;
	}
	cout << ans << endl;
	return 0;
}
