#include<iostream>
using namespace std;
int main(){
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if(y1 == y2) y = 2*y1 - y;
    else x = 2*x1 - x;
    cout << x << ' ' << y;
}