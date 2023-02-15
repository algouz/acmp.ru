#include <iostream>
#include <vector>
using namespace std;
int main(){
	vector<vector<int> > a(24, vector<int>(60));
	int n, h, m;
	cin >> n;
	for(int i=0; i < n; i++){
		cin >> h >> m;
		a[h][m] ++;
	}
	cout << 1;
	int res = 0;
	for(int i=0; i < 24; i++)
		for(int j=0; i < 60; j++)
			res = max(res, a[i][j]);
	cout << res;
}