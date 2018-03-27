/* 高精度除法 */
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int MAXS = 10005;

int sub(int a[], int b[], int lena, int lenb, int shift = 0){
    if (lena < lenb + shift) return -1;
    if (lena == lenb + shift){
        for (int i = lenb; i >= 1; --i){
            if (a[i + shift] > b[i]) break;
            if (a[i + shift] < b[i]) return -1;
        }
    }
    for (int i = shift + 1; i <= lena; ++i){
        a[i] -= b[i - shift];
        if (a[i] < 0){
            a[i] += 10;
            --a[i + 1];
        }
    }
    for (int i = lena; i != 0; --i){
        if (a[i]) return i;
    }
    return 0;
}

int a[MAXS] = {0}, b[MAXS] = {0}, ans[MAXS] = {0};

int main(){
    string s1, s2;
    bool flag = 1;
    getline(cin ,s1);
    getline(cin, s2);
    while (s1.size() != 0 && s1[0] == '0') s1.erase(s1.begin());
    while (s2.size() != 0 && s2[0] == '0') s2.erase(s2.begin());
    int lena = s1.size(), lenb = s2.size();
    if (lena == 0){
    	printf("0\n");
    	return 0;
	}
    for (int i = 1; i <= lena; ++i)
        a[i] = s1[lena - i] - '0';
    for (int i = 1; i <= lenb; ++i)
        b[i] = s2[lenb - i] - '0';
    if (lena < lenb){
        printf("0\n");
        return 0;
    }
    int def = lena - lenb;
    int sublen = 0;
    for (int i = def; i >= 0; --i){
        while ((sublen = sub(a, b, lena, lenb, i)) >= 0){
            lena = sublen;
            ++ans[i + 1];
        }
    }
    int len = def + 1;
    while (len >= 1 && ans[len] == 0) --len;
    if (len > 0){
        for (int i = len; i != 0; --i) printf("%d", ans[i]);
    }
    else printf("0");
    return 0;
}
