#include<iostream>
#include<vector>
using namespace std;
vector<vector<char> > g;
int n, m;
bool s, x;
void dfs(int u, int v){
    if(u < 0 || u >= n || v < 0 || v >= m || g[u][v] == '-') return;
    if(g[u][v] == 'S') s = true;
    else x = true;
    g[u][v] = '-';
    dfs(u+1, v);
    dfs(u-1, v);
    dfs(u, v-1);
    dfs(u, v+1);
}

int main(){
    int whole=0, downed=0, destroyed = 0;
    cin >> n >> m;
    g.resize(n, vector<char>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j < m; j++)
            cin >> g[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(g[i][j] != '-'){
                s = false;
                x = false;
                dfs(i, j);
                if(s && !x) whole ++;
                else if(!s && x) destroyed ++;
                else downed ++;
            }

    cout << whole << ' ' << downed << ' ' << destroyed;
    return 0;
}