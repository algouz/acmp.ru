#include <iostream>
using namespace std;

bool check(int n){
    int res = n%10;
    do{
        if(n%10 != res) return false;
        n /= 10;
    }while(n != 0);
    return true;
}

int main(){
    int l, r, k=0;
    cin >> l >> r;
    for(int i=l; i <= r; i++)
        if(check(i)) k ++;
    cout << k;
    return 0;
}