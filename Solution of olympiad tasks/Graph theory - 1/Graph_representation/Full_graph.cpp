#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, u, v;
    cin >> n >> m;
    vector<vector<int> > a(n+1, vector<int> (n+1));
    for(int i=0; i<m; i++){
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    for(int i=1; i <= n; i++){
        for(int j=i+1; j <= n; j++){
            if(a[i][j]==0){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;

}