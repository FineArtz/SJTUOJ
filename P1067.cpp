/* Dividing */
#include <iostream>
using namespace std;

bool work(int *a){
    int v = 0;
    bool ret;
    for (int i = 1; i <= 6; ++i){
        v += a[i] * i;
    }
    if (v % 2)
        return false;
    v /= 2;
    int *f[7];
    for (int i = 0; i <= 6; ++i)
        f[i] = new int[v + 1];
    f[0][0] = 0;
    for (int i = 1; i <= v; ++i)
        f[0][i] = -1;
    for (int i = 1; i <= 6; ++i){
        for (int j = 0; j <= v; ++j){
            if (f[i - 1][j] >= 0)
                f[i][j] = a[i];
            else
                f[i][j] = -1;
        }
        for (int j = 0; j <= v - i; ++j){
            if (f[i][j] > 0){
                f[i][j + i] = max(f[i][j + i], f[i][j] - 1);
            }
        }
    }
    if (f[6][v] != -1)
        ret = true;
    else
        ret = false;
    for (int i = 0; i <= 6; ++i)
        delete [] f[i];
    return ret;
}

int main(){
    int n[7], t = 0;
    bool eof = true;
    for (int i = 1; i <= 6; ++i){
        cin >> n[i];
        if (n[i]) eof = false;
    }
    while (!eof){
        ++t;
        bool flag = work(n);
        cout << "Collection #" << t << ": \n";
        if (flag)
            cout << "Can be divided.\n\n";
        else
            cout << "Can't be divided.\n\n";
        eof = true;
        for (int i = 1; i <= 6; ++i){
            cin >> n[i];
            if (n[i]) eof = false;
        }
    }
    return 0;
}
