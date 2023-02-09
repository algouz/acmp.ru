#include <iostream>
#include <vector>
using namespace std;

int prefix(string s){
    int n = s.size();
    vector<int> p(n);
    for(int i=1, j; i < n; i++){
        j = p[i-1];
        while(j > 0 && s[i] != s[j]) j = p[j-1];
        if(s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p.back();
}

int main(){
    string a, b;
    cin >> a >> b;
    int val = prefix(b+'#'+a);
    int k=0;
    while(k < a.size() && a[k] == b[b.size() - k - 1]) k++;
    if(k + val < a.size() || a.size() != b.size()) cout << "No" << endl;
    else cout << "Yes\n" << a.size() - val << endl;
    return 0;
}