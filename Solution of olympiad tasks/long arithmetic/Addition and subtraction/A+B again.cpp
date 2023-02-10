#include <iostream>
#include <vector>
using namespace std;
int main(){
    string a, b, c;
    cin >> a >> b;
    int k=0, s;
    if(a.size() < b.size()) a = string(b.size()-a.size(), '0') + a;
    else b = string(a.size()-b.size(), '0') + b;
    c.resize(a.size(), '0');
    for(int i=a.size()-1; i >= 0; i--){
        s = a[i] - '0' + b[i] - '0' + k;
        k = s/10;
        c[i] = s%10+'0';
    }
    if(k > 0)
        c = char(k+'0') + c;
    cout << c;
    return 0;
}