#include <iostream>
#include <vector>
using namespace std;
vector<int> a;
vector<long long> t;

void add(int v, int l, int r, int L, int R, int d){
    if(L== l && R == r) t[v] += d;
    else{
        int m = (l+r)>>1;
        if(R <= m) add(v<<1 ,l, m, L, R, d);
        else if(L > m) add(v<<1|1, m+1, r, L, R, d);
        else{
            add(v<<1, l, m, L, m, d);
            add(v<<1|1, m+1, r, m+1, R, d);
        }
    }
}

long long get(int v, int l, int r, int id){
    if(l == r) return t[v];
    int m = (l+r) >> 1;
    if(id > m) return t[v] + get(v<<1|1, m+1, r, id);
    return t[v] + get(v<<1, l, m, id);
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m, l, r, d, id;
    char c;
    cin >> n;
    a.resize(n);
    t.resize(n<<2);
    for(int &x: a) cin >> x;
    cin >> m;
    for(int i=0;i < m; i++){
        cin >> c;
        if(c == 'a'){
            cin >> l >> r >> d;
            add(1, 1, n, l, r, d);
        }
        else{
            cin >> id;
            cout << a[id-1] + get(1, 1, n, id) << ' ';
        }
    }
    return 0;
}