#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> a, b, c;
int sqrt_n;

bool isStart(int l){
    return l % sqrt_n == 0;
}

bool isEnd(int r){
    return r+1 == a.size() || (r+1) % sqrt_n == 0;
}

void build(){
    sqrt_n = ceil(sqrt(a.size()));
    b.resize(sqrt_n);
    c.resize(sqrt_n);
}

void inc_range(int l, int r){
    int L = l/sqrt_n, R = r/sqrt_n;
    if(L == R){
        if(isStart(l) && isEnd(r)){
            c[L] ++;
            b[L] ++;
            return;
        }
        for(int i=l; i <= r; i++){
            a[i] ++;
            b[L] = max(b[L], a[i]+c[L]);
        }
        return;
    }
    if(!isStart(l)){
        for(int i = l, j = (L +1)*sqrt_n; i < j; i++){
            a[i] ++;
            b[L] = max(b[L], a[i] + c[L]);
        }
        L++;
    }
    if(!isEnd(r)){
        for(int i = R * sqrt_n; i <= r; i++){
            a[i] ++;
            b[R] = max(b[R], a[i] + c[R]);
        }
        R--;
    }
    for(int i = L; i <= R; i++){
        c[i] ++;
        b[i] ++;
    }
}

int get_max(int l, int r){
    int L = l/sqrt_n, R = r/sqrt_n;
    int res = 0;
    if(L == R){
        if(isStart(l) && isEnd(r)) return b[l];
        for(int i = l; i <= r; i++) res = max(res, a[i] + c[L]);
        return res;
    }
    if(!isStart(l)){
        for(int i = l, j = (L+1) * sqrt_n; i < j; i++)  res = max(res, a[i] + c[L]);
        L--;
    }
    if(!isEnd(r)){
        for(int i = R * sqrt_n; i <= r; i++)  res = max(res, a[i] + c[L]);
        R++;
    }
    for(int i = L; i <= R; i++) res = max(res, b[i]);
    return res;
}

int main(){
    int n, k, m;
    cin >> n >> k >> m;
    a.resize(n);
    build();
    for(int i=0, l, r; i < m; i++){
        cin >> l >> r;
        if(get_max(l, r-1) < k){
            cout << "Yes\n";
            inc_range(l, r-1);
        }
        else cout << "No\n";
    }
}