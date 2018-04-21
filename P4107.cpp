/* Love and Auto Memories Doll II */
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXS = 10000000;

char a[MAXS + 5], b[MAXS + 5];
int nxt[MAXS + 5] = {0};
int lena = 0, lenb = 0;

inline void lowercase(char &ch){
    if (ch >= 'A' && ch <= 'Z')
        ch = ch - 'A' + 'a';
}

int main(){
	fgets(a, MAXS + 5, stdin);
	fgets(b, MAXS + 5, stdin);
	lena = strlen(a) - 1;
	lenb = strlen(b);
	for (int i = 0; i < lena; ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            a[i] = a[i] - 'A' + 'a';
    for (int i = 0; i < lenb; ++i)
        if (b[i] >= 'A' && b[i] <= 'Z')
            b[i] = b[i] - 'A' + 'a';
	int pos = -1, ans = 0;
	nxt[0] = -1;
	int t = -1;
    for (int i = 1; i < lena; ++i){
        while (t > -1 && a[i] != a[t + 1])
            t = nxt[t];
        if (a[i] == a[t + 1])
            ++t;
        nxt[i] = t;
    }
    t = -1;
    for (int i = 0; i < lenb; ++i){
        while (t > -1 && a[t + 1] != b[i])
            t = nxt[t];
        if (a[t + 1] == b[i])
            ++t;
        if (t == lena - 1){
            if (ans == 0)
                pos = i - lena + 1;
            ++ans;
            t = nxt[t];
        }
    }
	if (ans == 0)
		cout << "-1" << '\n';
	else
		cout << ans << ' ' << pos << '\n';
	return 0;
}
