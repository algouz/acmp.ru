#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> s(n);
    for(int &x: s) cin >> x;
    next_permutation(s.begin(), s.end());
    for(int x: s) cout << x << ' ';
    return 0;
}