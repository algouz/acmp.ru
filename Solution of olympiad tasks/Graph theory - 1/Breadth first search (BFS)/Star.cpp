#include<iostream>
#include<vector>
using namespace std;
vector<string> g;
int cnt=0, n, m;
void dfs(int u, int v){
    if(u < 0 || u >= n || v < 0 || v >= m || g[u][v] != '*') return;
    g[u][v] = '.';
    dfs(u+1, v);
    dfs(u-1, v);
    dfs(u, v-1);
    dfs(u, v+1);
}
 
int main(){
    cin >> n >> m;
    g.resize(n);
    for(int i=0; i<n; i++)
        cin >> g[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(g[i][j] == '*'){
                cnt++;
                dfs(i, j);
            }
 
    cout << cnt;
}