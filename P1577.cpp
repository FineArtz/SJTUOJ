/* °¢ºÚµÄÖÊÁ£ */
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    s.erase(s.begin());
    s.erase(s.end() - 1);
    int cnt = 0;
    while (n--){
        cin >> t;
        t.erase(t.begin());
        t.erase(t.end() - 1);
        if (t.size() != s.size()) continue;
        t += t;
        if (t.find(s) != string::npos) ++cnt;
        else{
            string p(t.rbegin(), t.rend());
            if (p.find(s) != string::npos) ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}
