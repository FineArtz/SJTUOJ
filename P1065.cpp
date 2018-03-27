/* 小M的生物实验 */
#include <iostream>
#include <cstring>
using namespace std;

int f[1005][1005] = {0};
char s1[1005], s2[1005];

int main(){
    cin >> s1 >> s2;
    int l1 = strlen(s1), l2 = strlen(s2);
    for (int i = 0; i <= l1; ++i){
        for (int j = 0; j <= l2; ++j){
            if (i == 0 || j == 0)
                f[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i][j - 1], f[i - 1][j]);
        }
    }
    cout << f[l1][l2] << endl;
    return 0;
}
