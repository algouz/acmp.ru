#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int> > edg(n+1, vector<int>(n+1));
    for(int i=0; i<m; i++){
        cin >> u >> v;
        if(u == v){
            cout << "NO";
            return 0;
        }
        edg[u][v] ++;
    }
    for(int u=1; u <= n; u++){
        for(int v=u+1; v <= n; v++){
            if(edg[u][v]+edg[v][u] != 1){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}