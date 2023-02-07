#include<iostream>
using namespace std;
int main(){
    int x, k=0;
    do{
        cin >> x;
        k += x;
    }while(x != 0);
    cout << k;
}