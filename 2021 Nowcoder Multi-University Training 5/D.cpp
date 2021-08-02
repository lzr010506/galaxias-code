#include<bits/stdc++.h>
#define maxn 5005
#define int long long
#define mod 1000000007
using namespace std;
typedef long long ll;
int dp[5005][5005], dp1[5005][5005];
char s[maxn], t[maxn];


ll fac[maxn*2];
ll inv[maxn*2];
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



int cal(int x, int y) {
	return C(x+y,y);
}

signed main() {
	int n, m;
	init(10001);
	scanf("%s%s",s+1,t+1);
	n = strlen(s+1), m = strlen(t+1);
	for(int i=1;i<=n;i++) {
		
		
		for(int j=1;j<=m;j++) {
			if(s[i] == t[j]) {
				dp[i][j] += (dp[i-1][j-1]+1)%mod;
				dp[i][j] %= mod;
			}
		}
		for(int j=1;j<=m;j++) {
			dp[i][j] += dp[i][j-1];
			dp[i][j] %= mod;
		}
		for(int j=1;j<=m;j++) {
			dp[i][j] += dp[i-1][j];
			dp[i][j] %= mod;
		}
		
	}
	
//	for(int i=n;i>=1;i--) {
//		
//		for(int j=n;j>=1;j--) {
//			dp1[i][j] = dp1[i+1][j];
//		}
//		for(int j=n;j>=1;j--) {
//			if(s[i] < t[j]) {
//				dp1[i][j] += dp1[i+1][j+1];
//				dp1[i][j] %= mod;
//			}
//		}
//	}
	ll ans = 0;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(s[i] < t[j]) {
			//	cout << i << " "<< j<< " " << dp[i-1][j-1] << endl;
				ans += (dp[i-1][j-1]+1)%mod*cal(min(n-i, m-j), max(n-i,m-j))%mod;
				ans %= mod;
			}
		}
	}
	cout << ans << endl;
	
}