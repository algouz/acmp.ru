#include<iostream>
#include<vector>
using namespace std;
int cnt = -4;
vector<vector<bool> > used;
vector<string> a;
void dfs(int q, int u){
    if(a[q][u]=='#'){
        cnt++;
        return;
    }
    if(used[q][u]) return;
    used[q][u] = true;
    dfs(q-1, u);
    dfs(q+1, u);
    dfs(q, u-1);
    dfs(q, u+1);
}
int main(){
    int n;
    cin>>n;
    a.resize(n+2);
    used.resize(n+2, vector<bool>(n+2));
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] = '#'+a[i]+'#';
    }
    a[0] = a[n+1] = string(n+2, '#');
    dfs(1, 1);
    dfs(n, n);
    cout << cnt*25;
    return 0;
}