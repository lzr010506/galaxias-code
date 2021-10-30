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

const int mod = 1e9 + 7;
const int N = 6e5 + 10;
vector<int> g[22],ans[22];
void dfs(int now) 
{
    if(now != 1) ans[now].pb(now);
    bool f = 0;
    for(auto to : g[now]) 
    {
        dfs(to);
        if(f) 
        {
            int len = ans[now].size(), l = (now == 1 ? 0 : 1);
            int dz = 1;
            for(auto y : ans[to]) 
            {
                ans[now].pb(y);
                if(dz == 1) rrep(i, len - 1, l) ans[now].pb(ans[now][i]);
                else rep(i, l, len - 1) ans[now].pb(ans[now][i]);
                dz = 1 - dz;
            }
        }
        else 
        {
            f = 1;
            for(auto y : ans[to]) ans[now].pb(y);
        }
    }
}
int main() 
{
    int n = read();
    rep(i, 2, n)
    {
        int x = read();
        g[x].pb(i);
    }
    dfs(1);
    printf("%d\n", ans[1].size());
    for(auto x : ans[1]) printf("%d ", x);
    return 0;
}