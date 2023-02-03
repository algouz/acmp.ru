#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
map<string, vector<string> > edges;
int main(){
    int n;
    cin >> n;
    string x, y;
    for(int i=0; i < n; i++){
        cin >> x >> y >> y;
        edges[x].push_back(y);
    }
    cin >> x >> y;
    queue<string> b;
    map<string, int> dist;
    b.push(x);
    dist[x] = 0;
    while(!b.empty()){
        x = b.front();
        b.pop();
        for(string v: edges[x]){
            if(dist.count(v) == 0){
                dist[v] = dist[x] + 1;
                b.push(v);
            }
        }
    }
    if(dist.count(y) == 0)  cout << -1;
    else cout << dist[y];
    return 0;
}