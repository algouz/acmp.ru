#include<iostream>
using namespace std;
int main(){
    int x, k=-1, s=0;
    do{
        cin >> x;
        k ++;
        s += x;
    }while(x != 0);
    cout << 1.0*s/k;
    return 0;
}