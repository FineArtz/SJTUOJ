/* The Clocks */
#include <iostream>
using namespace std;

int a[10], ans[10] = {0}, t[10] = {0}, l = 40;
initializer_list<int> imp[10] = {
    {0},
    {1, 2, 4, 5},
    {1, 2, 3},
    {2, 3, 5, 6},
    {1, 4, 7},
    {2, 4, 5, 6, 8},
    {3, 6, 9},
    {4, 5, 7, 8},
    {7, 8, 9},
    {5, 6, 8, 9}};

inline void rotate(int a[10], int x, initializer_list<int> il){
    for (int i : il){
        a[i] = (a[i] + 3 * x) % 12;
    }
}

void work(int t[10]){
    int len = 0, b[10];
    for (int i = 1; i <= 9; ++i)
        b[i] = a[i];
    for (int i = 1; i <= 9; ++i){
        if (t[i])
            ++len;
        rotate(b, t[i], imp[i]);
    }
    for (int i = 1; i <= 9; ++i)
        if (b[i])
            return;
    if (len < l){
        l = len;
        for (int i = 1; i <= 9; ++i)
            ans[i] = t[i];
    }
}

int main(){
    for (int i = 1; i <= 9; ++i){
        cin >> a[i];
        a[i] %= 12;
    }
//    t[4] = t[5] = t[8] = t[9] = 1;
//    work(t);
    for (int i = 0; i < 262144; ++i){
        work(t);
        ++t[9];
        int j = 9;
        while (t[j] == 4){
            t[j] = 0;
            ++t[--j];
        }
    }
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= ans[i]; ++j)
            cout << i << ' ';
    cout << endl;
    return 0;
}
