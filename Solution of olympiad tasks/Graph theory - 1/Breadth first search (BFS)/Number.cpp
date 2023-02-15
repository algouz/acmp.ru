#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i * i <= n; i += 6)
        if(n % i == 0 || n % (i+2) == 0) return false;
    return true;
}
int main(){
    int n, m;
    cin >> n;
    vector<int> dist(10000, -1);
    queue<int> b;
    auto add = [&](int x, int d){
        if(dist[x] == -1){
            dist[x] = d;
            b.push(x);
        }
    };
    add(n, 0);
    while(!b.empty()){
        n = b.front();
        b.pop();
        if(isPrime(n)){
            m = n;
            break;
        }
        if(n < 9000) add(n+1000, n);
        if(n % 10 > 1) add(n-1, n);
    }
    vector<int> res;
    while(m != 0){
        res.push_back(m);
        m = dist[m];
    }
    for(int i = res.size()-1; i >= 0; i--) cout << res[i] << '\n';
    return 0;
}