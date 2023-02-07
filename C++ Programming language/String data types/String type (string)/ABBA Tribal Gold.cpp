#include <bits/stdc++.h>
using namespace std;

bool mx(string a, string b){
    return a.size() > b.size() ? true: a.size() < b.size() ? false: a >= b;
}
int main(){
    string a, b, c;
    cin >> a >> b >> c;
    if(mx(a, b) && mx(a, c)) cout << a;
    else if(mx(b, c) && mx(b, a)) cout << b;
    else if(mx(c, a) && mx(c, b)) cout << c;
    return 0;
    
}