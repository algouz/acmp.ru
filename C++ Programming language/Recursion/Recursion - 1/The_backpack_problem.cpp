#include<iostream>
using namespace std;
int w[20], n, res = 2000000;

void brute_force(int i, int r, int l){
    if(i == n){
        res = min(res, abs(r-l));
        return;
    }
    brute_force(i+1, r + w[i], l);
    brute_force(i+1, r, l + w[i]);
}

int main(){
    cin >> n;
    for(int i=0; i < n; i++)
        cin >> w[i];
    brute_force(0, 0, 0);
    cout << res;
    return 0;
}