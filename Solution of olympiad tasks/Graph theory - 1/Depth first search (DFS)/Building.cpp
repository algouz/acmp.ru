#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > edges;
vector<bool> used;
vector<int> cnt;
int cont;

void dfs(int u){
    if(used[u]) return;
    used[u] = true;
    cont ++;
    for(int v: edges[u]){
        cnt[v] --;
        if(cnt[v]==0) dfs(v); 
    }
}

int main(){
    int n, m, u, v;
    cin >> n >> m;
    edges.resize(n+1);
    cnt.resize(n+1);
    for(int i=0; i < m; i++){
        cin >> u >> v;
        edges[u].push_back(v);
        cnt[v]++;
    }
    used.resize(n+1);
    for(int i=1; i <= n; i++){
        if(cnt[i] == 0) dfs(i);
    }
    cout << (cont == n? "Yes": "No");
    return 0;
}