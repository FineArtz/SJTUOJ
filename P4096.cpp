/* 小居居搬箱子 */
#include <iostream>
#include <cstring>
using namespace std;

int a[26][26] = {0};
int place[26] = {0}, sum[26] = {0};
int n;

void remove(int x){
    int p = place[x];
    int i = 1;
    while (a[p][i] != x)
        ++i;
    for (int j = i + 1; j <= sum[p]; ++j){
        int t = a[p][j];
        a[t][1] = t;
        place[t] = t;
        sum[t] = 1;
        a[p][j] = 0;
    }
    sum[p] = i;
}

void moveover(int x, int y){
    int p = place[x], q = place[y];
    remove(x);
    a[q][++sum[q]] = x;
    a[p][sum[p]--] = 0;
    place[x] = q;
}

void moveonto(int x, int y){
    int p = place[x], q = place[y];
    remove(x);
    remove(y);
    a[q][++sum[q]] = x;
    a[p][sum[p]--] = 0;
    place[x] = q;
}

void pileover(int x, int y){
    int p = place[x], q = place[y];
    int i = 1;
    while (a[p][i] != x)
        ++i;
    for (int j = i; j <= sum[p]; ++j){
        a[q][++sum[q]] = a[p][j];
        place[a[p][j]] = q;
        a[p][j] = 0;
    }
    sum[p] = i - 1;
}

void pileonto(int x, int y){
    int p = place[x], q = place[y];
    remove(y);
    int i = 1;
    while (a[p][i] != x)
        ++i;
    for (int j = i; j <= sum[p]; ++j){
        a[q][++sum[q]] = a[p][j];
        place[a[p][j]] = q;
        a[p][j] = 0;
    }
    sum[p] = i - 1;
}

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        a[i][1] = i;
        place[i] = i;
        sum[i] = 1;
    }
    char s1[10], s2[10];
    int x, y;
    cin >> s1;
    while (s1[0] != 'q'){
        cin >> x >> s2 >> y;
        ++x, ++y;
        if (place[x] == place[y]){
            cin >> s1;
            continue;
        }
        if (s1[0] == 'm'){
            if (s2[1] == 'v')
                moveover(x, y);
            else
                moveonto(x, y);
        }
        else{
            if (s2[1] == 'v')
                pileover(x, y);
            else
                pileonto(x, y);
        }
        cin >> s1;
    }
    for (int i = 0; i < n; ++i){
        cout << i << ":";
        for (int j = 1; j <= sum[i + 1]; ++j)
            cout << ' ' << a[i + 1][j] - 1;
        cout << endl;
    }
    return 0;
}
