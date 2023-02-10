#include <iostream>
#include <random>
#include <map>
using namespace std;
using ll = long long;
random_device rnd;
ll rand_range(ll l, ll r){
    return rnd() % (r - l + 1) + l;
}
ll binmult(ll a, ll b, ll mod){
    ll r = 0;
    while(b){
        if(b&1) r = (r + a) % mod;
        b >>= 1;
        a = (a + a) % mod;
    }
    return r;
}
ll binpow(ll a, ll n, ll mod){
    ll r = 1 % mod;
    while(n){
        if(n & 1) r = binmult(r, a, mod);
        n >>= 1;
        a = binmult(a, a, mod);
    }
    return r;
}
ll gcd(ll a, ll b){
    return b ? gcd(b, a % b) : a;
}
ll pollard_rho(ll n){
    if(n % 2 == 0) return 2;
    ll x = rand_range(1, n);
    ll c = rand_range(1, n);
    ll y = x;
    ll g = 1;
    while(g == 1){
        x = (binmult(x, x, n) + c) % n;
        y = (binmult(y, y, n) + c) % n;
        y = (binmult(y, y, n) + c) % n;
        g = gcd(n, abs(x-y));
    }
    return g;
}
bool miller_test(ll d, ll r, ll n){
    ll a = rand_range(2, n-2);
    ll x = binpow(a, d, n);
    if(x == 1 || x == n-1) return true;
    for(int i = 1; i < r; i ++){
        x = binmult(x, x, n);
        if(x == 1)
            return false;
        if(x == n-1)
            return true;
    }
    return false;
}
bool miller_probably_prime(ll n, int k = 20){
    ll s = n - 1, d = 0;
    while(!(s&1)){
        s >>= 1;
        d ++;
    }
    for(int i = 0; i < k; i ++)
        if(!miller_test(s, d, n))
            return false;
    return true;
}
bool is_prime(ll n){
    if(n == 2 || n == 3) return true;
    if(n < 1 || (n&-n) == n) return false;
    if(n % 2 == 0) return false;
    return miller_probably_prime(n);
}
map<ll, int>mp;
void factorization(ll n){
    if(n == 1) return;
    if(is_prime(n)){
        mp[n] ++;
        return;
    }
    ll d;
    d = n % 2 == 0 ? 2 : pollard_rho(n);
    factorization(d);
    factorization(n/d);
}
void t_main(){
    ll n;
    cin >> n;
    factorization(n);
    for(auto x = mp.begin(); x != mp.end(); x ++){
        for(int j = 0; j < x->second; j ++){
            cout << n << "|" << x->first << '\n';
            n /= x->first;
        }
    }
    cout << "1|";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    ///cin >> t;
    while(t --) t_main();
    return 0;
}