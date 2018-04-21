/* labyrinth */
#include <iostream>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Node{
    int x = 0, y = 0, step = 0;
};

char ch;
char a[1005][1005];
bool b[1005][1005] = {false};
int n, m;
int sx, sy;
Node q[1000005];
int front = 0, rear = 0;

void bfs(){
    Node s;
    s.x = sx;
    s.y = sy;
    q[rear++] = s;
    b[sx][sy] = true;
    while (front != rear){
        Node now = q[front];
        ++front;
        for (int k = 0; k < 4; ++k){
            int nx = now.x + dx[k];
            int ny = now.y + dy[k];
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && !b[nx][ny]){
                Node next;
                next.x = nx;
                next.y = ny;
                next.step = now.step + 1;
                if (a[nx][ny] == '$'){
                    cout << next.step << endl;
                    return;
                }
                b[nx][ny] = true;
                q[rear++] = next;
            }
        }
    }
    cout << "-1" << endl;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
            if (a[i][j] == '@'){
                sx = i;
                sy = j;
            }
            else if (a[i][j] == '#'){
                b[i][j] = true;
            }
        }
    }
    bfs();
    return 0;
}
