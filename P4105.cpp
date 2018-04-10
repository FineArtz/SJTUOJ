/* difference */
#include <iostream>
#include <cmath>
using namespace std;

struct Heap{
	int heapsize = 0;
	int a[200005] = {0};

	void swap(int x, int y){
		int t = a[x];
		a[x] = a[y];
		a[y] = t;
	}

	void siftup(int x){
		while (x != 1){
			if (a[x] < a[x >> 1]){
				swap(x, x >> 1);
				x >>= 1;
			}
			else
				break;
		}
	}

	void siftdown(){
		int i = 2;
		while (i <= heapsize){
			if (i + 1 <= heapsize && a[i] > a[i + 1])
				++i;
			if (a[i >> 1] > a[i]){
				swap(i, i >> 1);
				i <<= 1;
			}
			else
				break;
		}
	}

	void insert(int x){
		a[++heapsize] = x;
		siftup(heapsize);
	}

	void pop(){
		swap(1, heapsize);
		--heapsize;
		siftdown();
	}

	int top(){
		return a[1];
	}
};

int n, m;
Heap heap;
int a[200005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i){
		int t;
		cin >> t;
		heap.insert(t);
	}
	for (int i = 1; i <= n; ++i){
		a[i] = heap.top();
		//cout << a[i] << endl;
		heap.pop();
	}

	while (m--){
		int q;
		cin >> q;
		int l = 1, r = n, mid;
		while (l <= r){
			mid = (l + r) / 2;
			if (a[mid] == q)
				break;
			if (a[mid] > q)
				r = mid - 1;
			else
				l = mid + 1;
		}
		int ans = abs(q - a[mid]);
		if (mid > 1){
			ans = min(ans, abs(q - a[mid - 1]));
		}
		if (mid < n){
			ans = min(ans, abs(q - a[mid + 1]));
		}
		cout << ans << '\n';
	}
	return 0;
}
