#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main(){
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<vector<int> > dist(n+1, vector<int>(n+1, -1));
    int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    queue<pair<int, int> > b;
    b.push({x1, y1});
    dist[x1][y1] = 0;
    while(!b.empty()){
        auto x = b.front().first;
        auto y = b.front().second;
        // auto [x, y] = b.front();
        b.pop();
        for(int i=0, X, Y; i<8; i++){
            X = x + dx[i];
            Y = y + dy[i];
            if(X < 1 || X > n || Y < 1 || Y > n || dist[X][Y] != -1) continue;
            b.push({X, Y});
            dist[X][Y] = dist[x][y] + 1;
            // cout << dist[X][Y] << ' ';
        }
    }
    cout << dist[x2][y2];
    return 0;
}