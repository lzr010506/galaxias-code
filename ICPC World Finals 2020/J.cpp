#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
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
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
#define ld long double
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
    char c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
const long double eps = 1e-9;
const int N = 1e5 + 10;
vector<pii> G[N];
int dp[N][2][5];
void dfs(int x, int fa, int len)
{
    int ndp[2][5];
    dp[x][0][0] = 0;
    for(auto pp : G[x])
    {
        int to = pp.X;
        int val = pp.Y;
        if(to == fa) continue;
        dfs(to, x, val);
        
        rep0(i, 2)
            rep0(j, 5)
                ndp[i][j] = INF;
        rep0(i, 2)
            rep0(j, 5)
                rep0(ii, 2)
                    rep0(jj, 5)
                        if(j + jj <= 4)
                            ndp[i ^ ii][j + jj] = min(ndp[i ^ ii][j + jj], dp[x][i][j] + dp[to][ii][jj]);
        rep0(i, 2)
            rep0(j, 5)
                dp[x][i][j] = ndp[i][j];
    }
    rep0(i, 2)
        rep0(j, 5)
            ndp[i][j] = INF;
    rep0(i, 2)
        rep0(j, 5)
            rep(use, 1, 2)
            {
                int nn = (i + use) % 2;
                int nc = j + nn;
                if(nc > 4) continue;
                int nt = dp[x][i][j] + (use == 2 ? len : 0);
                ndp[use & 1][nc] = min(ndp[use & 1][nc], nt);
            }
    rep0(i, 2)
        rep0(j, 5)
            dp[x][i][j] = ndp[i][j];
}

int main()
{
    int n = read();
    int ans = 0;
    memset(dp, INF, sizeof(dp));
    rep(i, 1, n - 1)
    {
        int x, y, z;
        x = read();
        y = read();
        z = read();
        G[x].pb({y, z});
        G[y].pb({x, z});
        ans += z;
    }
    dfs(1, 0, 0);
    int res = INF;
    rep0(i, 5) res = min(res, dp[1][0][i]);
    printf("%d\n", ans + res);
}