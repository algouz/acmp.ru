#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<vector<int> >edges;
vector<bool> visited;
void dfs(int u){
    if(visited[u]) return;
    visited[u] = true;
    cnt ++;
    for(int v: edges[u]) dfs(v);
}
int main(){
    int n, s, x;
    cin >> n >> s;
    edges.resize(n+1);
    visited.resize(n+1);
    for(int i=1; i <= n; i++)
        for(int j=1; j <= n; j++){
            cin >> x;
            if(x==1) edges[i].push_back(j);
        }
    dfs(s);
    cout << cnt-1;
    return 0;
}