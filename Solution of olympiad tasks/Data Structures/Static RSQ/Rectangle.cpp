#include <iostream>
using namespace std;
int a[101], dp[101][101];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, x, res = -100, s;
    cin >> n >> m;
    for(int q=0; q<n; q++){
        for(int i=0; i < m; i++) cin >> a[i];
        for(int r=0; r < m; r++){
            s = 0;
            for(int l=r; l >= 0; l--){
                s += a[l];
                res = max(res, dp[l][r] = max(dp[l][r], 0) + s);
            }
        }
    }
    cout << res;
}