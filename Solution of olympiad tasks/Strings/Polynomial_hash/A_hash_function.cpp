#include<iostream>
#include<vector>
using namespace std;

int p(string S, int x, int m){
    int d = 1, res = 0;
    for(char c: S){
        res = (res + (c - 48)*d)%m;
        d = (d*x)%m;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, x, res=0;
    string s;
    cin >> n >> m >> x;
    vector<int> cnt(2000);
    for(int i=0; i < n; i++){
        cin >> s;
        res += cnt[p(s, x, m)] ++;
    }
    cout << res;
    return 0;
}