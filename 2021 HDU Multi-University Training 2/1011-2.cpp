#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const ll inf = 1000000007;
const ll mod = 998244353;
const int N = 1e6 + 10;
ll a[N], b[N], c[N];
ll amxz[N], amnz[N], amxf[N], amnf[N], bmxz[N], bmnz[N], bmxf[N], bmnf[N];
bool hasaz[N], hasaf[N], hasbz[N], hasbf[N], has0[N];
int main()
{
	int T = read();
	while (T --)
	{
		int n = read();
		int k = 1, _ = 0;
		while (k < n) k <<= 1, ++ _;
		k --;
		rep0(i, k + 1)
		{
			amxz[i] = 0;
			amnz[i] = inf;
			amxf[i] = -inf;
			amnf[i] = 0;
			bmxz[i] = 0;
			bmnz[i] = inf;
			bmxf[i] = -inf;
			bmnf[i] = 0;
			hasaz[i] = 0;
			hasaf[i] = 0;
			hasbz[i] = 0;
			hasbf[i] = 0;
			has0[i] = 0;
			c[i] = -inf * inf;
		}
		rep0(i, n)
		{
			a[i] = read();
			if (a[i] > 0)
			{
				amxz[i] = max(amxz[i], a[i]);
				amnz[i] = min(amnz[i], a[i]);
				hasaz[i] = 1;
			}
			else if (a[i] < 0)
			{
				amxf[i] = max(amxf[i], a[i]);
				amnf[i] = min(amnf[i], a[i]);
				hasaf[i] = 1;
			}
			else if (a[i] == 0)
				has0[i] = 1;

		}
		rep0(i, n)
		{
			b[i] = read1();
			if (b[i] > 0)
			{
				bmxz[i] = max(bmxz[i], b[i]);
				bmnz[i] = min(bmnz[i], b[i]);
				hasbz[i] = 1;
			}
			else if (b[i] < 0)
			{
				bmxf[i] = max(bmxf[i], b[i]);
				bmnf[i] = min(bmnf[i], b[i]);
				hasbf[i] = 1;
			}
			else if (b[i] == 0)
				has0[i] = 1;
		}
		ll ans = 0;
		rrep(S, k, 0)
		{
			rep0(i, _)
			if ((S & (1 << i)) == 0)
			{
				int sta = S | (1 << i);
				hasaz[S] |= hasaz[sta];
				hasaf[S] |= hasaf[sta];
				hasbz[S] |= hasbz[sta];
				hasbf[S] |= hasbf[sta];
				has0[S] |= has0[sta];
				if (hasaz[S])
				{
					amxz[S] = max(amxz[S], amxz[sta]);
					amnz[S] = min(amnz[S], amnz[sta]);
				}
				if (hasaf[S])
				{
					amxf[S] = max(amxf[S], amxf[sta]);
					amnf[S] = min(amnf[S], amnf[sta]);
				}
				if (hasbz[S])
				{
					bmxz[S] = max(bmxz[S], bmxz[sta]);
					bmnz[S] = min(bmnz[S], bmnz[sta]);
				}
				if (hasbf[S])
				{
					bmxf[S] = max(bmxf[S], bmxf[sta]);
					bmnf[S] = min(bmnf[S], bmnf[sta]);
				}
			}
			//cerr<<S<<" "<<hasaz[S]<<" "<<hasaf[S]<<" "<<hasbz[S]<<" "<<hasbf[S]<<" "<<has0[S]<<endl;
			if (hasaz[S] && hasbz[S])c[S] = max(c[S], amxz[S] * bmxz[S]);
			if (hasaf[S] && hasbf[S])c[S] = max(c[S], amnf[S] * bmnf[S]);
			if (hasaz[S] && hasbf[S])c[S] = max(c[S], amnz[S] * bmxf[S]);
			if (hasaf[S] && hasbz[S])c[S] = max(c[S], amxf[S] * bmnz[S]);
			if (has0[S])c[S] = max(c[S], 0ll);
			//cerr<<c[S]<<endl;
			if (S < k)c[S] = max(c[S], c[S + 1]);
			if (S < n) 
			{
				ans = (ans + c[S]) % mod;
				assert(abs(c[S]) < inf * 1ll * inf);
			}
		}
		ans = (ans % mod + mod) % mod;
		printf("%lld\n", ans);
	}
}
