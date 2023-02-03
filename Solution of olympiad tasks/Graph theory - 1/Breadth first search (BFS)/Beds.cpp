#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    int n, m, cnt=0;
    cin >> n >> m;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {-1, 1, 0, 0};
    queue<pair<int, int> > b;
    vector<string> g(n);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> g[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(g[i][j] == '#'){
                cnt ++;
                b.push({i, j});
                while(!b.empty()){
                    int x = b.front().first, y = b.front().second;
                    b.pop();
                    for(int u=0, X, Y; u<4; u++){
                        X = x + dx[u];
                        Y = y + dy[u];
                        if(X < 0 || X >= n || Y < 0 || Y >= m) continue;
                        if(g[X][Y] != '#') continue;
                        g[X][Y] = '.';
                        b.push({X, Y});
                    }
                }
            }
        }
    cout << cnt;
}