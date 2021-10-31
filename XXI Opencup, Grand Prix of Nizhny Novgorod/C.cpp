#include<bits/stdc++.h>

#define mod 998244353
using namespace std;
typedef long long ll;

int qpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b&1) res=1ll*res*a%mod;
		b>>=1;
		a=1ll*a*a%mod;
	}
	return res;
}



int C(int n, int m) {
	int tmp1, tmp2;
	tmp1=tmp2=1;
	for(int i=n; i>=n-m+1; i--) tmp1 = 1ll*tmp1*i%mod,tmp2 = 1ll*tmp2*(n-i+1)%mod;
	return 1ll*tmp1*qpow(tmp2,mod-2)%mod;

}

int phi(int n) {
	int res=n,a=n;
	for(int i=2; i*i<=a; i++) {
		if(a%i==0) {
			res=res/i*(i-1);
			while(a%i==0) a/=i;
		}
	}
	if(a>1) res=res/a*(a-1);
	return res;
}


signed main() {
	int n, k;
	cin >> n >>k;
	cout << 1ll*C(n-1,k-1)*phi(n)%mod << endl;
}