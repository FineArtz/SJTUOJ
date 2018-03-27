/* ÊýÊý */
#include <iostream>
using namespace std;

int main(){
   int n, ans = 0;
   cin >> n;
   for (int i = 1; i <= n; ++i){
      int a = 0;
      cin >> a;
      while (a > 0){
         if (a % 2) ++ans;
         a /= 2;
      }
   }
   cout << ans << endl;
   return 0;
}
