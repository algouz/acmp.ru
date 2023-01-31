#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(101);
    for(int i=1, u, v; i <= n; i++){
	cin >> u >> v;
	a[u]++;
	a[v]++;
    }
    int cnt = 0;
    for(int u: a) if(u>1) cnt ++;
    cout << cnt;
    return 0;
}
