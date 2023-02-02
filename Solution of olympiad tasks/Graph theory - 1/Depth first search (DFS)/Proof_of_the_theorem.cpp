#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<vector<int> > edges;
vector<bool> used;
vector<int> cnt;

void dfs(int u){
    for(int v: edges[u]) dfs(v);
    sort(edges[u].begin(), edges[u].end(), [](int x, int y){return cnt[x] < cnt[y];});
    for(int i= (edges[u].size()-1)/2; i >= 0; i--)
        cnt[u] += cnt[edges[u][i]];
    cnt[u] ++;
}

void _dfs(int u){
    for(int i= (edges[u].size()-1)/2; i >= 0; i--) _dfs(edges[u][i]);
    cout << '\n' << u;
}

int main(){
    int n, x;
    cin >> n;
    edges.resize(n+1);
    cnt.resize(n+1);
    for(int i=1; i <= n; i++)
        while(cin >> x, x != 0) edges[i].push_back(x);
    dfs(1);
    cout << cnt[1];
    _dfs(1);
    return 0;
}