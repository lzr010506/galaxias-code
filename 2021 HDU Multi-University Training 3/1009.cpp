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
const int N = 110;
int n, a[N][N], b[N][N];
vector<pii> f[N][N];
int main()
{
    int T = read();
    while(T --)
    {
        n = read();
        rep(i, 1, n) rep(j, 1, n) a[i][j] = read();
        rep(i, 1, n) rep(j, 1, n) b[i][j] = read();
        rep(i, 1, n) rep(j, 1, n)
        {
            if (i > 1 && j > 1)
            {
                f[i][j].clear();
                int p = 0, q = 0;
                for (; p < f[i - 1][j].size() || q < f[i][j - 1].size(); )
                {
                    pii t;
                    if (p < f[i - 1][j].size() && q < f[i][j - 1].size())
                    {
                        if (f[i - 1][j][p] > f[i][j - 1][q]) t = f[i][j - 1][q++];
                        else t = f[i - 1][j][p++];
                    }
                    else 
                    {
                        if (p == f[i - 1][j].size()) t = f[i][j - 1][q++];
                        else t = f[i - 1][j][p++];
                    }
                    while (!f[i][j].empty() && f[i][j].back().Y <= t.Y) f[i][j].pop_back();
                    f[i][j].push_back(t);
                }
            }
            else if (i > 1) f[i][j] = f[i - 1][j];
            else if (j > 1) f[i][j] = f[i][j - 1];
            else { f[i][j].clear(); f[i][j].push_back(mp(0, 0)); }
            for (auto &t : f[i][j]) t.X += a[i][j], t.Y += b[i][j];
        }
        ll ans = 0;
        for (auto t : f[n][n]) ans = max(ans, 1ll * t.X * t.Y);
        printf("%lld\n", ans);
    }

    return 0;
}