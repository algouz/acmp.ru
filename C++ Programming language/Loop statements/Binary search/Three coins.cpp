#include<iostream>
using namespace std;
using ll = long long;
ll n, s;
ll get(ll n){
    if(n > ::n) return s;
    cout << "? " << n << endl;
    ll s;
    cin >> s;
    return n*(n+1)/2 - s;
}
int main(){
    cin >> n;
    s = get(n);
    ll a1, a2, a3, l=1, r=n, m, q, g;
    while(true){
        m = (l+r)/2;
        q = get(m);
        if(q == 0) l = m+1;
        else if(q == s) r = m;
        else{
            g = get(q-1);
            if(g == 0){
                a1 = q;
                l = m+1;
                while(true){
                    m = (l+r)/2;
                    g = get(m);
                    if(g == q) l = m+1;
                    else if(g == s) r = m;
                    else{
                        a2 = g - a1;
                        a3 = s - g;
                        break;
                    }
                }
                break;
            }
            else{
                a3 = s - q;
                r = m;
                while(true){
                    m = (l+r)/2;
                    g = get(m);
                    if(g == 0) l = m+1;
                    else if(g == q) r = m;
                    else{
                        a1 = g;
                        a2 = q-a1;
                        break;
                    }
                }
                break;
            }
        }
    }
    cout << "! " << a1 << ' ' << a2 << ' ' << a3;
    return 0;
}