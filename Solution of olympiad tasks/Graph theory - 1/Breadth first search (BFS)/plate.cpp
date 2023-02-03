#include<iostream>
#include<vector>
#include<queue>
int res[100][100];
using namespace std;
int main(){
    int n, m, x;
    cin >> n >> m;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};
    queue<pair<int, int> > b;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++){
            cin >> x;
            if(x == 1)
                b.push({i, j});
            else
                res[i][j] = -1;   
            }
    while(!b.empty()){
        int x = b.front().first, y = b.front().second;
        b.pop();
        for(int q=0, X, Y; q<4; q++){
            X = x + dx[q];
            Y = y + dy[q];
            if(X < 0 || X >= n || Y < 0 || Y >= m || res[X][Y] != -1) continue;
            b.push({X, Y});
            res[X][Y] = res[x][y] + 1;
        }
    }
    for(int i=0; i < n; i++)
        for(int j=0; j<m; j++)
            cout << res[i][j] << " \n"[j == m-1];
    return 0;
}