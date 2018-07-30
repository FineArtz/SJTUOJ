/* Water Problem */
#include <iostream>
#include <cstring>
using namespace std;

int t;
char s[205];
int isSublist[205][205];

inline bool readSet(const char *, int, int);
inline bool readElementSublist(const char *, int, int);
inline bool readElement(const char *, int, int);
inline bool readSubelement(const char *, int, int);

inline bool readSet(const char *s, int first, int last){
    if (s[first] != '{' || s[last - 1] != '}')
        return false;
    if (last - first == 2)
        return true;
    return readElementSublist(s, first + 1, last - 1);
}

inline bool readElementSublist(const char *s, int first, int last){
    if (isSublist[first][last] == 1)
        return true;
    if (isSublist[first][last] == -1)
        return false;
    for (int i = first; i < last; ++i){
        if (s[i] != ',')
            continue;
        if (readElement(s, first, i) && readElementSublist(s, i + 1, last))
            return true;
    }
    bool flag = readElement(s, first, last);
    if (flag)
        isSublist[first][last] = 1;
    else
        isSublist[first][last] = -1;
    return flag;
}

inline bool readElement(const char *s, int first, int last){
    if (last - first == 1){
        if (s[first] == '{' || s[first] == '}' || s[first] == ',')
            return true;
        else
            return false;
    }
    return readSet(s, first, last);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for (int i = 1; i <= t; ++i){
        cin >> s;
        int len = strlen(s);
        memset(isSublist, 0, sizeof(isSublist));
        if (readSet(s, 0, len))
            cout << "Word #" << i << ": Set\n";
        else
            cout << "Word #" << i << ": No Set\n";
    }
    return 0;
}
