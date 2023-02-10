#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> a, b;
int sqrt_n;

bool isStart(int l){
    return l % sqrt_n == 0;
}

bool IsEnd(int r){
    return r+1 == a.size() || (r+1) % sqrt_n == 0;
}

void build(){
    int n = a.size();
    sqrt_n = ceil(sqrt(n));
    b.resize(sqrt_n);
    for(int i=0, j; i < n; i ++){
        j = i / sqrt_n;
        b[j] += a[i] == 0;
    }
}

int get(int l, int r){
    int L = l/sqrt_n, R = r/sqrt_n;
    if(L == R){
        if(isStart(l) && IsEnd(r)) return b[L];
        int res = 0;
        for(int i=l; i <= r; i++) res += a[i] == 0;
        return res;
    }
    int res = 0;
    if(!isStart(l)){
        for(int i = l, t = (L+1)*sqrt_n; i < t; i++)
            res += a[i] == 0;
        L++;
    }
    if(!IsEnd(r)){
        for(int i = R * sqrt_n; i <= r; i++)
            res += a[i] == 0;
        R --;
    }
    for(int i = L; i <= R; i++){
        res += b[i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l, r;
    cin >> n;
    a.resize(n);
    for(int &x: a) cin >> x;
    build();
    int m;
    cin >> m;
    for(int i=0; i < m; i++){
        cin >> l >> r;
        cout << get(l-1, r-1) << ' ';
    }
    return 0;
}