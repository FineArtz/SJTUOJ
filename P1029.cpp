/* 整理书架 */
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> book;
    string ss;
    getline(cin, ss);
    for (int i = 1; i <= n ; ++i){
        string st;
        getline(cin, st);
        istringstream iss(st);
        int t;
        vector<int> tv;
        while (iss >> t)
            tv.push_back(t);
        book.push_back(tv);
    }
    for (int i = 1; i < n; ++i){
        int x, y;
        cin >> x >> y;
        book[y - 1].insert(book[y - 1].end(), book[x - 1].begin(), book[x - 1].end());
        book[x - 1].clear();
    }
    for (int i = n - 1; i >= 0; --i){
        if (!book[i].empty()){
            for (auto j : book[i]){
                cout << j << ' ';
            }
            cout << endl;
            return 0;
        }
    }
    return 0;
}
