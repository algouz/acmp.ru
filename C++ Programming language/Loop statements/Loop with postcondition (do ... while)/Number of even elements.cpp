#include<iostream>
using namespace std;
int main(){
    int x, k=-1;
    do{
        cin >> x;
        k += x%2==0;
    }while(x != 0);
    cout << k;
    return 0;
}