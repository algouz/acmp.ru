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
    int n, x, res=0;
    cin >> n;
    edges.resize(n+1);
    visited.resize(n+1);
    for(int i=1; i <= n; i++)
        for(int j=1; j <= n; j++){
            cin >> x;
            if(x==1){
                edges[i].push_back(j);
                res ++;
            }
        }
    res/=2;
    dfs(1);
    cout << (cnt==n && res + 1 == n? "YES": "NO");
    return 0;
}