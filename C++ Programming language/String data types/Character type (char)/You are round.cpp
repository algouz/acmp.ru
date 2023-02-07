#include <iostream>
using namespace std;
int main(){
    char c;
    int cnt = 0;
    while(cin >> c){
        switch(c){
            case '6':
            case '9':
            case '0': cnt += 1; break;
            case '8': cnt += 2; break;
            default: break;
        }
    }
    cout << cnt;
}