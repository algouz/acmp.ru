#include<iostream>
using namespace std;
int main(){
    int l = 1, r = 1e1, m, d;
    long long s = 0, x;
    while(l != r){
        m = (l+r)/2;
        d = m-s%m;
        cout << "run " << d << endl;
        cin >> x;
        s += d;
        if(s/(x+1)+1 > l) l = s/(x+1)+1;
        if(x != 0 && s/x < r) r = s/x;
    }
    cout << "ensure " << l;
    return 0;
}