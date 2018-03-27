/* Brackets Stack */
#include <iostream>
using namespace std;

char full[1000005], inco[1000005];
bool isco[1000005] = {0};
int n, fsize = 0, isize = 0;

bool isLeft(char ch){
    return (ch == '(' || ch == '[' || ch == '{');
}

char getRight(char ch){
    if (ch == '(') return ')';
    else if (ch == '[') return ']';
    else if (ch == '{') return '}';
    else return ' ';
}

char getLeft(char ch){
    if (ch == ')') return '(';
    else if (ch == ']') return '[';
    else if (ch == '}') return '{';
    else return ' ';
}

int main(){
    ios::sync_with_stdio(false);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--){
        int op;
        char ch;
        cin >> op;
        switch(op){
        case 1:
            cin >> ch;
            full[fsize++] = ch;
            if (isLeft(ch)){
                inco[isize++] = ch;
                isco[fsize - 1] = true;
            }
            else{
                if (isize != 0 && isLeft(inco[isize - 1]) && ch == getRight(inco[isize - 1])){
                    --isize;
                    isco[fsize - 1] = true;
                }
                else{
                    inco[isize++] = ch;
                    isco[fsize - 1] = false;
                }
            }
            break;
        case 2:
            if (fsize == 0)
                break;
            ch = full[fsize - 1];
            if (isLeft(ch))
                --isize;
            else{
                if (isco[fsize - 1])
                    inco[isize++] = getLeft(ch);
                else
                    --isize;
            }
            --fsize;
            break;
        case 3:
            if (fsize != 0)
                cout << full[fsize - 1] << '\n';
            break;
        case 4:
            if (isize)
                cout << "NO\n";
            else
                cout << "YES\n";
            break;
        }
    }
    return 0;
}
