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
int T, n, cnt, ans, res, d[300005], S;
pii p[300005];
set<pii > s[300005];
vector<int> v[300005], e[300005];
map<pii, int> M;
void dfs(int x, int y) 
{
    p[x].first = ++ cnt;
    for(auto to : e[x]) if (to != y) dfs(to, x);
    p[x].Y = ++ cnt;
    M[p[x]] = x;
}
void sol(int x, int ss, int y, int k) 
{
    if (y && p[x].first < p[y].Y && p[y].first < p[x].Y) 
    {
        k = ++S;
        ss = d[x] - 1;
    }
    bool in = 0, ot = 0;
    vector<pii >V;
    pii OT;
    if (s[k].empty()) 
    {
        s[k].insert(p[x]);
        in = 1;
    }
    else 
    {
        set<pii >::iterator it = s[k].lower_bound(p[x]);
        if (it == s[k].end() || (it -> X) > p[x].Y) 
        {
            in = 1;
            if (it != s[k].begin()) 
            {
                --it;
                if (it -> Y > p[x].X) 
                {
                    ot = 1;
                    OT = *it;
                    s[k].erase(it);
                }
            }
            s[k].insert(p[x]);
        }
        else 
        {
            while (it != s[k].end() && (it->X) < p[x].Y) V.pb(*it), ++it;
            in = 1;
            s[k].insert(p[x]);
            rep0(i, sz(V)) s[k].erase(V[i]);
        }
    }
    if (ot)ss = max(ss, d[M[OT]]);
    rep0(i, sz(V)) ss = max(ss, d[M[V[i]]]);
    if (in)ans = max(ans, d[x] - ss);
    rep0(i, sz(v[x])) if (v[x][i] != y) d[v[x][i]] = d[x] + 1, sol(v[x][i], ss, x, k);
    if (in)s[k].erase(p[x]);
    if (ot)s[k].insert(OT);
    for(auto xx : V) s[k].insert(xx);
}
int main()
{
    int T = read();
    while (T --)
    {
        M.clear();
        n = read();
        cnt = 0;
        rep(i, 1, n) v[i].clear(), e[i].clear();
        rep(i, 2, n)
        {
            int x = read();
            int y = read();
            v[x].pb(y);
            v[y].pb(x);
        }
        rep(i, 2, n)
        {
            int x = read();
            int y = read();
            e[x].pb(y);
            e[y].pb(x);
        }
        dfs(1, 0);
        ans = 1;
        d[1] = 1;
        S = 1;
        sol(1, 0, 0, 1);
        printf("%d\n", ans);
    }
    return 0;
}
