#include<iostream>
#include<algorithm>
#include<vector>
#include<memory.h>
#define x first
#define y second
using namespace std;

int n, m;
int mm[109][109];
bool f=true;
vector<pair<int, int> >dd = {
    {2, -1}, {2, 1}, {1, -2}, {1, 2}, {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}
};

void rec(int i, int j, int step){
    mm[i][j] = step;
    if(step == n*m){
        for(int i=2; i < n+2; i++){
            for(int j=2;j < m+2; j++)
                cout << mm[i][j] << ' ';
            cout << '\n';
            }
        f = false;
        return;
    }
    vector<pair<int, int> >v;
    for(auto it(dd.begin()); it != dd.end(); it++)
        if(!mm[i + it->x][j + it->y])
        v.push_back({
            count_if(dd.begin(), dd.end(), [&](pair<int, int> p){
                return !mm[i + it ->x + p.x][j + it ->y + p.y];
            }),
            it - dd.begin()
        });
    

    auto k = min_element(v.begin(), v.end());
    if(k != v.end())
        rec(i + dd[k->second].x, j + dd[k -> second].y, step+1);

    mm[i][j] = 0;
}


int main(){
    srand(1619);
    cin >> n >> m;
    char s[109];
    int bi = -1, bj = -1;
    memset(mm, -1, sizeof(mm));
    for(int i=0; i < n; i++){
        cin >> s;
        for(int j=0; j < m; j++){
            if(s[j] == 'K')
                bi = i+2, bj = j+2;
            mm[i+2][j+2] = 0;
        }
    }

    while(f){
        random_shuffle(dd.begin(), dd.end());
        rec(bi, bj, 1);
    }
    return 0;
}