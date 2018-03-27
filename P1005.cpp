/* Êý¶À */
#include <iostream>
using namespace std;

inline short WhichBlock(int x, int y){
    if (x <= 3){
        if (y <= 3) return 1;
        if (y <= 6) return 2;
        if (y <= 9) return 3;
    }
    if (x <= 6){
        if (y <= 3) return 4;
        if (y <= 6) return 5;
        if (y <= 9) return 6;
    }
    if (x <= 9){
        if (y <= 3) return 7;
        if (y <= 6) return 8;
        if (y <= 9) return 9;
    }
}
int main(){
    int k;
    cin >> k;
    for (int data = 0; data != k; ++data){
        bool line[10][10] = {0}, row[10][10] = {0}, block[10][10] = {0}, flag = 1;
        short num = 0;
        for (int i = 0; i != 9; ++i){
            for (int j = 0; j != 9; ++j){
                cin >> num;
                if (line[i][num] || row[j][num] || block[WhichBlock(i + 1, j + 1)][num]){
                    flag = 0;
                    //break;
                }
                line[i][num] = row[j][num] = block[WhichBlock(i + 1, j + 1)][num] = 1;
            }
            //if (!flag) break;
        }
        if (flag) cout << "Right" << endl;
        else cout << "Wrong" << endl;
    }
    return 0;
}
