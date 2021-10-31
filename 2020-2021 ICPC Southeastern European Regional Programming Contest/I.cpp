#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
using namespace std;
const int mod = 1e9 + 7;
ll dp[1000010], cnt[1000010];
int main()
{
	int n;
	scanf("%d", &n);
	if(n == 1) {puts("1"); return 0;}
	dp[1] = 1; dp[2] = 1; dp[3] = 2;
	rep(j, 2, n / 2) cnt[j * 2] ++;
	rep(j, 2, n / 3) cnt[j * 3] += 2;
	rep(i, 5, n)
	{
		dp[i - 1] = dp[1] + dp[i - 2] + cnt[i] + cnt[i - 1] + cnt[i - 2] - !(i & 1);
		dp[i - 1] %= mod;
		rep(j, 2, n / (i - 1)) (cnt[j * (i - 1)] += dp[i - 1]) %= mod;
	}
	int ans = 0;
	rep(i, 1, n - 1) (ans += dp[i]) %= mod;
	printf("%d\n", 1LL * ans * n % mod);

	return 0;
}