/* 日天部落 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

class Point{
public:
    int x = 0;
    int y = 0;
};
bool cmp(Point p1, Point p2){
    return (p1.x < p2.x || p1.x == p2.x && p1.y < p2.y);
}

Point p[150005], pos[150005];
bool v[150005] = {0};
int n, m;

bool bfs(int st){
    queue<int> q;
    q.push(st);
    v[st] = true;
    int now, next;
    int person = 1, battle = 0;
    while (!q.empty()){
        now = q.front();
        q.pop();
        for (int k = pos[now].x; k <= pos[now].y; ++k){
        	if (k == 0) break;
            next = p[k].y;
            ++battle;
            if (v[next]) continue;
            ++person;
            q.push(next);
            v[next] = true;
        }
    }
    return (battle == person * (person - 1) / 2);
}
int main(){
    cin >> n >> m;
    memset(v, 0, sizeof(v));
    for (int i = 1; i <= m; ++i){
        cin >> p[i].x >> p[i].y;
        if (p[i].x > p[i].y){
            int t = p[i].x;
            p[i].x = p[i].y;
            p[i].y = t;
        }
    }
    sort(p + 1, p + m + 1, cmp);
    pos[p[1].x].x = 1;
    for (int i = 2; i <= m; ++i){
        if (p[i].x != p[i - 1].x){
            pos[p[i - 1].x].y = i - 1;
            pos[p[i].x].x = i;
        }
    }
    pos[p[m].x].y = m;
    for (int i = 1; i <= m; ++i){
        if (!v[i]){
            bool flag = bfs(i);
            if (!flag){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
