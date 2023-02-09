#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x, m, l, r;
    cin >> n;
    long long a[n+1];
    a[0] = 0;
    cin >> a[1];
    for(int i=2; i <= n; i++){
        cin >> x;
        a[i] = a[i-1] + x;
        // cout << a[i] << ' ';
    }
    cin >> m;
    for(int i=0; i < m; i++){
        cin >> l >> r;
        cout << a[r] - a[l-1] << ' ';
    }
    return 0;
}