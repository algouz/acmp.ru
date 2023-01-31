#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, cnt=0, x;
    cin >> n;
    vector<pair<int, int> > edges;
    for(int u=1; u <= n; u++){
        for(int v=1; v <= n; v++){
            cin >> x;
            if(x==1) edges.push_back({u, v});
        }
    }
    cout << n << ' ' << edges.size();
    for(auto edge: edges)
        cout << '\n' << edge.first << ' ' << edge.second;
    
    return 0;

}