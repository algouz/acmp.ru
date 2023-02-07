#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double x=0, sum1=0, sum2=0, k=-1;
    do{
        sum1 += x*x;
        sum2 += x;
        k ++;
        cin >> x;
    }while(x != 0);
    cout << sqrt((sum1 - sum2*sum2/k)/(k-1));
    return 0;
}