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
const int N = 1e6 + 10;
int dfn[N], low[N], sz[N], mi, tot, a[N];
vector<int> G[N];
void dfs(int now, int fa)
{
    dfn[now] = low[now] = ++ tot;
    sz[now] = 1;
    bool flag = 0;
    for(auto y : G[now])
    {
        if(y == fa) continue;
        if(!dfn[y])
        {
            dfs(y, now);
            sz[now] += sz[y];
            if(low[y] >= dfn[now] && (sz[y] & 1)) flag = 1;
            low[now] = min(low[now], low[y]);
        }else low[now] = min(low[now], dfn[y]);
    }
    if(flag == 0)
    {
        mi = min(mi, a[now]);
    }
}
int main()
{
    int T = read();
    while(T --)
    {
        ll ans = 0;
        tot = 0;
        int n = read();
        int m = read();
        rep0(i, n + 1)
        {
            G[i].clear();
            dfn[i]=low[i]=0;
        }
        rep(i, 1, n)
        {
            a[i] = read();
            ans += a[i];
        }
        rep(i, 1, m)
        {
            int x = read();
            int y = read();
            G[x].pb(y);
            G[y].pb(x);
        }
        rep(i, 1, n)
        {
            if(dfn[i])continue;
            mi = 2000000000;
            dfs(i, 0);
            if(sz[i] & 1) ans -= 1LL * mi * 2;
        }
        printf("%lld\n", ans);
    }
}
