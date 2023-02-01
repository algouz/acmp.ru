#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > edges;
vector<vector<int> > countries;
vector<int> capital;
vector<bool> used;
void dfs(int v, int c = -1){
    if(used[v]) return;
    used[v] = true;
    if(capital[v] != -1) c = capital[v];
    countries[c].push_back(v);
    for(int u: edges[v]) dfs(u, c);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m;
    edges.resize(n+1);
    capital.resize(n+1, -1);
    used.resize(n+1);
    for(int i=0, u, v; i < m; i++){
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cin >> k;
    countries.resize(k);
    for(int i=0; i<k; i++){
        cin >> m;
        capital[m] = i;
    }
    dfs(m);
    for(auto country: countries){
        cout << country.size() << '\n';
        for(auto city: country) cout << city << ' ';
        cout << '\n';
    }
    return 0;
}