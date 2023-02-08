#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n, m, res=0;
    cin >> m >> n;
    int i=0, j=m-1;
    if(n*2 < m){
        cout << -1;
        return 0;
    }
    vector<int> a(m);
    for(int &x: a) cin >> x;
    sort(a.begin(), a.end());
    while(n+i < m){
        res += a[i]*a[j];
        i++; j--;
    }
    for(; i <= j; i++)
        res += a[i];
    cout << res;
    return 0;
}