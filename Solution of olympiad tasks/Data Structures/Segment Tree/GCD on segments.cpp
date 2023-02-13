#include <iostream>
#include <vector>
using namespace std;
vector<int> a, t;

int gcd(int a, int b){
    return b? gcd(b, a%b): a;
}

void build(int v, int l, int r){
    if(l == r){
        t[v] = a[v-1];
        return;
    }
    int m = (l+r)/2;
    if(r < m) build(v*2, 1, m);
    else      build(v*2+1, m+1, r);
    t[v] = gcd(t[v*2], t[v*2+1]);
}

int get(int v, int l, int r, int L, int R){
    if(l == L && r == R) return t[v];
    int m = (l+r)/2;
    if(r < m) return get(v*2, l, m, L, R);
    if(l > m) return get(v*2+1, m+1, r, L, R);
    return gcd(get(v*2, l, m, L, m), get(v*2+1, m+1, r, m+1, R));
}

int main(){
    int n, m, l, r;
    cin >> n;
    a.resize(n);
    t.resize(n*4);
    for(int &x: a) cin >> x;
    build(1, 1, n);
    cin >> m;
    for(int i=0; i<m; i++){
        cin >> l >> r;
        cout << get(1, 1, n, l, r);
    }
    return 0;
}