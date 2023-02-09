#include <iostream>
#include <set>
using namespace std;
const int mod1 = 1e9+7;
const int mod2 = 1e9+9;
const int alphabet1 = 271;
const int alphabet2 = 293;
int main(){
    string a, b;
    cin >> a >> b;
    set<pair<int, int> > s;
    int h1 = 0, d1=1, cnt, h2=0, d2=1;
    for(char c: b){
        h1 = (1LL * h1 * alphabet1 + c) % mod1;
        h2 = (1LL * h2 * alphabet2 + c) % mod2;
    }
    for(int i=1; i < b.size(); i++){
        d1 = (1LL * d1 * alphabet1) % mod1;
        d2 = (1LL * d2 * alphabet2) % mod2;
    }

    for(char c: b){
        h1 = ((h1 - 1LL * c * d1 % mod1 + mod1)%mod1*alphabet1 + c) % mod1; 
        h2 = ((h2 - 1LL * c * d2 % mod2 + mod2)%mod2*alphabet2 + c) % mod2; 
        s.insert(make_pair(h1, h2));
    }

    h1 = h2 = 0;
    for(int i=0; i < b.size(); i++){
        h1 = (1LL * h1 * alphabet1 + a[i]) % mod1;
        h2 = (1LL * h2 * alphabet2 + a[i]) % mod2;
    }
    cnt = s.count(make_pair(h1, h2));
    for(int i = b.size(); i < a.size(); i++){
        h1 = ((h1 - 1LL * a[i-b.size()] * d1 % mod1 + mod1)%mod1*alphabet1 + a[i]) % mod1; 
        h2 = ((h2 - 1LL * a[i-b.size()] * d2 % mod2 + mod2)%mod2*alphabet2 + a[i]) % mod2; 
        cnt += s.count(make_pair(h1, h2));
    }
    cout << cnt;
    return 0;
}