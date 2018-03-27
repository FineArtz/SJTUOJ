/* 二哥的家族 */
#include <iostream>
using namespace std;

bool b[200005] = {0};
int father[200005] = {0}, son[200005] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, cnt = 1;
    cin >> n;
    b[1] = true;
    while (n--){
        char ch;
        cin >> ch;
        if (ch == 'B'){
            int x, y;
            cin >> x >> y;
            father[y] = x;
            ++son[x];
            b[y] = true;
        }
        else if (ch == 'D'){
            int x;
            cin >> x;
            if (b[father[x]]){
                cnt += son[x];
                --son[father[x]];
            }
            else
                cnt += son[x] - 1;
            b[x] = false;
            son[x] = 0;
            cout << cnt << '\n';
        }
    }
    return 0;
}
