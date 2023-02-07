#include<iostream>
using namespace std;
int main(){
    int x = 1, sum = 0, cnt = 0, prev;
    do{
        prev = x;
        cin >> x;
        sum += x;
    }while( x != 0 || prev != 0);
    cout << sum;
    return 0; 
}