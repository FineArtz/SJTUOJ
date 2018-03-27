/* STL-algorithm */
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, m, tmp;
    scanf("%d%d", &n, &m);
    vector<int> v;
    //cin >> n >> m;
    for (int i = 0; i < n; ++i){
        scanf("%d", &tmp);
        //cin >> tmp;
        v.push_back(tmp);
    }
    while (m--){
        int t, i, j, a, b, c;
        int ans;
        vector<int>::iterator ite = v.begin();
        scanf("%d%d%d", &t, &i, &j);
        switch(t){
            case 1:
                sort(v.begin() + i, v.begin() + j);
                break;
            case 2:
                reverse(v.begin() + i, v.begin() + j);
                break;
            case 3:
                for (auto it = v.begin() + i; it != v.begin() + j; ++it)
                    printf("%d ", *it);
                    //cout << *it << ' ';
                printf("\n");
                //cout << endl;
                break;
            case 4:
                ans = *min_element(v.begin() + i, v.begin() + j);
                printf("%d\n", ans);
                //cout << *minn << endl;
                break;
            case 5:
                scanf("%d", &a);
                //cin >> a;
                ans = count_if(v.begin() + i, v.begin() + j, [a](int x){return x > a;});
                printf("%d\n", ans);
                //cout << ans << endl;
                break;
            case 6:
                scanf("%d", &a);
                ite = find(v.begin() + i, v.begin() + j, a);
                ans = distance(v.begin(), ite);
                printf("%d\n", ans);
                //cout << ans << endl;
                break;
            case 7:
                scanf("%d%d", &a, &b);
                //cin >> a >> b;
                replace(v.begin() + i, v.begin() + j, a, b);
                break;
            case 8:
                scanf("%d%d%d", &a, &b, &c);
                stable_partition(v.begin() + i, v.begin() + j, [a, b, c](int x){return a * x * x + b * x + c > 0;});
                break;
            default:
                break;
        }
    }
    return 0;
}
