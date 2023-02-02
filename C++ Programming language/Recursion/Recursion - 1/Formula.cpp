#include<iostream>
using namespace std;
string s;
int id;
int formula(){
    int res;
    if(isdigit(s[id])){
        res = s[id] - '0';
        id ++;
        return res;
    }
    char f = s[id];
    id += 2;
    int a = formula();
    id ++;
    int b = formula();
    id ++;
    res = f == 'M'? max(a, b) : min(a, b);
    return res;
}
int main(){
    cin >> s;
    cout << formula();
    return 0;
}