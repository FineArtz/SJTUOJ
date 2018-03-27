/* ¾Ã×ÓµÄÍ¼ÕÂ */
#include <iostream>
#include <cstdio>
using namespace std;

class Point{
public:
    Point() : x(0), y(0) {}
    Point(int xx, int yy) : x(xx), y(yy) {};
    int x, y;
};

bool gra[1005][1005] = {0};
Point pic[1000000];

void solve(){
    int m, n, p, q;
    int cntg = 0;
    cin >> m >> n >> p >> q;
    for (int i = 1; i <= m; ++i)
    	for (int j = 1; j <= n; ++j){
    		scanf("%d", &gra[i][j]);
    		if (gra[i][j]) ++cntg;
    	}
    int t = 0, cntp = 0;
    for (int i = 1; i <= p; ++i)
    	for (int j = 1; j <= q; ++j){
    		scanf("%d", &t);
    		if (t == 1){
    			++cntp;
    			pic[cntp].x = i;
    			pic[cntp].y = j;
    		}
    	}
    /*if (cntg % cntp != 0){
    	cout << "No" << endl;
    	return;
    }
	if (m > 50 && n > 50){
		cout << "No" << endl;
		return;
	}*/
    for (int i = 1; i <= m; ++i){
    	for (int j = 1; j <= n; ++j){
    		if (gra[i][j]){
    			for (int l = 2; l <= cntp; ++l){
    				int nx = i + pic[l].x - pic[1].x, ny = j + pic[l].y - pic[1].y;
    				if (nx <= 0 || ny <= 0 || nx > m || ny > n){
    					printf("No\n");
    					return;
    				}
    				if (gra[nx][ny]) gra[nx][ny] = 0;
    				else{
    					printf("No\n");
    					return;
    				}
    			}
    		}
    	}
    }
    printf("Yes\n");
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i != t; ++i)
        solve();
    return 0;
}
