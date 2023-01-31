#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, x;
    cin >> n;
    vector<bool> origin(n, true), drain(n, true);
    for(int i=0; i < n; i++)
        for(int j=0; j < n; j++){
            cin >> x;
            if(x==1){
                origin[j] = false;
                drain[i] = false;
            }
        }
    int a=0, b=0;
    for(int i=0; i < n; i++){
        if(origin[i]) a++;
        if(drain[i]) b++;
    }
    cout << a;
    for(int i=0; i < n; i++)
        if(origin[i]) cout << ' ' << i+1;
    cout << '\n' << b;
    for(int i=0; i <n; i++)
        if(drain[i]) cout << ' ' << i+1;
}