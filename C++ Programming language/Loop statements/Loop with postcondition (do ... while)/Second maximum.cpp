#include<iostream>
using namespace std;
int main(){
    int x = 0, mx = 0, mx2 = 0;
    do{
        if(x > mx){
            mx2 = mx;
            mx = x;
        }
        else if(x > mx2) mx2 = x;
        cin >> x;
    }while(x != 0);
    cout << mx2;
    return 0;
}