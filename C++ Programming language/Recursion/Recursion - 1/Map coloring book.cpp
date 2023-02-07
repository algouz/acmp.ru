#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<vector<int> > a;
vector<int> color;
bool check(int d){
    if(d == n) return true;
    vector<bool>used(k);
    for(int q: a[d]) used[color[q]] = true;
    for(int r=0; r<k; r++){
        if(used[r]) continue;
        color[d] = r;
        if(check(d+1)) return true;
    }
    return false;
}

int main(){
    cin >> n;
    color.resize(n);
    a.resize(n);
    for(int i=0, x; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> x;
            if(x==1 && i > j) a[i].push_back(j);
        }
    }
    do{
        k ++;
    }while(!check(0));
    for(int r: color) cout << r + 1 << ' ';
    return 0;
}