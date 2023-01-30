#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m, x, y;
    cin >> n >> m;
    vector<int> a(n+1);
    for(int i=0; i<m; i++){
        cin >> x >> y;
        a[x]++;
        a[y]++;
    }
    for(int i=1; i<=n; i++) 
        cout << a[i] << ' ';
    return 0;
}