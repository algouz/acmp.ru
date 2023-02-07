#include<iostream>
#include <vector>
using namespace std;
using ll = long long;
int n, w[20], p[20], W, res = 2000000;
ll result_P;
vector<int> selected_ids, result_ids;
void brute_force(int i, int W, int P){
    if(W > ::W) return;
    if(i == n){
        if(result_P < P){
            result_P = P;
            result_ids = selected_ids;
        }
        else if(result_P == P && result_ids.size() > selected_ids.size())
            result_ids = selected_ids;
        else if(result_P == P && result_ids.size() == selected_ids.size() && result_ids > selected_ids)
            result_ids = selected_ids;
        return;
    }
    selected_ids.push_back(i);
    brute_force(i+1, W + w[i], P+p[i]);
    selected_ids.pop_back();
    brute_force(i+1, W, P);
}

int main(){
    cin >> n >> W;
    for(int i=0; i < n; i++)
        cin >> w[i] >> p[i];
    brute_force(0, 0, 0);
    cout << result_ids.size() << ' ' << result_P << '\n';
    for(auto x: result_ids) cout << x+1 << ' '; 
    return 0;
}