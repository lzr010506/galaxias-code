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
int n, m, ans;
int s[6], vis[6][6];
char G[6][6];

void dfs(int tot)
{
	if(tot > m)
	{
		rep(i, 1, n)
			rep(j, 1, n)
				if(G[i][j] == 'O' && vis[i][j] == 0)
					return;
		ans ++;
		return;
	}
	rep(i, 1, n)
		rep(j, 1, n)
		{
			if(i + s[tot] - 1 <= n)
			{
				rep(k, i, i + s[tot] - 1)
					if(G[k][j] == 'X' || vis[k][j]) goto L1;
				rep(k, i, i + s[tot] - 1)
					vis[k][j] = 1;
				dfs(tot + 1);
				rep(k, i, i + s[tot] - 1)
					vis[k][j] = 0;
			}
			L1:;
			if(s[tot] == 1) goto L2;
			if(j + s[tot] - 1 <= n)
			{
				rep(k, j, j + s[tot] - 1)
					if(G[i][k] == 'X' || vis[i][k]) goto L2;
				rep(k, j, j + s[tot] - 1)
					vis[i][k] = 1;
				dfs(tot + 1);
				rep(k, j, j + s[tot] - 1)
					vis[i][k] = 0;
			}
			L2:;
		}
}

int main()
{
	scanf("%d%d", &n, &m);
	rep(i, 1, n)
		scanf("%s", G[i] + 1);
	rep(i, 1, m)
		scanf("%d", &s[i]);
	dfs(1);
	printf("%d\n", ans);
	return 0;
}