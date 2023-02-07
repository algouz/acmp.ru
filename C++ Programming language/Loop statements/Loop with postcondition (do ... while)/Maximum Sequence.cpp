#include<iostream>
using namespace std;
int main(){
    int x, k=-101;
    do{
        cin >> x;
        k = max(k, x);
    }while(x != 0);
    cout << k;
    return 0;
}