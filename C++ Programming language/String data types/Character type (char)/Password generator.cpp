#include <iostream>
using namespace std;
int main(){
    int n, a, b, c;
    cin >> n >> a >> b;
    c = n-a-b;
    char s;
    for(int i=0; i < a; i++) cout << "AB"[i & 1];
    for(int i=0; i < b; i++) cout << "ab"[i & 1];
    for(int i=0; i < c; i++) cout << "01"[i & 1];
    return 0;
}   