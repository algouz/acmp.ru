#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s1, x1;
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    queue<pair<int, int> > b;
    int whole=0, downed=0, destroyed = 0;
    cin >> n >> m;
    vector<string > g(n);
    for(int i=0; i<n; i++)
        cin >> g[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(g[i][j] != '-'){
                s1 = 0;
                x1 = 0;
                if(g[i][j] == 'S') s1++;
                else x1 ++;
                g[i][j] = '-';
                b.push({i, j});
                while(!b.empty()){
                    int x = b.front().first, y = b.front().second;
                    b.pop();
                    for(int u=0, X, Y; u<4; u++){
                        X = x + dx[u];
                        Y = y + dy[u];
                        if(X < 0 || X >= n || Y < 0 || Y >= m || g[X][Y] == '-') continue;
                        if(g[X][Y] == 'S') s1++;
                        else x1++;
                        g[X][Y] = '-';
                        b.push({X, Y});
                    }
                }
                if(x1 == 0) whole ++;
                else if(s1==0) destroyed ++;
                else downed ++;
            }

    cout << whole << ' ' << downed << ' ' << destroyed;
    return 0;
}