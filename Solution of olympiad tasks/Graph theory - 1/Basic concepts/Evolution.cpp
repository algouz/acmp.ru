#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n, x, y;
    cin >> n >> x >> y;
    while(x != y){
        y > x ? y/=2: x/=2;
    }
    cout << x;
    return 0;
}