#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k=0;
    cin >> n;
    vector<int> b(n+1);
    vector<vector<int> > a(n+1, vector<int>(n+1));
    for(int i=1; i <= n; i++)
        for(int j=1; j <= n; j++) 
            cin >> a[i][j];
    for(int i=1;i<=n;i++)
        cin >> b[i];

    for(int i=1; i <= n; i++)
        for(int j=i+1; j <= n; j++) 
            if(a[i][j]==1) k += b[i]!=b[j];
    cout << k;
}