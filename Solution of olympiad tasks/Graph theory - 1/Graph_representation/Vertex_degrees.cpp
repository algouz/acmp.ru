#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, cnt=0, x;
    cin >> n;
    vector<pair<int, int> > edges;
    for(int u=1; u <= n; u++){
        int cnt=0;
        for(int v=1; v <= n; v++){
            cin >> x;
            if(x==1) cnt ++;
        }
        cout << cnt << ' ';
    }
    return 0;

}