/* mushroom */
#include <iostream>
using namespace std;

int main(){
    int f[1005] = {0};
    int T, M;
    cin >> T >> M;
    int t[105], w[105];
    for (int i = 1; i <= M; ++i)
        cin >> t[i] >> w[i];
    for (int i = 1; i <= M; ++i){
        for (int j = T; j >= t[i]; --j)
            f[j] = max(f[j], f[j - t[i]] + w[i]);
    }
    cout << f[T] << endl;
    return 0;
}
