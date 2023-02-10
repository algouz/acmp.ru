#include <iostream>
using namespace std;
int dp[1<<15|1] = {1};
int rev[1<<15|1] = {1};
int dp0[1<<15|1];
int binpow(int a, int n, int mod){
    int r = 1%mod;
    while(n){
        if(n&1) r = 1LL * r * a % mod;
        n >>= 1;
        a = 1LL * a * a % mod;
    }
    return r;
}
int main(){
    int n, q, r31, mod = (1LL<<31)-1, l, r, _n, s=0, x;
    cin >> n >> q >> r31;
    _n = n-1;
    auto next = [&](){
        r31 = (r31*1103515245LL + 12345) & mod;
        return r31 >> 16;
    };
    for(int i=1; i <= n; i++){
        x = next();
        dp0[i] = dp0[i-1];
        if(x == 0){
            dp0[i] ++;
            x = 1;
        }
        dp[i] = (1LL*dp[i-1] * x) % mod;
        rev[i] = binpow(dp[i], mod-2, mod);
    }
    for(int i=1; i <= q; i++){
        l = (next() & _n);
        r = (next() & _n);
        if(l > r) swap(l, r);
        if(dp0[r+1] - dp0[l]==0) 
            s = (s + 1LL*dp[r + 1] * rev[l]) % mod;
    }
    cout << s;
    return 0;
}