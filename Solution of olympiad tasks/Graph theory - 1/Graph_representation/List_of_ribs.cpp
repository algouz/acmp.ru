#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int> > graph(n+1);
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
    }
    cout << n;
    for(int v = 1; v <= n; v++){
        cout << '\n' << graph[v].size();
        sort(graph[v].begin(), graph[v].end());
        for(auto x: graph[v]) cout << ' ' << x;
    }
    return 0;
}