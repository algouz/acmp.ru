#include <vector>
#include <iostream>
#include <set>
using namespace std;
vector<int> id(10002);
void solve(){
    int n;
    cin >> n;
    vector<int> s(10001);
    vector<pair<int, int> > a(n);
    for(int i=0; i < n; i++){
        cin >> a[i].first >> a[i].second;
        s[a[i].first] ++;
        s[a[i].second] --;
    }
    if(s[0] == 0){
        cout << "Wrong Answer\n";
        return;
    }
    for(int i=1; i < 10000; i++){
        s[i] += s[i-1];
        if(s[i] == 0){
            cout << "Wrong Answer\n";
            return;
        }
    }   
    s[10000] += s[9999];
    vector<vector<int> > dp(id[10001]+1);
    dp[0] = s;
    for(int d = 1; d < dp.size(); d ++){
        dp[d].resize(10002 - (1<<d));
        for(int j=0; j < dp[d].size(); j++)
            dp[d][j] = min(dp[d-1][j], dp[d-1][j+(1<<(d-1))]);
    }
    for(int i = 0, l, r, d; i < n; i++){
        l = a[i].first;
        r = a[i].second - 1;
        d = id[r-l+1];
        if(min(dp[d][l], dp[d][r-(1<<d)+1]) != 1){
            cout << "Wrong Answer\n";
            return;
        }
    }
    cout << "Accepted\n";
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    id[0] = -1;
    for(int i=1; i <= 10001; i++) id[i] = id[i>>1] + 1;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}