#include<iostream>
using namespace std;
int main(){
    int x, cur, prev, cnt=1, dist = 101;
    bool f=false;
    cin >> prev >> cur >> x;
    do{
        if(cur > prev && cur > x){
            if(f) dist = min(dist, cnt);
            else f = true;
            cnt = 1;
        }
        else cnt ++;
        prev = cur;
        cur = x;
        cin >> x;
    }while(x != 0);
    cout << (dist == 101 ? 0: dist);
    return 0;
}