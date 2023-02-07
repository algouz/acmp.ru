#include<iostream>
using namespace std;
int main(){
    int x, cur, prev, cnt=0;
    cin >> prev >> cur >> x;
    do{
        if(cur > prev && cur > x) cnt ++;
        prev = cur;
        cur = x;
        cin >> x;
    }while(x != 0);
    cout << cnt;
    return 0;
}