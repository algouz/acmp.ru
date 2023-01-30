#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_sum(string s){
    vector<int> p(s.size());
    for(int i = 1, j; i < s.size(); i ++){
        j = p[i-1];
        while(j > 0 && s[i] != s[j]) j = p[j - 1];
        if(s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}
int main(){
    string s;
    cin >> s;
    for(int x: prefix_sum(s)) cout << x << ' ';
    return 0;
}