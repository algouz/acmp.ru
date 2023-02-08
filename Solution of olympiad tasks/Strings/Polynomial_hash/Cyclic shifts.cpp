#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> suffix_sort(string s){
    int n = s.size(), classes;
    vector<pair<pair<int, int>, int> > v(n);
    vector<int> c(n);
    for(int i=0; i < n; i++)
        v[i] = {{s[i], s[i]}, i};
    sort(v.begin(), v.end());

    classes = 0;
    c[v[0].second] = classes;
    for(int i=1; i < n; i++){
        if(v[i].first != v[i-1].first) classes ++;
        c[v[i].second] = classes;
    }
    for(int h = 1; h < n; h *= 2){
        for(int i=0; i < n; i++)
            v[i] = {{c[i], c[(i+h)%n]}, i};
        sort(v.begin(), v.end());

        classes = 0;
        c[v[0].second] = classes;
        for(int i=1; i < n; i++){
            if(v[i].first != v[i-1].first) classes ++;
            c[v[i].second] = classes;
        }
    }
    for(int i=0; i < n; i++)
        c[i] = v[i].second;
    return c;
}

int main(){
    string a;
    cin >> a;
    vector<int> res = suffix_sort(a);
    int i = 0;
    while(res[i] != 0) i++;
    cout << i+1 << endl;
    for(int i=0; i < a.size(); i++)
        cout << a[(res[i]+a.size() - 1)%a.size()];
    return 0;
}