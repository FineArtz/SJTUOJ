/* 步步为赢 */
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool devide(const string &s, const string &t, const int &x){
    string tmp = "";
    int len = s.size();
	for (int j = 0; j < x; ++j){
		for (int i = 0; i < len / x; ++i){
            tmp += s[i * x + j];
        }
    }
    if (tmp == t) return true;
    else return false;
}

int main(){
    string s, t;
    cin >> s >> t;
    int len = s.size();
    for (int i = 2; i <= len; ++i){
        if (len % i == 0){
            bool flag = devide(s, t, i);
            if (flag){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
