#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > edges;
vector<int> color;
bool dfs(int v, int r){
    if(color[v] != 0) return color[v] == r;
    color[v] = r;
    r = 3 - r;
    for(int u: edges[v])
        if(!dfs(u, r)) return false;
    return true;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    edges.resize(n+1);
    for(int i=1; i <= m; i++){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    color.resize(n+1);
    for(int i= 1; i <= n; i++)
        if(color[i]==0){
            if(!dfs(i, 1)){
                cout << "NO";
                return 0;
            }
        }
    cout << "YES";
    return 0;
}