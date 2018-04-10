/* Watashi kininarimasu! */
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAXN = 200000;

struct Node{
	int l = 0, r = 0;
	int maxx = 0;
};

Node a[MAXN * 4 + 5];

int t;
int h, w, n;

void pushUp(int x){
	if (a[x * 2].maxx >= a[x * 2 + 1].maxx)
		a[x].maxx = a[x * 2].maxx;
	else
		a[x].maxx = a[x * 2 + 1].maxx;
}

void buildTree(int x, int l, int r){
	a[x].l = l;
	a[x].r = r;
	if (l == r){
		a[x].maxx = w;
		return;
	}
	int mid = (l + r) / 2;
	buildTree(x * 2, l, mid);
	buildTree(x * 2 + 1, mid + 1, r);
	pushUp(x);
}

void update(int x, int line, int len){
	if (a[x].l == a[x].r){
		a[x].maxx -= len;
		return;
	}
	int mid = (a[x].l + a[x].r) / 2;
	if (line <= mid)
		update(x * 2, line, len);
	else
		update(x * 2 + 1, line, len);
	pushUp(x);
}

int query(int x, int len){
	if (a[x].l == a[x].r)
		return a[x].l;
	if (a[x * 2].maxx >= len)
		return query(x * 2, len);
	else
		return query(x * 2 + 1, len);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--){
		cin >> h >> w >> n;
		buildTree(1, 1, min(n, h));
		for (int i = 1; i <= n; ++i){
			int m;
			cin >> m;
			if (m > a[1].maxx){
				cout << "-1\n";
				continue;
			}
			int line = query(1, m);
			cout << line << '\n';
			update(1, line, m);
		}
	}
	return 0;
}
