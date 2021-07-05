#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define ll long long
using namespace std;
const int N = 3e5 + 10;

inline int read()
{
	int x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x;
}

int n, m, f[N] , ed[N];
ll sz[N];
struct Edge
{
	int u, v, w;
}e[N << 1];
int find(int x)
{
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

bool cmp(Edge a, Edge b)
{
	return a.w > b.w;
}

int main()
{
	ll ans = 0;
	n = read();
	m = read();
	rep(i, 1, n) f[i] = i, sz[i] = 1;
	rep(i, 1, m)
	{
		e[i].u = read();
		e[i].v = read();
		e[i].w = read();
	}
	sort(e + 1, e + m + 1, cmp);

	ed[m] = m ;
	for (int i = m - 1 ; i >= 0 ; --i)
		if (e[i].w == e[i + 1].w) ed[i] = ed[i + 1] ;
		else ed[i] = i ;
	
	bool ok = 1 ;
	rep(i, 1, m)
	{

		int u = e[i].u;
		int v = e[i].v;
		if (e[i].w != e[i - 1].w && i > 1) {
			for (int j = i ; j <= ed[i] ; ++j) {
				int x = find(e[j].u) , y = find(e[j].v) ;
				if (x == y) ok = 0 ;
			}

			if (!ok) break ;
		}


		int x = find(u);
		int y = find(v);
		if(x == y) continue ;
		f[x] = y;
		ans += sz[x] * sz[y] * e[i].w;
		sz[y] += sz[x];
	}
	int S = 0;
	rep(i, 1, n)
	{
		if(find(i) != i) continue;
		ans += S * sz[i];
		S += sz[i];
	}
	if (ok) cout << ans << endl;
	else cout << -1 << endl ;
	return 0;
}