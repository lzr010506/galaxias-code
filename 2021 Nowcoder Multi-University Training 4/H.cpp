#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+5,mod=998244353;
ll gcd(ll a,ll b) {
	return a%b==0?b:gcd(a%b,b);
}
ll pow(ll a,ll b) {
	ll ret=1;
	while(b) {
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}
ll a[N],b[N],f[N],dp[N];
ll n,c;
int main() {
	scanf("%lld %lld",&n,&c);
	for(int i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		f[i]=pow(1ll*i,c);
	}
	for(int i=1; i<=n; i++) {
		for(int j=1; j*i<=n; j++)
			dp[j]=(dp[j-1]+a[i*j]*f[i*j]%mod)%mod;
		for(int j=1; j*i<=n; j++) {
			if(__gcd(i,j)!=1)
				continue;
			b[i*j]=(b[i*j]+f[j]*pow(f[i],mod-2)%mod*dp[min(n/i,n/j)]%mod)%mod;
		}
	}
	for(int i=2; i<=n; i++)
		b[i]^=b[i-1];
	printf("%lld\n",b[n]);
}