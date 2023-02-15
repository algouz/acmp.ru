#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > a(n, vector<int> (m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
}