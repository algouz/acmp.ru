#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, cnt=0;
    cin >> n;
    vector<vector<int> > graph(n+1, vector<int>(n+1));
    for(int u=1; u <= n; u++)
        for(int v=1; v <= n; v++){
            cin >> graph[u][v];
            if(graph[u][v]) cnt ++;
        }
    cout << n << ' ' << cnt << '\n';
    for(int u=1; u <= n; u++)
        for(int v=1; v <= n; v++)
            if(graph[u][v]) cout << u << ' ' << v << '\n';
    return 0;

}