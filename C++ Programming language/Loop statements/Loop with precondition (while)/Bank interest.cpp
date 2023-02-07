#include<iostream>
#include<cmath>
using namespace std;
int main(){
    float x, p, y;
    cin >> x >> p >> y;
    x *= 100;
    y *= 100;
    int i=0;
    while(i++, x < y) x = (int)x + x/100*p;
    cout << --i;
}