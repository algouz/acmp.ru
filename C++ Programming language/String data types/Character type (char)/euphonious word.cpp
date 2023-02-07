#include <iostream>
using namespace std;
int main(){
    bool last = true, now;
    int cnt = 0, res=0;
    char c;
    while(cin >> c){
        now = c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
        if(now == last) cnt ++;
        else{
            res += (cnt-1)/2;
            cnt = 1;
            last = now;
        }
    }
    res += (cnt-1)/2;
    cout << res;
}