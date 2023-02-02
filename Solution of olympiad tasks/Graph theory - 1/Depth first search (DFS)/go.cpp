#include<iostream>
#include<vector>
using namespace std;
int n, dame;
vector<vector<char> >a;
vector<vector<int> > used;

void dfs(int q, int u){
    if(q < 0 || u < 0 || q >= n || u >= n || used[q][u]) return;
    used[q][u] = 1;
    if(a[q][u] == '.') dame++;
    if(a[q][u] == 'B'){
        dfs(q-1, u);
        dfs(q, u-1);
        dfs(q+1, u);
        dfs(q, u+1);
    }
}

void _dfs(int q, int u){
    if(q < 0 || u < 0 || q >= n || u >= n || used[q][u] == 2) return;
    used[q][u] = 2;
    if(a[q][u] == '.') used[q][u] = 0;
    if(a[q][u] == 'B'){
        _dfs(q-1, u);
        _dfs(q, u-1);
        _dfs(q+1, u);
        _dfs(q, u+1);
    }
}

int main(){
    int cnt = 0;
    cin >> n;
    a.resize(n, vector<char>(n));
    used.resize(n, vector<int>(n));
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            cin >> a[i][j];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            if(a[i][j] == 'B' && !used[i][j]){
                dame = 0;
                dfs(i, j);
                if(dame == 1) cnt ++;
                _dfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}