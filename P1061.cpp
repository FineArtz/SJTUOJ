/* 小M的服务器 */
#include <iostream>
using namespace std;

const long long INF = 131313131313131313LL;

long long f[1000005], c[1000005];
long long q[1000005], front = 1, rear = 1;

inline double g(long long j, long long k){
    return (2 * (f[j] - f[k]) + j * (j - 1) - k * (k - 1)) * 0.5 / (j - k);
}

int main(){
    int n;
    cin >> n;
    c[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    f[n] = c[n];
    q[front] = n;
    for (int i = n - 1; i >= 0; --i){
        while (front < rear && g(q[front], q[front + 1]) > i)
            ++front;
        f[i] = f[q[front]] + (q[front] - i) * (q[front] - i - 1) / 2 + c[i];
        while (front < rear && g(q[rear - 1], q[rear]) < g(q[rear], i))
            --rear;
        q[++rear] = i;
    }
    cout << f[0] << endl;
    return 0;
}
