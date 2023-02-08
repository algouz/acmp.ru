#include <iostream>
using namespace std;

int get(int n, int k){
    if(n == 0) return 1;
    if(k*(k+1)/2 > n) return 0;
    if(n < k) k = n;
    int res = 0;
    for(int i=k; i >= 0; i--)
        res += get(n-i, i-1);
    return res;
}

int main(){
    int n;
    cin >> n;
    cout << get(n, n);
    return 0;
}