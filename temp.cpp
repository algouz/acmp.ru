#include <vector>
#include <iostream>
using namespace std;

int main(){
  	ios::sync_with_stdio(false);
  	cin.tie(nullptr);
  	cout.tie(nullptr);
    int n, q, l, r, x;
    cin >> n >> q;
    vector<long long> b(n+2);
    for(int Q = 0; Q < q; Q++){
            cin >> l >> r >> x;
            b[l] += x;
            b[r+1] -= x;
        }
  		long long z = 0;
        for(int i = 1; i <= n; i++){
            z = z + b[i];
          	cout << z << ' ';
        }
    return 0;
}