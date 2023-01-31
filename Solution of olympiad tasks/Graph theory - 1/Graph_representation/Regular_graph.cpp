#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, cnt=0, x;
    cin >> n;
    for(int v=1; v <= n; v++){
        cin >> x;
        if(x) cnt ++;
    }    
    for(int u=2; u <= n; u++){
        int k=0;
        for(int v=1; v <= n; v++){
            cin >> x;
            if(x==1) k ++;
        }
        if(k != cnt){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;

}