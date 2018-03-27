/* STL-map/pq */
#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

int main(){
    int n, t, x, y;
    scanf("%d", &n);
    //cin >> n;
    map<int, priority_queue<int>> apple;
    while (n--){
        scanf("%d", &t);
        //cin >> t;
        switch(t){
            case 1:
                scanf("%d%d", &x, &y);
                //cin >> x >> y;
                apple[x].push(y);
                break;
            case 2:
                scanf("%d", &x);
                //cin >> x;
                apple[x].pop();
                break;
            case 3:
                scanf("%d", &x);
                //cin >> x;
                printf("%d\n", apple[x].top());
                //cout << apple[x].top() << endl;
                break;
            default:
                break;
        }
    }
    return 0;
}
