#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

string add(int a, int b, int c){
    string x = to_string(a), y = to_string(b), z = to_string(c), res, res2;
    int n = max(x.size(), y.size());
    x = string(n-x.size(), '0') + x;
    y = string(n-y.size(), '0') + y;
    for(int i=n-1; i >= 0; i--)
        res = to_string(x[i] - '0' + y[i] - '0') + res;
    
    n = max(res.size(), z.size());
    z = string(n-z.size(), '0') + z;
    for(int i=n-1; i >= 0; i--)
        res2 = to_string(res[i] - '0' + z[i] - '0') + res2;
    return res2;

}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    vector<string> s;
    s.push_back(add(a,b,c));
    s.push_back(add(a,c,b));
    s.push_back(add(b,a,c));
    s.push_back(add(b,c,a));
    s.push_back(add(c,b,a));
    s.push_back(add(c,a,b));
    sort(s.begin(), s.end(), [&](string l, string r){return l.size() < r.size()? true: l.size() > r.size()? false: l < r;});
    vector<string> n;
    n.push_back(s[0]);
    for(int i=1; i< s.size(); i++)
        if(s[i] != s[i-1]) n.push_back(s[i]); 
    
    if(n.size() == 1){
        cout << "NO\n";
        cout << n.front();
    }
    else{
        cout << "YES\n";
        for(auto i: n) cout << i << endl;
    }
    return 0;
}