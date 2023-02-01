#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double a, b, c;
    cin >> a >> b >> c;
    cout.precision(4);
    cout << fixed;

    if(a==0){
        if(b==0)
            cout << (c==0? -1: 0) << endl;
        else cout << "1\n" << -c/b;
    }
    else{
        double D = pow(b, 2) - 4*a*c;
        if(D>0){
            cout << 2 << endl;
            cout << (-b+sqrt(D))/(2*a) << endl;
            cout << (-b-sqrt(D))/(2*a);
        }
        else if(D==0){
            cout << 1 << endl;
            cout << -b/(2*a);
        }
        else{
            cout << 0;
        }
    }
    return 0;
}