#include <bits/stdc++.h>
using namespace std;
vector<vector<char> > a;
vector<vector<int> > dist;
queue<pair<int, int> > b;

int n, m, res = 1000000;

void add(int x, int y, int d){
    if(x <= 0 || x > n || y <= 0 || y > m){
        res = min(res, d);
        return;
    }
    if(a[x][y] == '0' || dist[x][y] != -1) return;

    dist[x][y] = d;
    b.push({x, y});
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int x, y;

    cin >> n >> m >> x >> y;

    a.resize(n+1, vector<char>(m+1));
    dist.resize(n+1, vector<int>(m+1, -1));
    
    for(int i=1; i <= n; i++)
        for(int j=1; j <= m; j++) cin >> a[i][j];
    
    add(x, y, 0);
    
    while(!b.empty()){
        //auto [x, y] = b.front();
        x = b.front().first;
        y = b.front().second;
        b.pop();
        add(x-1, y - x%2, dist[x][y] + 1);
        add(x-1, y - x%2+1, dist[x][y] + 1);
        add(x+1, y - x%2, dist[x][y] + 1);
        add(x+1, y - x%2+1, dist[x][y] + 1);
        add(x, y - 1, dist[x][y] + 1);
        add(x, y + 1, dist[x][y] + 1);
    }
    if(res == 1000000) cout << "No solution";
    else cout << res;
    return 0;
}