#include <iostream>
using namespace std;
int dp[1<<15|1];
int main(){
    int n, q, r31, mod = (1LL<<31)-1, l, r, _n, s=0;
    cin >> n >> q >> r31;
    _n = n-1;
    auto next = [&](){
        r31 = (r31*1103515245LL + 12345) & mod;
        return r31 >> 16;
    };
    for(int i=1; i <= n; i++) dp[i] = (dp[i-1] + next()) & mod;
    for(int i=1; i <= q; i++){
        l = (next() & _n);
        r = (next() & _n);
        if(l > r) swap(l, r);
        s = (s + dp[r + 1] - dp[l]) & mod;
    }
    if(s < 0) s += mod+1;
    cout << s;
    return 0;
}