#include <iostream>
using namespace std;
int yuza(int x1, int y1, int x2, int y2, int x3, int y3){
    return abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2));
}
int main(){
    int x1, y1, x2, y2, x3, y3, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x >> y;
    if(yuza(x1, y1, x2, y2, x3, y3) == yuza(x1, y1, x2, y2, x, y) + yuza(x1, y1, x, y, x3, y3) + yuza(x, y, x2, y2, x3, y3))
        cout << "In";
    else cout << "Out";
    return 0;
}