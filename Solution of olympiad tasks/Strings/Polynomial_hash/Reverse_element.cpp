#include<iostream>
#include<algorithm>
using namespace std;
int mod;
int binpow(int a, int b){
    if(b == 0) return 1;
    if(b%2==1) return (1LL*(a%mod)*(binpow(a, b-1)%mod))%mod;
    int x = binpow(a, b/2)%mod;
    return (1LL*x*x)%mod;
}

int phi (int n) {
	int result = n;
	for (int i=2; i*i<=n; ++i)
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	if (n > 1)
		result -= result / n;
	return result;
}

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int n;
    cin >> n >> mod;
    if(gcd(n, mod)!=1){
        cout << "No solution";
        return 0;
    }
    cout << (binpow(n, phi(mod)-1));
    return 0;
}