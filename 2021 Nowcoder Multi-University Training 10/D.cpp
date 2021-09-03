#include<bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
const int maxn = 2e6+50;
ll fac[maxn];
ll inv[maxn];
int mod;
ll qpow(long long a,long long b) {
	ll ans=1;
	ll k=a;
	while(b) {
		if(b&1)ans=ans*k%mod;
		k=k*k%mod;
		b>>=1;
	}
	return (ans+mod)%mod;
}
void init(int xx) {
	long long it;
	fac[0]=1;
	inv[0]=1;
	fac[1]=1;
	inv[1]=1;
	for(int i=2; i<=xx; i++)
		fac[i]=fac[i-1]*i%mod,inv[i]=mod-(mod/i)*inv[mod%i]%mod;
	for(int i=1; i<=xx; i++)
		inv[i]=inv[i-1]*inv[i]%mod;
}
ll C(ll n,ll m) {
	if (n<m||m<0) return 0;
	return  (fac[n]*inv[m]%mod*inv[n-m]%mod+mod)%mod;
}

int f[505][505], g[2][505][505], h[505][505];

signed main() {

	int n, p;
	cin >> n >> p;
	mod = p;
	init(505);
	int inv2 = qpow(2,p-2);
	g[0][0][0] = 1;
	for(int i=1; i<=n; i++) {
		if(i == 1) f[i][1] = 1;
		int cur = 1;
		g[i&1][0][0] = 1;
		for(int k=0; k<=n-i; k++) {
			g[i&1][0][k] = cur;
			cur *= i;
			cur %= mod;
		}
		for(int j=1; j<=i; j++) {
			for(int k=j; k<=n-i; k++) {
				g[i&1][j][k] = (i*g[i&1][j][k-1]%mod + j*g[(i&1)^1][j-1][k-1]%mod)%mod;
			}
		}

		if(i == 1) {
			for(int j=1; j<=i; j++) {

				f[2][2] += 1;
				f[2][2] %= mod;
				h[2][2] = 1;
				for(int k=2; k<=n-i; k++) {
					f[i+k][k] += f[i][j]*g[i&1][j][k]%mod*C(i+k,i)%mod;
					f[i+k][k] %= mod;
					h[i+k][k] += (2ll*f[i][j]*g[i&1][j][k]%mod*C(i+k,i)%mod+g[i&1][j][k]*h[i][j]%mod)%mod;
					h[k+i][k] %= mod;
				}
			}
		}

		else {

			for(int j=1; j<=i; j++) {

				for(int k=j; k<=n-i; k++) {
					f[i+k][k] += f[i][j]*g[i&1][j][k]%mod*C(i+k,i)%mod;
					f[i+k][k] %= mod;
					h[i+k][k] += (2ll*f[i][j]*g[i&1][j][k]%mod*C(i+k,i)%mod+g[i&1][j][k]*h[i][j]%mod*C(i+k,i)%mod)%mod;
					h[k+i][k] %= mod;
				}
			}
		}

	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		ans += h[n][i];
		ans %= mod;
	}
	cout << ans << endl;



}