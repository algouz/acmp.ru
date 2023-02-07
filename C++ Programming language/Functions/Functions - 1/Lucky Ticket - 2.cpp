#include <iostream>
using namespace std;

int sum_of_digits(int n){
    int s = 0;
    while(n != 0){
        s += n % 10;
        n /= 10;
    }
    return s;
}

int digital_root(int n){
    while (n >= 10)   n = sum_of_digits(n);
    return n;
}

int digital_root(string n){
    int s = 0;
    for(char c: n) s += c - '0';
    return digital_root(s);
}

int main(){
    string s;
    cin >> s;
    for(int l=1; l < s.size(); l ++){
        if(digital_root(s.substr(0, l)) == digital_root(s.substr(l))){
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}