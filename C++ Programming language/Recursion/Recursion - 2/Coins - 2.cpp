#include <iostream>
using namespace std;
int n, m, a[15], ts;

void brute_force(int i, int k, long long s){
    if(i == m){
        if(s == n && k < ts) ts = k;
        return; 
    }
    brute_force(i+1, k, s);
    brute_force(i+1, k+1, s+a[i]);
    brute_force(i+1, k+2, s+2*a[i]);
}

int main(){
    cin >> n >> m;
    long long s=0;
    for(int i=0; i < m; i++){
        cin >> a[i];
        s += a[i] << 1;
    }
    if(s < n){
        cout << -1;
        return 0;
    }
    ts = 2*m+1;
    brute_force(0, 0, 0);
    cout << (ts == 2*m+1 ? 0 : ts);
    return 0;
}