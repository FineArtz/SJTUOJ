/* 千岛樱 */
#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int sub = 0;
    int father = 0;
    vector<int> child;
};

Node a[500005];
bool sa[500005] = {0};
int n, k;
long long ans = 0;

void makeTree(int x){
    if (sa[x]) a[x].sub = 1;
    for (auto i : a[x].child){
        if (i != a[x].father){
            a[i].father = x;
            makeTree(i);
            a[x].sub += a[i].sub;
        }
    }
    return;
}
void countDis(int x){
    for (auto i : a[x].child){
        if (i != a[x].father){
            ans += min(a[i].sub, 2 * k - a[i].sub);
            countDis(i);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= 2 * k; ++i){
        int x;
        cin >> x;
        sa[x] = true;
    }
    for (int i = 1; i <= n - 1; ++i){
        int x, y;
        cin >> x >> y;
        a[x].child.push_back(y);
        a[y].child.push_back(x);
    }
    makeTree(1);
    countDis(1);
    cout << ans << endl;
    return 0;
}
