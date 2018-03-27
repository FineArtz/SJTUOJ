/* NC的颜文字 */
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

const char none[] = "Are you kidding me? \\(`Д´)/";

/*void init(vector<string> &vs){
    char ch;
    ch = cin.get();
    while (ch != '\n'){
        if (ch == '['){
            string temps = "";
            ch = cin.get();
            while (ch != ']'){
                if (ch == '\n') return;
                temps += ch;
                ch = cin.get();
            }
            if (temps != "" && vs.size() < 15)
                vs.push_back(temps);
        }
        ch = cin.get();
    }
}*/

int main(){
    vector<string> lib[3];
    char ch;
    for (int i = 0; i != 3; ++i){
        while ((ch = cin.get()) != '\n'){
            if (ch == '['){
                string temps;
                while ((ch = cin.get()) != ']')
                    temps += ch;
                //if (lib[i].size() < 15)
                lib[i].push_back(temps);
            }
        }
    }
    /*for (int i = 0; i != 3; ++i)
        for (int j = 0; j != lib[i].size(); ++j)
            cout << lib[i][j] << endl;*/
    int k;
    cin >> k;
    for (int query = 0; query != k; ++query){
        int q[5] = {0};
        string ans = "";
        for (int i = 0; i != 5; ++i)
            cin >> q[i];

        if (q[0] > lib[0].size() || q[0] <=0){
            cout << none << endl;
            continue;
        }
        ans += lib[0][q[0] - 1];

        ans += "(";

        if (q[1] > lib[1].size() || q[1] <=0){
            cout << none << endl;
            continue;
        }
        ans += lib[1][q[1] - 1];

        if (q[2] > lib[2].size() || q[2] <=0){
            cout << none << endl;
            continue;
        }
        ans += lib[2][q[2] - 1];

        if (q[3] > lib[1].size() || q[3] <=0){
            cout << none << endl;
            continue;
        }
        ans += lib[1][q[3] - 1];

        ans += ")";

        if (q[4] > lib[0].size() || q[4] <=0){
            cout << none << endl;
            continue;
        }
        ans += lib[0][q[4] - 1];

        cout << ans << endl;
    }
    /*for (int i = 0; i != 3; ++i)
    {
        for (int j = 0; j != lib[i].size(); ++j){
            for (int k = 0; k != lib[i][j].size(); ++k)
                cout << int(lib[i][j][k]) << ' ';
            cout << endl;
        }
    }*/
    return 0;
}
