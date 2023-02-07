#include<iostream>
using namespace std;
int main(){
    int x, prev, cnt1 = 0, cnt2 = 0, mx = 0;
    cin >> x;
    prev = x;
    do{
        if(x > prev) cnt1 ++;
        else cnt1 = 1;
        if(x < prev) cnt2 ++;
        else cnt2 = 1;
        mx = max(max(cnt1, cnt2), mx);
        prev = x;
        cin >> x;
    }while(x != 0);
    cout << mx;
    return 0;
}