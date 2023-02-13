#include <iostream>
#include <vector>
using namespace std;
using type = int;
vector<type> a, t;


type compare(type i, type j){
    //type code here
    return (a[j] > a[i] ? j: i);
}

type marge(type a, type b){
    return compare(a, b);
}


void build(int v, int l, int r){
    if(l == r){
        t[v] = l-1;
        return;
    }
    int m = (l+r)>>1;
    build(v<<1, l, m);
    build(v<<1|1, m+1, r);
    t[v] = marge(t[v<<1], t[v<<1|1]);
}

void update(int v, int l, int r, int id, type new_val){
    if(l == r){
        t[v] = new_val;
        return;
    }
    int m = (l+r) >> 1;
    if(id > m) update(v<<1|1, m+1, r, id, new_val);
    else       update(v<<1, l, m, id, new_val);
    t[v] = marge(t[v<<1], t[v<<1|1]);
}


type get(int v, int l, int r, int L, int R){
    // cout << 1;
    if(l == L && r == R) return t[v];
    int m = (l+r) >> 1;
    if(R <= m) return get(v<<1, l, m, L, R);
    if(m < L)  return get(v<<1|1, m+1, r, L, R);
    return marge(get(v*2, l, m, L, m), get(v*2+1, m+1, r, m+1, R));
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, l, r, id;
    type k;
    char c;
    cin >> n;
    a.resize(n);
    t.resize(n<<2);
    for(type &x: a) cin >> x;
    build(1, 1, n);
    cin >> m;
    for(int i=0; i < m; i++){
        cin >> l >> r;
        l = get(1, 1, n, l, r);
        cout << a[l] << ' ' << l + 1 << '\n';
    }
    return 0;
}