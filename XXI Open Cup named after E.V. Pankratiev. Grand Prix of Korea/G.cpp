#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
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
#define All(x) (x).begin(), (x).end()
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
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n, m, now[N], nxt[N], ans;

int dp[N][1 << 7][5]; 
bool mp[256];
char s[N]; 
int main() 
{
	scanf("%s", s + 1);
	m = read();
	n = strlen(s + 1);
	if(m == 0)
	{
		puts("1");
		return 0;
	}
	dp[0][0][0] = 1;
	rep(i, 1, n)
	{
		memset(mp, 0, sizeof(mp));
		rep(j, max(i - m, 1), min(i + m, n)) mp[s[j]] = 1;
		rep0(j, (1 << (m << 1)))
			rep(k, 0, m)
				if(dp[i - 1][j][k]) 
				{ 
					now[i - 1] = i - 1 - k;
					rep0(t, m) now[i + t] = now[i + t - 1] + (j >> (t + m) & 1);
					rep(t, 1, m) if(i - 1 - t > 0) now[i - 1 - t] = now[i - t] - (j >> (m - t) & 1);
					int to1 = -1, to2;
					for(char ch = 'A'; ch <= 'Z'; ch ++) 
					{
						if(!mp[ch] && ~to1) 
						{
							(dp[i][to1][to2] += dp[i - 1][j][k]) %= mod;
							continue;
						}
						int msk = 0;
						rep(move, max(i - m, 1), i + m)
							nxt[move] = max(max(now[move], now[move - 1] + (s[move] == ch)), nxt[move - 1]);
						rep(move, max(i - m, 0), i + m - 1) 
							if(nxt[move] ^ nxt[move + 1]) msk |= (1 << (move - i + m));
						(dp[i][msk][i - nxt[i]] += dp[i - 1][j][k]) %= mod;
						if(!mp[ch]) to1 = msk, to2 = i - nxt[i];
					}
				}

	}
	rep0(i, (1 << (m << 1)))
		rep(j, 0, m)
			(ans += dp[n][i][j]) %= mod;
	cout << ans << endl;

	return 0;

} 