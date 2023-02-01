#include<iostream>
#include<vector>
using namespace std;


int n=8, m=8;
vector<string> a;


void dfs(int q, int u, char r){
    if(q < 0 || u < 0 || q >= n || u >= m || a[q][u] != r) return;
    a[q][u] = '.';
    r = "BW"[r == 'B'];
    dfs(q-1, u, r);
    dfs(q+1, u, r);
    dfs(q, u-1, r);
    dfs(q, u+1, r);

}
int main(){
    int cnt = 0;
    a.resize(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(a[i][j] != '.'){
                cnt ++;
                dfs(i, j, a[i][j]);
            }
    cout << cnt;
}