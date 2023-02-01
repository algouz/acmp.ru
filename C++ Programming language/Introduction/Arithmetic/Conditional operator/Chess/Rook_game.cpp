#include<iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    cout << (a==b && b==1? 0: a==b? 2: 1);
    return 0;
}