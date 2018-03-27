/* ¶ş¸çÕªÆ»¹û */
#include <iostream>
using namespace std;

int main(){
   int h, l, n;
   cin >> h >> l >> n;
   int sum = 0;
   for (int i = 1; i <= n; ++i){
      int t;
      cin >> t;
      if (h + l >= t) ++sum;
   }
   cout << sum << endl;
   return 0;
}
