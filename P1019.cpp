/* 括号匹配 */
#include <iostream>
#include <sstream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        istringstream iss(s);
        char ch;
        bool flag = 1;
        int left = 0;
        while (iss >> ch){
            if (ch == '(') ++left;
            else if (ch == ')') --left;
            if (left < 0){
                cout << "NO" << endl;
                flag = 0;
                break;
            }
        }
        if (flag){
            if (left == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
