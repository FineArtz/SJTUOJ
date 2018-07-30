/* Welcome to the Aperture Science */
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int n, m, N, M;
int a[500005], b[710][1400], c[710][1400];

inline int query(int x){
    int p = x / N, q = x - p * N;
    int ret = 0;
    for (int i = p; i < M; ++i){
        ret += c[i][q];
        q = b[i][q];
    }
    if (n % M != 0){
        ret += c[M][q];
    }
    return ret;
}

inline void update(int x, int y){
    int p = x / N, q = x - p * N;
    a[x] = y;
    int st = p * N, ed = st + N;
    if (p != M){
        for (int j = q; j >= 0; --j){
            if (j + a[st + j] >= N){
                b[p][j] = j + a[st + j] - N;
                c[p][j] = 1;
            }
            else{
                b[p][j] = b[p][j + a[st + j]];
                c[p][j] = c[p][j + a[st + j]] + 1;
            }
        }
    }
    else{
        for (int j = q; j >= 0; --j){
            if (j + st >= n)
                continue;
            if (j + a[st + j] >= n - st){
                b[p][j] = j + a[st + j] - n + st;
                c[p][j] = 1;
            }
            else{
                b[p][j] = b[p][j + a[st + j]];
                c[p][j] = c[p][j + a[st + j]] + 1;
            }
        }
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    N = sqrt(n);
    M = n / N;
    for (int i = 0; i < M; ++i){
        int st = i * N, ed = st + N;
        for (int j = N - 1; j >= 0; --j){
            if (j + st >= n)
                continue;
            if (j + a[st + j] >= N){
                b[i][j] = j + a[st + j] - N;
                c[i][j] = 1;
            }
            else{
                b[i][j] = b[i][j + a[st + j]];
                c[i][j] = c[i][j + a[st + j]] + 1;
            }
        }
    }
    if (n % M != 0){
        int st = N * M, ed = st + N;
        for (int j = N - 1; j >= 0; --j){
            if (j + st >= n)
                continue;
            if (j + a[st + j] >= n - st){
                b[M][j] = j + a[st + j] - n + st;
                c[M][j] = 1;
            }
            else{
                b[M][j] = b[M][j + a[st + j]];
                c[M][j] = c[M][j + a[st + j]] + 1;
            }
        }
    }
    scanf("%d", &m);
    while (m--){
        int op, u, v;
        scanf("%d", &op);
        if (op == 1){
            scanf("%d", &u);
            printf("%d\n", query(u));
        }
        else{
            scanf("%d%d", &u, &v);
            update(u, v);
        }
    }
    return 0;
}