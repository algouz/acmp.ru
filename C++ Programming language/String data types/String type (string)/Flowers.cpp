#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    string a = "GCV";
    for(int i=0; i < n; i++){
        swap(a[1], a[2]);
        swap(a[0], a[1]);
    }
    cout << a;
}