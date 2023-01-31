#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> h(n+1), f(n+1);
    for(int i=2; i<=n; i++){
        cin >> f[i];
        h[i] = h[f[i]] + 1;
    }
    while(u != v){
        if(h[u] > h[v]) u = f[u];
        else v = f[v];
    }
    cout << v;
    return 0;
}