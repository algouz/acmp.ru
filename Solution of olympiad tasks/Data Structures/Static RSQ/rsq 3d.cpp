#include <iostream>
using namespace std;
int dp[101][101][101];
int main(){
    int h, n, m, q;
    char c;
    cin >> h >> n >> m >> q;
    for(int x = 1; x <= h; x++)
        for(int y=1; y <= n; y++)
            for(int z=1; z <= m; z++){
                cin >> c;
                dp[x][y][z] = dp[x-1][y][z] + dp[x][y-1][z] + dp[x][y][z-1] - dp[x-1][y-1][z] - dp[x][y-1][z-1] - dp[x-1][y][z-1] + dp[x-1][y-1][z-1] + (c-48);
            }
    for(int i=0, x1, x2, y1, y2, z1, z2; i < q; i++){
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        if(x1 > x2) swap(x1, x2);
        if(y1 > y2) swap(y1, y2);
        if(z1 > z2) swap(z1, z2);
        cout << dp[x2][y2][z2] - dp[x1-1][y2][z2] - dp[x2][y1-1][z2] - dp[x2][y2][z1-1] + dp[x2][y1-1][z1-1] + dp[x1-1][y1-1][z2] + dp[x1-1][y2][z1-1] - dp[x1-1][y1-1][z1-1] << endl; 
    }
    return 0;
}