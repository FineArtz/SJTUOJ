/* Interesting Island */
#include <iostream>
#include <cstring>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m;
char a[55][55];
bool v[55][55], isol = true;

void floodfill(int x, int y){
    v[x][y] = true;
    for (int k = 0; k < 4; ++k){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#' && !v[nx][ny])
            floodfill(nx, ny);
    }
}

void checkfill(int x, int y){
    if (a[x][y] == '.'){
        isol = false;
        return;
    }
    v[x][y] = true;
    for (int k = 0; k < 4; ++k){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] != '#' && !v[nx][ny])
            checkfill(nx, ny);
        if (!isol)
            return;
    }
}

void realfill(int x, int y){
    v[x][y] = true;
    a[x][y] = '#';
    for (int k = 0; k < 4; ++k){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && a[nx][ny] == '?' && !v[nx][ny])
            realfill(nx, ny);
    }
}

bool check(){
    bool flag = true;
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == '.'){
                floodfill(i, j);
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == '.' && !v[i][j])
                return false;
        }
    }
    return true;
}

void checkIso(int i, int j){
    isol = true;
    memset(v, 0, sizeof(v));
    checkfill(i, j);
    if (isol){
        memset(v, 0, sizeof(v));
        realfill(i, j);
    }
}

int main(){
    bool flag = false;
    int cnt = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            if (a[i][j] == '.')
                flag = true;
            if (a[i][j] == '?')
                ++cnt;
        }
    }
    if (!flag){
        if (cnt >= 2){
            cout << "Ambiguous" << endl;
            return 0;
        }
        else if (cnt == 0){
            cout << "Impossible" << endl;
            return 0;
        }
        else{
            for (int i = 1; i <= n; ++i){
                for (int j = 1; j <= m; ++j){
                    if (a[i][j] == '?')
                        cout << '.';
                    else
                        cout << a[i][j];
                }
                cout << endl;
            }
            return 0;
        }
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j] == '?'){
                checkIso(i, j);
                if (a[i][j] != '?')
                    continue;
                bool flag1 = false, flag2 = false;
                a[i][j] = '.';
                flag1 = check();
                a[i][j] = '#';
                flag2 = check();
                if (flag1 && flag2){
                    cout << "Ambiguous" << endl;
                    return 0;
                }
                if (!flag1 && !flag2){
                    cout << "Impossible" << endl;
                    return 0;
                }
                a[i][j] = '.';
            }
        }
    }
    bool imp = true;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == '.'){
                imp = false;
                break;
            }
    if (imp){
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j)
            cout << a[i][j];
        cout << endl;
    }
    return 0;
}
