#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> suffix_sort(string s){
    int n = (int)s.size();
    vector<pair<pair<int, int>, int> > v(n);
    vector<int> c(n);
    for(int i = 0; i < n; i++)
        v[i] = make_pair(make_pair(s[i], s[i]), i);
    sort(v.begin(), v.end());
    int classes = 0;
    c[v[0].second] = classes;
    for(int i=1; i < n; i++){
        if(v[i-1].first != v[i].first) classes ++;
        c[v[i].second] = classes;
    }

    for(int h=0; (1<<h) < n; h++){
        for(int i=0; i < n; i++)
            v[i] = make_pair(make_pair(c[i], c[(i+(1<<h))%n]), i);
        sort(v.begin(), v.end());
        classes = 0;
        c[v[0].second] = classes;
        for(int i=1; i < n; i++){
            if(v[i-1].first != v[i].first) classes ++;
            c[v[i].second] = classes;
        }
    }
    return c;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    vector<int> c = suffix_sort(s);
    int i = 0;
    while(c[i] != 0)  i++;
    cout << s.substr(i) << s.substr(0, i) << '\n';
    return 0;
}