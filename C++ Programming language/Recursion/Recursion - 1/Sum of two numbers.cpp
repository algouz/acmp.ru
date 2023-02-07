#include <iostream>
using namespace std;
int c, y, cnt_b[10], A = 1e9;
string a, b, x;
bool check(int n){
    if(n < 0) return false;
    int cnt[] = {0,0,0,0,0,0,0,0,0,0};
    do{
        cnt[n%10] ++;
        n /= 10;
    }while(n > 0);
    if(cnt_b[0] < cnt[0]) return false;
    for(int i = 1; i <= 9; i++)
        if(cnt_b[i] != cnt[i])
            return false;
    return true;
}

void brute_force(int i){
    if(i == a.size()){
        y = stoi(x);
        if(check(c-y) && y < A)
            A = y;
        return;
    }
    for(int j=0; j < a.size(); j++){
        if(a[j] == ' ') continue;
        x[i] = a[j];
        a[j] = ' ';
        brute_force(i+1);
        a[j] = x[i];
    }
}

int main(){
    cin >> a >> b >> c;
    x.resize(a.size());
    for(char c: b) cnt_b[c-'0'] ++;
    brute_force(0);
    if(A == 1e9)
    cout << "NO";
    else cout << "YES\n" << A << ' ' << c-A; 
    return 0;
}