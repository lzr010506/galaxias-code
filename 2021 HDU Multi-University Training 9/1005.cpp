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

vector<int> v[5];
int sz[5];
int dp[52 * 52 * 52 * 52][5];

int getid(int x1, int x2, int x3, int x4)
{
    return x1 * (sz[2] + 1) * (sz[3] + 1) * (sz[4] + 1) + x2 * (sz[3] + 1) * (sz[4] + 1) + x3 * (sz[4] + 1) + x4;
}

int dfs(int x1, int x2, int x3, int x4, int dis)
{
    int id = getid(x1, x2, x3, x4);
    if(id == 0) return 0;
    if(dp[id][dis] != -1) return dp[id][dis];
    if(dis > 0)
    {
        int val = INF;
        if(x1) val = min(val, dfs(x1 - 1, x2, x3, x4, dis - 1));
        if(x2) val = min(val, dfs(x1, x2 - 1, x3, x4, dis - 1));
        if(x3) val = min(val, dfs(x1, x2, x3 - 1, x4, dis - 1));
        if(x4) val = min(val, dfs(x1, x2, x3, x4 - 1, dis - 1));
        return dp[id][dis] = val;
    }
    int val = 0;
    if(x1) val = max(val, dfs(x1 - 1, x2, x3, x4, 1) + v[1][x1 - 1]);
    if(x2) val = max(val, dfs(x1, x2 - 1, x3, x4, 2) + v[2][x2 - 1]);
    if(x3) val = max(val, dfs(x1, x2, x3 - 1, x4, 3) + v[3][x3 - 1]);
    if(x4) val = max(val, dfs(x1, x2, x3, x4 - 1, 4) + v[4][x4 - 1]);
    return dp[id][dis] = val;
}

int main()
{
    int T = read();
    while(T --)
    {
        rep(i, 1, 4) v[i].clear(), sz[i] = 0;
        int n = read();
        rep(i, 1, n)
        {
            int d = read();
            int vv = read();
            v[vv].pb(d);
            sz[vv] ++;
        }
        rep(i, 1, 4) sort(v[i].begin(), v[i].end());
        //rep(i, 1, 4) reverse(v[i].begin(), v[i].end());
        rep(i, 0, getid(sz[1], sz[2], sz[3], sz[4]))
            rep(j, 0, 4)
                dp[i][j] = -1;
        printf("%d\n", dfs(sz[1], sz[2], sz[3], sz[4], 0));
    }

    return 0;
}