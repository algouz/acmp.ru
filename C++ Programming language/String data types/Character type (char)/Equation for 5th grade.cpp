#include <iostream>
using namespace std;
int main(){
    char x, y, z, c, o;
    cin >> x >> o >> y >> c >> z;
    if(x == 'x')
        cout << (o == '+' ? z-y: z + y-96);
    if(y == 'x')
        cout << (o == '+' ? z-x: x-z);
    if(z == 'x')
        cout << (o == '+' ? x+y-96: x-y);
    return 0;
}