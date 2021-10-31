#include<bits/stdc++.h>
#define int long long
#define mod 1000000000000000031
using namespace std;
typedef long long ll;

ll qmul(ll a, ll b) {
	long double tmp = ((long double)a*b/mod);
	ll tmpp = (ll) tmp;
	ll res = a*b-tmpp*mod;
	res %= mod;
	res += mod;
	res %= mod;
	return res;

}

ll qpow(ll a, ll b) {
	ll res = 1;
	while(b) {
		if(b&1) res=qmul(res,a);
		a=qmul(a,a);
		b>>=1;
	}
	return res;
}

signed main() {
	long long n;
	int x = 300;
	scanf("%lld",&n);
	for(int i=1; i<=1000000-n; i++) {
		x = qpow(42, x);
	}
	cout << x << endl;
}