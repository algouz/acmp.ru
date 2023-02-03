#include<iostream>
using namespace std;
int main(){
    int x1, x2, y1, y2;
    char X1, X2;
    cin >> X1 >> y1 >> X2 >> y2;
    x1 = X1 - 96;
    x2 = X2 - 96;
    if((x1 + y1)%2 != (x2 + y2)%2){
        cout << -1;
        return 0;
    }
    int d = abs(x1-x2) + abs(y1-y2);
    cout << d/2;
    return 0;
}