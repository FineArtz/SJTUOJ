/* ´òµç»° */
#include <iostream>
#include <string>
#include <map>
using namespace std;

const char res[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 0, 7, 7, 8, 8, 8, 9, 9, 9, 0};

bool IsLet(char ch) { return (ch >= 'A' && ch <= 'Z'); }
bool IsNum(char ch) { return (ch >= '0' && ch <= '9'); }

int main(){
    int n, flag = 0;
    cin >> n;
    map<string, int> ans;
    for (int i = 1; i <= n; ++i){
        string s, ss = "";
        cin >> s;
        for (string::iterator it = s.begin(); it != s.end(); ++it){
            if (IsNum(*it)) ss.push_back(*it);
            else if (IsLet(*it)) ss.push_back(res[*it - 'A'] + '0');
        }
        ss.insert(ss.begin() + 3, '-');
        ++ans[ss];
    }
    for (map<string, int>::iterator it = ans.begin(); it != ans.end(); ++it)
        if (it->second > 1){
            cout << it->first << ' ' << it->second << endl;
            flag = 1;
        }
    if (!flag) cout << "No duplicates." << endl;
    return 0;
}
