#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, x;
    cin >> n >> m;
    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
    vector<vector<int> > dist(n, vector<int>(m, 100004));
    queue<pair<int, int> > b;
    // vector<pair<int, int> > pink;
    vector<vector<bool> > used;
    for(int i=0; i < n; i++)
        for(int j=0; j < m; j++){
            cin >> x;
            if(x == 1){
                // pink.push_back({i, j});
                used.assign(n, vector<bool>(m, false));
                dist[i][j] = 0;
                b.push({i, j});
                while(!b.empty()){
                    int x = b.front().first, y = b.front().second;
                    b.pop();
                    for(int q=0, X, Y; q<8; q++){
                        X = x + dx[q];
                        Y = y + dy[q];
                        if(X < 0 || X >= n || Y < 0 || Y >= m || used[X][Y]) continue;
                        used[X][Y] = true;
                        b.push({X, Y});
                        dist[X][Y] = min(dist[X][Y], dist[x][y] + abs(x-X)+abs(y-Y));
                    }
                }
            }
        }
    for(auto i: dist){
        for(auto j: i) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}