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
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
    char c, _c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
const int N = 1e6 + 10;
int a1[N], b1[N], a2[N], b2[N];
vector<int> G[N];
int vis[N], col[N], tag[N];
char ch[N];
int flag, cnt;
vector<int> t[N];
void dfs(int x, int fa)
{
	t[cnt].pb(x);
	vis[x] = 1;
	for(auto y : G[x])
	{
		//cout << x << " " << y << endl;
		if(y == fa) continue;
		if(col[y] == col[x]) tag[cnt] = 1;
		if(col[y] == -1) 
		{
			vis[y] = 1;
			col[y] = 1 - col[x];
			dfs(y, x);
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T --)
	{
		int n;
		scanf("%d", &n);
		rep(i, 1, n) G[i].clear(), vis[i] = 0, col[i] = -1, t[i].clear(), tag[i] = 0;
		int m;
		cnt = 0;
		scanf("%d", &m);
		rep(i, 1, m)
		{
			int u;
			int v;
			scanf("%d%d", &u, &v);
			G[u].pb(v);
			G[v].pb(u);
		}
		rep(i, 1, n)
			scanf("%d", &a1[i]);
		scanf("%s", ch + 1);
		rep(i, 1, n)
			if(ch[i] == 'R') b1[i] = 1;
			else b1[i] = 0;
		rep(i, 1, n)
			scanf("%d", &a2[i]);
		scanf("%s", ch + 1);
		rep(i, 1, n)
			if(ch[i] == 'R') b2[i] = 1;
			else b2[i] = 0;
		col[0] = -1;
		rep(i, 1, n)
		{
			if(vis[i] == 1) continue;
			col[i] = 1;
			cnt ++;
			dfs(i, 0);
		}
		//cout << cnt << endl;
		rep(i, 1, cnt)
		{
			if(tag[i] == 0)
			{
				vector<int> x, y;
				for(auto j : t[i]) 
				{
					x.pb(a1[j] * 2 + (col[j] ^ b1[j]));
					y.pb(a2[j] * 2 + (col[j] ^ b2[j]));
				}
				sort(x.begin(), x.end());
				sort(y.begin(), y.end());
				rep0(i, sz(x)) if(x[i] != y[i]) {puts("NO"); goto L1;}
			}
			else
			{
				vector<int> x, y;
				for(auto j : t[i]) x.pb(a1[j]), y.pb(a2[j]);
				sort(x.begin(), x.end());
				sort(y.begin(), y.end());
				rep0(i, sz(x)) if(x[i] != y[i]) {puts("NO"); goto L1;}
				int c1 = 0, c2 = 0;
				for(auto j : t[i])
				{
					c1 += b1[j];
					c2 += b2[j];
				}
				if(c1 % 2 != c2 % 2) 
				{puts("NO");
				goto L1;}
			}
		}
		puts("YES");
		L1:;
	}
}