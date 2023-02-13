#include <iostream>
#include <vector>
using namespace std;
vector<int> a, t;

int gcd(int a, int b){
    return b ? gcd(b, a%b): a;
}

void build(int v, int l, int r){
    if(l == r){
        t[v] = a[l-1];
        return;
    }
    int m = (l+r)/2;
    build(v*2, l, m);
    build(v*2+1, m+1, r);
    t[v] = gcd(t[v*2], t[v*2+1]);
}

void update(int v, int l, int r, int id, int new_val){
    if(l == r){
        t[v] = new_val;
        return;
    }
    int m = (l+r)/2;
    if(id > m) update(v*2+1, m+1, r, id, new_val);
    else       update(v*2, l, m, id, new_val);
    t[v] = gcd(t[v*2], t[v*2+1]);
}


int get(int v, int l, int r, int L, int R){
    // cout << 1;
    if(l == L && r == R) return t[v];
    int m = (l+r) / 2;
    if(R <= m) return get(v*2, l, m, L, R);
    if(m < L)  return get(v*2+1, m+1, r, L, R);
    return gcd(get(v*2, l, m, L, m), get(v*2+1, m+1, r, m+1, R));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, l, r, id, x;
    char c;
    cin >> n;
    a.resize(n);
    t.resize(4*n);
    for(int &x: a) cin >> x;
    build(1, 1, n);
    cin >> m;
    for(int i=0; i < m; i++){
        cin >> c;
        if(c == 'g'){
            cin >> l >> r;
            cout << get(1, 1, n, l, r) << ' ';
        }
        else{
            cin >> id >> x;
            update(1, 1, n, id, x);
        }
    }
    return 0;
}   