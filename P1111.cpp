/* 二哥学二叉树 */
#include <iostream>
#include <cstring>
using namespace std;

char a[1005];
char dlr[30], ldr[30];

void restoreTree(char *dlr, char *ldr, int len, int root){
    if (len <= 0)
        return;
    char r = dlr[0];
    a[root] = r;
    int i = 0;
    while (ldr[i] != r)
        ++i;
    restoreTree(dlr + 1, ldr, i, root * 2);
    restoreTree(dlr + i + 1, ldr + i + 1, len - i - 1, root * 2 + 1);
}

int main(){
    cin >> dlr >> ldr;
    for (int i = 1; i <= 1004; ++i)
        a[i] = ' ';
    restoreTree(dlr, ldr, strlen(dlr), 1);
    int n = 1000;
    while (a[n] == ' ')
        --n;
    for (int i = 1; i <= n; ++i){
        if (a[i] == ' ')
            cout << "NULL ";
        else
            cout << a[i] << ' ';
    }
    cout << endl;
    return 0;
}
