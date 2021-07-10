#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

ll f[3100][3100];
int h[3100], s[3100], w[3100];
int n, H, S;
int main()
{
	n = read();
	H = read();
	S = read();
	rep(i, 1, n)
	{
		h[i] = read();
		s[i] = read();
		w[i] = read();
	}
	rep(i, 1, n)
		rep(j, 1, H)
			rep(k, 0, S)
			{
				int nh = j, ns = k;
				nh -= h[i];
				ns -= s[i];
				if(ns < 0) nh += ns, ns = 0;
				if(nh <= 0) continue;
				f[nh][ns] = max(f[nh][ns], f[j][k] + w[i]);
			}
	ll ans = 0;
	rep(j, 1, H)
		rep(k, 0, S)
			ans = max(ans, f[j][k]);
	cout << ans;
	return 0;
}