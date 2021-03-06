#include<bits/stdc++.h>
#define maxn 200005
#define maxm 25
#define mod 1000000007
#define int long long
using namespace std;

int f[maxm+2][maxn];
int cur[maxn];
int a[maxn], b[maxn], len[maxn];
signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	for(int i=0; i<n; i++) scanf("%lld",&a[i]);
	b[0] = a[0]%k;
	f[0][0]++;
	for(int i=1; i<n; i++) {
		b[i] = (b[i-1]+a[i])%k;
		f[0][b[i-1]%k]++;
		f[0][b[i-1]%k] %= mod;
	}

	int tmp = b[n-1];
	for(int i=0; i<maxm; i++) {
		len[i] = tmp;
		tmp *= 2;
		tmp %= k;
	}

	for(int i=1; i<maxm; i++) {
		for(int j=0; j<k; j++) {
			f[i][j] = (f[i-1][j]+f[i-1][(j-len[i-1]+k)%k])%mod;
		}
	}


	tmp = 0;

	for(int i=maxm-1; i>=0; i--) {
		if(!(m&(1ll<<i))) continue;
		for(int j=0; j<k; j++) {
			cur[j] += f[i][(j-tmp+k)%k];
			cur[j] %= mod;
		}
		tmp += len[i];
		tmp %= k;
	}

	int ans = 0;
	if(tmp == 0) {
		cur[0]--;
		cur[0] += mod;
		cur[0] %= mod;

		ans += cur[0];
		ans %= mod;
		cur[tmp]++;
		cur[tmp] %= mod;

		for (int i=0; i<n-1; i++) {
			cur[b[i]]--;
			cur[b[i]] += mod;
			cur[b[i]] %= mod;

			ans += cur[b[i]];
			ans %= mod;
			cur[(tmp+b[i])%k]++;
			cur[(tmp+b[i])%k] %= mod;

		}
		ans=ans*m%mod;
		ans++;

	} else {
		cur[0]--;
		cur[0] += mod;
		cur[0] %= mod;

		ans += cur[0];
		ans %= mod;
		cur[tmp]++;
		cur[tmp] %= mod;

		for (int i=0; i<n-1; i++) {
			cur[b[i]]--;
			cur[b[i]] += mod;
			cur[b[i]] %= mod;

			ans += cur[b[i]];
			ans %= mod;
			cur[(tmp+b[i])%k]++;
			cur[(tmp+b[i])%k] %= mod;

		}
		ans=ans*m%mod;
	}
	cout << ans <<endl;
}