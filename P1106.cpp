#include <iostream>
#include <cstring>
using namespace std;

const int MAXNODE = 2000005, MAXN = 1050;
const int SLOT = 0, ROW = 1, COL = 2, SUB = 3;

class DancingLink{
private:
    int n, m;
    int U[MAXNODE], D[MAXNODE], L[MAXNODE], R[MAXNODE];
    int row[MAXNODE], col[MAXNODE];
    int head[MAXN], sum[MAXN];
    int ansd, size;

public:
    int solution;

    void init(int n = 0, int m = 0){
        this->n = n;
        this->m = m;
        size = m + 1;
        solution = 0;
        memset(sum, 0, sizeof(sum));
        memset(head, -1, sizeof(head));
        for (int i = 0; i <= m; ++i){
            L[i] = i - 1;
            R[i] = i + 1;
            U[i] = i;
            D[i] = i;
        }
        L[0] = m;
        R[m] = 0;
    }

    void addNode(int r, int c){
        row[size] = r;
        col[size] = c;
        U[size] = U[c];
        D[size] = c;
        U[D[size]] = size;
        D[U[size]] = size;
        if (head[r] == -1){ //empty row
            L[size] = size;
            R[size] = size;
            head[r] = size;
        }
        else{
            L[size] = L[head[r]];
            R[size] = head[r];
            L[R[size]] = size;
            R[L[size]] = size;
        }
        ++sum[col[size++]];
    }

    void delNode(int x){
        R[L[x]] = R[x];
        L[R[x]] = L[x];
        for (int i = D[x]; i != x; i = D[i]){
            for (int j = R[i]; j != i; j = R[j]){
                U[D[j]] = U[j];
                D[U[j]] = D[j];
                --sum[col[j]];
            }
        }
    }

    void resNode(int x){
        for (int i = U[x]; i != x; i = U[i]){
            for (int j = L[i]; j != i; j = L[j]){
                U[D[j]] = j;
                D[U[j]] = j;
                ++sum[col[j]];
            }
        }
        R[L[x]] = x;
        L[R[x]] = x;
    }

    void dfs(int depth){
        if (R[0] == 0){
            ++solution;
            return;
        }
        int x = R[0];
        for (int i = R[0]; i != 0; i = R[i]){
            if (sum[x] > sum[i])
                x = i;
        }
        delNode(x);
        for (int i = D[x]; i != x; i = D[i]){
            for (int j = R[i]; j != i; j = R[j])
                delNode(col[j]);
            dfs(depth + 1);
            if (solution >= 2)
                return;
            for (int j = L[i]; j != i; j = L[j])
                resNode(col[j]);
        }
        resNode(x);
    }
};

inline int encode(int x, int y, int z){
    return 81 * x + 9 * y + z + 1;
}

inline void decode(int code, int &x, int &y, int &z){
    --code;
    z = code % 9;
    code /= 9;
    y = code % 9;
    code /= 9;
    x = code % 9;
}

DancingLink dlx;
void solve(){
    int a[9][9];
    dlx.init(9 * 9 * 9, 9 * 9 * 4);
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> a[i][j];
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j){
            for (int k = 0; k < 9; ++k){
                if (a[i][j] == 0 || a[i][j] == k + 1){
                    int x = encode(i, j, k);
                    dlx.addNode(x, encode(0, i, j));
                    dlx.addNode(x, encode(1, i, k));
                    dlx.addNode(x, encode(2, j, k));
                    dlx.addNode(x, encode(3, i / 3 * 3 + j / 3, k));
                }
            }
        }
    }
    dlx.dfs(0);
    if (dlx.solution == 1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
