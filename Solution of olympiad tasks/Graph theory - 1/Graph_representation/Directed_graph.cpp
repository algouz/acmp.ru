#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, cnt=0, x;
    cin >> n;
    vector<vector<int> > a(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)
        if(a[i][i]==1){
            cout << "NO";
            return 0;
        }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i][j] != a[j][i]){
                cout << "YES";
                return 0;
            }
    cout << "NO";
    return 0;

}