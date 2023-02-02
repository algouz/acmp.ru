#include<iostream>
#include<vector>
#include<climits>
using namespace std;
vector<int> rang, res, x, y;
vector<vector<int> > L;
int n;
bool dfs(int i, double r, int rng){
    if(rang[i]) return rang[i] == rng;
    rang[i] = rng;
    for(int j=0; j < n; j++){
        if(L[i][j] >= r) continue;
        if(!dfs(j, r, 3-rng)) return false;
    }
    return true;
}

bool check(double r){
    rang.assign(n, 0);
    for(int i=0; i < n; i++){
        if(rang[i] == 0){
            if(!dfs(i, 4*r*r, 1)) return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    x.resize(n);
    y.resize(n);
    for(int i=0; i<n; i++) cin >> x[i] >> y[i];
    L.resize(n, vector<int>(n));
    for(int i=0; i<n; i++){

        for(int j=0; j<n; j++)
            L[i][j] = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
        L[i][i] = INT_MAX;
    }
    double l = 0, r = 1e5, m, result = 0;
    for(int i=0; i < 100; i++){
        m = (l+r)/2;
        if(check(m)){
            result = m;
            res = rang;
            l = m;
        }
        else r=m;
    }
    cout.precision(10);
    cout << fixed;
    cout << result << '\n';
    for(int x: res) cout << x << ' ';
    return 0;
}