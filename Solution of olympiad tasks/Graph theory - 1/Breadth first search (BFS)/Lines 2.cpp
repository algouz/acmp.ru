#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<pair<int, int> >> dist(250, vector<pair<int, int> >(250, make_pair(-1, -1)));
vector<vector<char> > a;
queue<pair<int, int> > b;
int n;

void add(int _x1, int _y1, int _x2, int _y2){
    if(_x1 < 0 || _x1 >= n || _y1 < 0 || _y1 >= n || a[_x1][_y1] == 'O' || dist[_x1][_y1] != make_pair(-1, -1)) return;
    b.push(make_pair(_x1, _y1));
    dist[_x1][_y1] = make_pair(_x2, _y2);
}

int main(){
    int _x1, _y1, _x2, _y2, x, y;
    cin >> n;
    a.resize(n+1, vector<char>(n+1));
    // cout << 1;
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            cin >> a[i][j];
            // cout << 1;
            if(a[i][j] == 'X'){
                _x1 = i;
                _y1 = j;
            }
            if(a[i][j] == '@'){
                _x2 = i;
                _y2 = j;
            }
        }
    }
    //cout << 1;
    //return 0;
    add(_x1, _y1, n, n);
    while(!b.empty()){
        x = b.front().first;
        y = b.front().second;
        b.pop();
        add(x+1, y, x, y);
        add(x-1, y, x, y);
        add(x, y+1, x, y);
        add(x, y-1, x, y);
    }
    if(dist[_x2][_y2] == make_pair(-1, -1)){
        cout << "N";
        return 0;
    }
    _x2 = dist[_x2][_y2].first;
    _y2 = dist[_x2][_y2].second;
    
    while(!(_x2 == n && _y2 == n)){
        a[_x2][_y2] = '+';
        int l = dist[_x2][_y2].first;
        int r = dist[_x2][_y2].second;
        _x2 = l;
        _y2 = r;
    }
    cout << "Y\n";
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++)
            cout << a[i][j];
        cout << '\n';
    }
    return 0;
}