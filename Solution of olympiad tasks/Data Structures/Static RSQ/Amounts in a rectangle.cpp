#include <iostream>
#include <vector>
using namespace std;
// int a[1001][1001];
vector<vector<int> > a(1001, vector<int>(1001));
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k, x1, y1, x2, y2, x;
    cin >> n >> m >> k;
    for(int i=1; i <= n; i++){
        for(int j=1; j <= m; j++){
            cin >> x;
            a[i][j] = a[i][j-1] + a[i-1][j] - a[i-1][j-1] + x;
            // cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    for(int i=0; i < k; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << a[x2][y2] - a[x2][y1-1] - a[x1-1][y2] + a[x1-1][y1-1] << endl;
    }
    return 0;
}