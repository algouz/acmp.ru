#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<string> a;

void dfs(int q, int u){
    if(q < 0 || u < 0 || q >= n || u >= m || a[q][u] != '#') return;
    a[q][u] = '.';
    dfs(q-1, u);
    dfs(q+1, u);
    dfs(q, u-1);
    dfs(q, u+1);

}
int main(){
    char x;
    cin >> n >> m;
    int cnt = 0;
    a.resize(n);
    for(int u=0; u < n; u++) cin >> a[u];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j]=='#'){
                cnt ++;
                dfs(i, j);
            }
    cout << cnt;
}