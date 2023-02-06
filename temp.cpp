#include<iostream>
using namespace std;
int main(){
    string a, s;
    cin >> a >> s;
    int k=0;
    while(a.find(s) == string::npos){
        for(char &c: a) c = (c == 'A' ? 'Z' : c-1);
        k ++;
        if(k == 30){
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << a;
    return 0;
}