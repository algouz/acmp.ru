#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<string, vector<string> > edges;
vector<string> func;
map<string, bool> used;

bool dfs(string u, string b){
    if(used[u]) return u==b;
    used[u] = true;
    for(string v: edges[u])
        if(dfs(v, b)) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string x;
    cin >> n;
    func.resize(n);
    for(int i=0; i < n; i++){
        cin >> func[i];
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> x;
            edges[func[i]].push_back(x);
        }
        cin >> x;
    }
    for(int i=0; i < n; i++){
        used.clear();
        if(dfs(func[i], func[i])) cout << "YES\n";
        else                      cout << "NO\n";
    }
    return 0;
}