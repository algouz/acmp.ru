#include <iostream>
#include <algorithm>
#include <vector> 
using namespace std;
int main(){
    int n, k, cnt = 0;
    bool f;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i < n; i++) a[i] = i+1;
    do{
        f = true;
        for(int i=1; i < n; i++)
            if(abs(a[i] - a[i-1]) > k) f = false;
        cnt += f;
    }while(next_permutation(a.begin(), a.end()));
    cout << cnt;
    return 0;
}