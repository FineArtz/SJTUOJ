/* Gap */
#include <iostream>
#include <cmath>
using namespace std;

bool isp(const int &x){
    if (x == 2) return true;
    for (int i = 2; i <= trunc(sqrt(x)) + 1; ++i)
        if (x % i == 0) return false;
    return true;
}

int main(){
    int n;
    cin >> n;
    int LowerBound = n, UpperBound = n;
    while (!isp(LowerBound)) --LowerBound;
    while (!isp(UpperBound)) ++UpperBound;
    cout << UpperBound - LowerBound << endl;
    return 0;
}
