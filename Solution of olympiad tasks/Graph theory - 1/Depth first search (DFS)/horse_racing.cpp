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
    int n, s, u, v;
    cin >> n >> s;
    edges.resize(n+1);
    visited.resize(n+1);
    cin >> u;
    while(u != 0){
        cin >> v;
        if(v == s){
            cout << "No";
            return 0;
        }
        edges[u].push_back(v);
        cin >> u;
    }
    dfs(s);
    cout << (cnt == n? "Yes":"No");
    return 0;
}