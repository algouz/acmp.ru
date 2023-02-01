#include<bits/stdc++.h>
using namespace std;
int res[21][21][21];
bool solved[21][21][21];

int F(int a, int b, int c){
    if(min({a, b, c}) <= 0) return 1;
    if(max({a, b, c}) > 20) return F(20, 20, 20);

    if(solved[a][b][c]) return res[a][b][c];
    solved[a][b][c]=true; 
    if(a < b && b < c) return res[a][b][c] = F(a, b, c-1) + F(a, b-1, c-1) - F(a, b-1, c);
    return res[a][b][c] = F(a-1, b, c) + F(a-1, b-1, c) + F(a-1, b, c-1) - F(a-1, b-1, c-1);
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << F(a, b, c);
    return 0;
}