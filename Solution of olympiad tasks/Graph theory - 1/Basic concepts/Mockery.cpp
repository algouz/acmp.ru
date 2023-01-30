#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k=0;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++)
            cin >> a[i][j];
    int mx = 3001;
    for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            for(int k=j+1; k<n; k++)
                mx = min(mx, a[i][j]+a[j][k]+a[k][i]);
    cout << mx;
}