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
const int N = 1e5 + 10;
char ch[110][110];
int vis[110][110];
int l, r;
vector<pair<int, int> > ans;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};


int main()
{
	int T = read();
	rep(Cas, 1, T)
	{
		memset(vis, 0, sizeof(vis));
		ans.clear();
		rep(i, 1, 30)
			scanf("%s", ch[i] + 1);
		l = 101;
		r = 0;

		rep(j, 1, 21)
		{
			int flag = 0;
			rep(i, 1, 30)
			{
				if(ch[i][j] == '#') {flag = 1; break;}
			}
			if(flag == 0)
			{
			}
			else
			{
				l = min(l, j);
				r = max(r, j);
			}
		}
		ans.pb(mp(l, r));
		l = 101;
		r = 0;
		rep(j, 22, 100)
		{
			int flag = 0;
			rep(i, 1, 30)
			{
				if(ch[i][j] == '#') {flag = 1; break;}
			}
			if(flag == 0)
			{
				if(l != 101 || r != 0) ans.pb(mp(l, r));
				l = 101;
				r = 0;
			}
			else
			{
				l = min(l, j);
				r = max(r, j);
			}
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d:\n", Cas);
		for(auto x : ans) printf("%d %d\n", x.X, x.Y);
	}

	return 0;
}