#include<iostream>
#include<set>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int k, n, m;
    cin >> k >> n >> m;
    set<string> s;
    string res;
    vector<vector<string> > a(k, vector<string>(n));
    for(int K=0; K < k; K++)
        for(int i=0; i < n; i++)
            cin >> a[K][i];
    for(int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            res.clear();
            for(int K=0; K < k; K++){
                res += a[K][i][j];
            }
            s.insert(res);
        }
    }
    cout << s.size();
    return 0;
}