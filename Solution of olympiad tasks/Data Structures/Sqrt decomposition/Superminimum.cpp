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
    b.resize(sqrt_n, 32768);
    for(int i=0, j; i < n; i ++){
        j = i / sqrt_n;
        b[j] = min(b[j], a[i]);
    }
}

int get(int l, int r){
    int L = l/sqrt_n, R = r/sqrt_n;
    if(L == R){
        if(isStart(l) && IsEnd(r)) return b[L];
        int res = 32768;
        for(int i=l; i <= r; i++) res = min(res, a[i]);
        return res;
    }
    int res = 32768;
    if(!isStart(l)){
        for(int i = l, t = (L+1)*sqrt_n; i < t; i++)
            res = min(res, a[i]);
        L++;
    }
    if(!IsEnd(r)){
        for(int i = R * sqrt_n; i <= r; i++)
            res = min(res, a[i]);
        R --;
    }
    for(int i = L; i <= R; i++){
        res = min(res, b[i]);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l, r, k;
    cin >> n >> k;
    a.resize(n);
    for(int &x: a) cin >> x;
    build();
    for(int l = 0, r = k-1; r < n; l++, r++)
        cout << get(l, r) << ' ';
    return 0;
}