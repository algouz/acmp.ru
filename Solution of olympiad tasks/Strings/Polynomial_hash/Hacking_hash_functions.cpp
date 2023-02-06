#include<iostream>
#include<vector>
using namespace std;
int main(){
    int x, xd, m, l, v;
    cin >> x >> m >> l >> v;
    vector<vector<string> > dp(l+1, vector<string>(m));
    dp[0][0] = "0";
    xd = 1;
    for(int n = 0; n < l; n++){
        for(int h=0; h < m; h++)
            if(!dp[n][h].empty())
                for(int i=0; i <= 9; i++)
                    dp[n+1][(h + i*xd)%m] = dp[n][h] + char(i+48);
        xd = (xd*x)%m;
    }
    cout << (dp[l][v].empty() ? "NO SOLUTION" : dp[l][v].substr(1));
    return 0;
}