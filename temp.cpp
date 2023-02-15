#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main()
{
	string s = "1234";
	cout << s.substr(1) + s[0] << endl;
	cout << s.back() + s.substr(0, 3);
}