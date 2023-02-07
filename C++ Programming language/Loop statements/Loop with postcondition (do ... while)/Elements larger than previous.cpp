#include<iostream>
using namespace std;
int main(){
    int x, k=0, ans=100000;
    do{
        cin >> x;
        if(x > ans) k++;
        ans = x;
    }while(x != 0);
    cout << k;
    return 0;
}