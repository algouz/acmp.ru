#include<bits/stdc++.h>
using namespace std;
int main(){
    int mn = INT_MAX, mx = INT_MIN, x=0;
    while(cin>>x){
        x++;
        if(x%2) mn = min(mn, x);
        else mx = max(mx, x);
    }
    cout << mn+mx;
    return 0;
}