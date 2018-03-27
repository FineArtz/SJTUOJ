/* ”Ôæ‰∆•≈‰ */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int n;
    cin >> n;
    stack<string> state;
    while(n--){
        string s;
        cin >> s;
        if (state.empty()){
            if (s == "then" || s == "end" || s == "else"){
                cout << "NO" << endl;
                return 0;
            }
            state.push(s);
            continue;
        }
        string t = state.top();
        if (s == "then"){
            if (t != "if"){
                cout << "NO" << endl;
                return 0;
            }
            else{
                state.pop();
                state.push(s);
            }
        }
        else if (s == "else"){
            if (t == "begin" || t == "if"){
                cout << "NO" << endl;
                return 0;
            }
            while (!state.empty() && state.top() != "then")
                state.pop();
			if (state.empty()){
				cout << "NO" << endl;
				return 0;
			}
			state.pop();
        }
        else if (s == "end"){
            if (t == "if"){
                cout << "NO" << endl;
                return 0;
            }
            while (!state.empty() && state.top() != "begin")
                state.pop();
			if (state.empty()){
				cout << "NO" << endl;
				return 0;
			}
			state.pop();
        }
        else if (s == "begin"){
            if (t == "if"){
                cout << "NO" << endl;
                return 0;
            }
            state.push(s);
        }
        else if (s == "if"){
            if (t == "if"){
                cout << "NO" << endl;
                return 0;
            }
            state.push(s);
        }
    }
    while (!state.empty() && state.top() == "then") state.pop();
    if (!state.empty()) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
