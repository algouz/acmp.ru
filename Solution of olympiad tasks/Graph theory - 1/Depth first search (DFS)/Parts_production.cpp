#include<iostream>
#include<vector>
using namespace std;
vector<vector<int> > edges;
vector<bool> used;
vector<int> tim;
vector<int> a;
long long sm;
void dfs(int u){
    if(used[u]) return;
    for(int v: edges[u]) dfs(v);
    used[u] = true;
    sm += tim[u];
    a.push_back(u);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, cnt, x;
    cin >> n;
    edges.resize(n+1);
    used.resize(n+1);
    tim.resize(n+1);
    for(int i=1; i <= n; i++)
        cin >> tim[i];
    for(int i=1; i <= n; i++){
        cin >> cnt;
        edges[i].resize(cnt);
        for(int &x: edges[i]) cin >> x;
    }
    dfs(1);
    cout << sm << ' ' << a.size() << '\n';
    for(int u: a) cout << u << ' ';
    return 0;
}