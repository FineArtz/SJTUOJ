/* game */
#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << (1 << (n - 1)) << endl;
    }
    return 0;
}
