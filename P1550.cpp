/* 留下的水 */
#include <iostream>
#include <cstring>
using namespace std;

int n;
char ch;
int a[1005] = {0}, maxx = 0, ans = 0;

int main(){
    cin >> n;
    int num = 0, cnt = 0;
    bool flag = false;
    while (cin >> ch){
        if (!isdigit(ch)){
            if (flag){
                a[++cnt] = num;
                if (num > maxx)
                    maxx = num;
                num = 0;
                flag = false;
            }
            continue;
        }
        flag = true;
        num = num * 10 + ch - '0';
    }
    int l = 1, r = n;
    for (int h = 1; h <= maxx; ++h){
        while (a[l] < h)
            ++l;
        while (a[r] < h)
            --r;
        for (int i = l; i <= r; ++i)
            if (a[i] < h)
                ++ans;
    }
    cout << ans << endl;
    return 0;
}
