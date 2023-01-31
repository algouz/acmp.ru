#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x, v;
    cin >> n;
    vector<vector<int> > edg(n+1, vector<int>(n+1));
    for(int u=1; u<=n; u++){
        cin >> x;
        for(int i=0; i < x; i++){
            cin >> v;
            edg[u][v] = 1;
        }
    }
    cout << n;
    for(int u=1; u <= n; u++){
        cout << '\n';
        for(int v=1; v <= n; v++)
            cout << edg[u][v] << ' ';
    }
    return 0;
}