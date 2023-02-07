#include<iostream>
using namespace std;
int main(){
    int x = 0, mx = 0, cnt = 0;
    do{
        if(x > mx){
            mx = x;
            cnt = 1;
        }
        else if(x == mx) cnt ++;
        cin >> x;
    }while(x != 0);
    cout << cnt;
    return 0;
}