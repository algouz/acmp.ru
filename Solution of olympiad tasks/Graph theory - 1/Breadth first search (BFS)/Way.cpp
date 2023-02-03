#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > edges;
vector<int> dist;
int main(){
    int n, x;
    cin >> n;
    edges.resize(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<= n; j++){
            cin >> x;
            if(x==1) edges[i].push_back(j);
        }
    }
    int u, v;
    cin >> u >> v;
    dist.resize(n+1, -1);
    dist[u] = 0;
    queue<int> b;
    b.push(u);
    while(!b.empty()){
        x = b.front();
        b.pop();
        for(int y: edges[x])
            if(dist[y] == -1){
                b.push(y);
                dist[y] = dist[x]+1;
            }
    }
    cout << dist[v];
    return 0;
}