#include<iostream>
using namespace std;
string s, a;
void rec(int n){
    if(n == a.size()){
        cout << a << '\n';
        return;
    }
    for(int i = 0; i<s.size(); i++){
        if(s[i] == ' ') continue;
        a[n] = s[i];
        s[i] = ' ';
        rec(n+1);
        s[i] = a[n];
    }
}
int main(){
    cin >> s;
    a.resize(s.size());
    rec(0);
    return 0;
}