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
#define maxn 1600005
#define maxc 26
char s[maxn];
int ch[maxn][26];
int fa[maxn], cnt, last, rt;
int dis[maxn], pos[maxn], sum[maxn], val[maxn];
ll k;
int n;
void init()
{
	for (int i = 0; i <= cnt; ++i)
	{
		for (int j = 0; j < 26; ++j)ch[i][j] = 0;
		fa[i] = dis[i] = pos[i] = 0;
	}
	cnt = 0;
	rt = last = ++cnt;
}
inline int newnode(int x) {dis[++cnt] = x; return cnt;}
void add(int x, int i)
{
	int np = newnode(dis[last] + 1), p = last;
	for (; p && (!ch[p][x]); p = fa[p])ch[p][x] = np;
	if (!p)fa[np] = rt;
	else
	{
		int q = ch[p][x];
		if (dis[q] == dis[p] + 1)fa[np] = q;
		else
		{
			int nq = newnode(dis[p] + 1);
			memcpy(ch[nq], ch[q], sizeof(ch[q]));
			fa[nq] = fa[q];
			fa[q] = fa[np] = nq;
			pos[nq] = pos[q];
			for (; ch[p][x] == q; p = fa[p])ch[p][x] = nq;
		}
	}
	last = np;
	pos[np] = i;
}

inline int query(int x, int y)
{
	return sum[y] - sum[x - 1];
}

bool check(int x)
{
	ll tot = 0;
	rep(i, 2, cnt)
	{
		int l = dis[fa[i]] + 1, r = dis[i];
		int ans = dis[fa[i]];
		while(l <= r)
		{
			int mid = l + r >> 1;
			if(query(pos[i] - mid + 1, pos[i]) <= x) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		tot += ans - dis[fa[i]];
	}

    return (tot >= k);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		scanf("%d%lld", &n, &k);
		scanf("%s", s + 1);
		init();
		rep(i, 1, n) add(s[i] - 'a', i);
		rep0(i, 26) scanf("%d", &val[i]);
		rep(i, 1, n) sum[i] = sum[i - 1] + val[s[i] - 'a'];
		ll tot = 0;
		rep(i, 1, cnt) tot += dis[i] - dis[fa[i]];
		if (k > tot) puts("-1");
		else
		{
			int l = 0, r = 10000000, ans = 10000000;
			while(l <= r)
			{
				int mid = l + r >> 1;
				if(check(mid)) ans = mid, r = mid - 1;
				else l = mid + 1; 
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}