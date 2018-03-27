/* ¶þ¸çÑøÏ¸¾ú */
#include <iostream>
#include <deque>
using namespace std;

int a[105][105], l;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int bfs(){
    int ans = 0;
    deque<int> nowx, nowy;
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= l; ++j)
            if (a[i][j] == 1){
                nowx.push_back(i);
                nowy.push_back(j);
            }
    while (!nowx.empty()){
        ++ans;
        int len = nowx.size();
        for (int nowc = 0; nowc < len; ++nowc){
            for (int d = 0; d < 4; ++d){
                int x = nowx[nowc] + dx[d];
                int y = nowy[nowc] + dy[d];
                if (a[x][y] == 0){
                    a[x][y] = 1;
                    nowx.push_back(x);
                    nowy.push_back(y);
                }
            }
        }
        for (int i = 1; i <= len; ++i){
            nowx.pop_front();
            nowy.pop_front();
        }
    }
    return ans - 1;
}
int main(){
    cin >> l;
    for (int i = 0; i <= 104; ++i)
        for (int j = 0; j <= 104; ++j)
            a[i][j] = 2;
    for (int i = 1; i <= l; ++i)
        for (int j = 1; j <= l; ++j)
            cin >> a[i][j];
    cout << bfs() << endl;
    return 0;
}
