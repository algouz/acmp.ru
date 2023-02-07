#include<iostream>
using namespace std;
int main(){
    int x = -1, cnt = 0, prev, mx=0;
    do{
        prev = x;
        cin >> x;
        if(x == prev) cnt ++;
        else{
            mx = max(mx, cnt);
            cnt = 1;
        }
    }while(x != 0);
    cout << mx;
    return 0; 
}