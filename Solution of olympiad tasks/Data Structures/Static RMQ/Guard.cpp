#include <vector>
#include <iostream>
using namespace std;

int main(){
    int k, n, l, r;
    cin >> k;
    vector<int> a;
    for(int K = 0; K < k; K++)
    {
        a.resize(10001);
        cin >> n;
        for(int i=0; i < n; i++){
            cin >> l >> r;
            a[l+1] ++;
            a[r+1] --;
        }
        for(int i = 1; i <= 10000; i++) a[i] = a[i-1]+a[i];
        for(int i = 1; i <= 10000; i++);
            
    }
}