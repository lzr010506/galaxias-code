#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
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
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 5e6 + 10;
struct Node
{
    int ch[2];
    int s;
}t[N];
int n, l[N], r[N], s[N], w[N];
int cnt, ans;
vector<pii> G[100010];

void dfs(int x, int fa)
{
    for(auto y : G[x])
    {
        int to = y.X;
        int w = y.Y;
        if(to == fa) continue;
        s[to] = s[x] ^ w;
        dfs(to, x);
    }
}

void add(int k, int w, int x)
{
    k ++;
    rrep(i, 30, 0)
    {
        if(!(k & (1 << i))) continue;
        int p = (((w ^ k) >> i) ^ 1) << i;
        int o = 1;
        rrep(j, 30, i)
        {
            int nw = (p >> j) & 1;
            if(!t[o].ch[nw]) t[o].ch[nw] = ++ cnt;
            o = t[o].ch[nw]; 
        }
        t[o].s += x;
    }
}

void sol(int nw, ll y, int z, int k)
{
   //cout << nw << " " << y << " " << z << " " << k << endl;
    if(!t[nw].ch[0] && !t[nw].ch[1]) 
    {
        if(z + t[nw].s >= n) ans += y;
        return;
    }
    z += t[nw].s;
    y >>= 1;
    if(t[nw].ch[0]) sol(t[nw].ch[0], y, z, k << 1);
    else if(z >= n) ans += y;
    if(t[nw].ch[1]) sol(t[nw].ch[1], y, z, k << 1 | 1);
    else if(z >= n) ans += y; 
}


int main()
{
    cnt = 1;
    n = read();
    rep(i, 1, n) l[i] = read(), r[i] = read();
    rep(i, 1, n - 1)
    {
        int x = read();
        int y = read();
        int z = read();
        G[x].pb(mp(y, z));
        G[y].pb(mp(x, z));
    }
    dfs(1, 0);
    rep(i, 1, n)
    {
        add(r[i], s[i], 1);
        if(l[i]) add(l[i] - 1, s[i], -1);
    }
    //puts("!111");
    sol(1, 1ll << 31, 0, 0);
    cout << ans << endl;
    return 0;
}