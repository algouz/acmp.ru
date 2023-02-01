#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > edges;
vector<vector<int> > res;
vector<int> comp;
vector<bool> used;

void dfs(int v){
    if(used[v]) return;
    used[v] = true;
    comp.push_back(v);
    for(int u: edges[v]) dfs(u);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;

    edges.resize(n+1);
    used.resize(n+1);
    for(int i=0; i < m; i++){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for(int i=1; i <= n; i++){
        if(used[i]) continue;
        comp.clear();
        dfs(i);
        res.push_back(comp);
    }
    cout << res.size();
    for(auto comp: res){
        cout << '\n' << comp.size() << '\n';
        for(int v: comp)
            cout << v << ' ';
    }
    return 0;
}