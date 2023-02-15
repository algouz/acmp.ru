#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
	set<int> a;
	int n;
	string s;
	cin >> n;
	vector<int> a;
	for(int i=0; i < n; i++){
		cin >> s;
		for(char &x: s) x = tolower(x);
		cout << (s == "yes" ? "YES" : "NO");
		cout << '\n';
	}
	return 0;
}