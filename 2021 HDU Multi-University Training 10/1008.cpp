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
    char c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}

inline ll read1() {
    char c; ll x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10LL + c - '0'; } return x;
}
const int N = 5e5 + 10;
const int b1 = 31;
const int b2 = 37;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
int h1[N], h2[N];
int pw1[N], pw2[N];
int com(int l1, int r1, int l2, int r2)
{
    int L = r1 - l1 + 1;
    return (h1[r1] - (ll)h1[l1 - 1] * pw1[L] % mod1 + mod1) % mod1 == (h1[r2] - (ll)h1[l2 - 1] * pw1[L] % mod1 + mod1) % mod1;
}

int n, Q, block, L;
char S[N];
int mk[N], mkn;
struct SAM
{
    int root, tot, p;
    int son[N][26], par[N], len[N], suf[N];
    void init()
    {
        root = tot = p = 1;
        memset(son[1], 0, sizeof son[1]);
        memset(suf, 0, sizeof suf);
        par[1] = 0; len[1] = 0;
    }
    int newnode()
    {
        tot++;
        memset(son[tot], 0, sizeof son[tot]);
        par[tot] = 0, len[tot] = 0;
        return tot;
    }
    void extend(const int w, const int ss)
    {
        int np = newnode(); suf[np] = ss; len[np] = len[p] + 1;
        while (p && !son[p][w])
        {
            son[p][w] = np;
            p = par[p];
        }
        if (p)
        {
            int q = son[p][w];
            if (len[q] == len[p] + 1) par[np] = q;
            else
            {
                int nq = newnode();
                memcpy(son[nq], son[q], sizeof son[nq]);
                par[nq] = par[q]; len[nq] = len[p] + 1;
                par[q] = nq; par[np] = nq;

                while (p && son[p][w] == q)
                {
                    son[p][w] = nq;
                    p = par[p];
                }
            }
        }
        else par[np] = root;
        p = np;
    }
    int ct[205][N];
    vector<int>V[N];
    void addpre()
    {
        for (int i = 0; i <= n; i++)
        {
            vector<int>_;
            V[i].swap(_);
        }
        for (int i = 1; i <= tot; i++) V[len[i]].push_back(i);
    }
    void add(int ki, int j)
    {
        memset(ct[ki], 0, sizeof ct[ki]);
        for (int i = n; i >= 1; i--)
        {
            for (auto k : V[i])
            {
                if (suf[k] && suf[k] + 1 + n - j <= n && com(j, n, suf[k] + 1, suf[k] + 1 + n - j)) ct[ki][k]++;
                ct[ki][par[k]] += ct[ki][k];
            }
        }
    }
    int query(int now, int y)
    {
        while (!mk[y])
        {
            int c = S[y] - 'a';
            if (!son[now][c]) return 0;
            y++;
            now = son[now][c];
        }
        return ct[mk[y]][now];
    }
} sam;


int ans[N];
vector< pair<int,int> >qi[N];

int main()
{
    pw1[0] = 1; rep(i, 1, N - 1) pw1[i] = (ll)pw1[i - 1] * b1 % mod1;
    int T;
    scanf("%d", &T);
    while (T --)
    {
        scanf("%d%d", &n, &Q);
        scanf("%s", S + 1);
        rep(i, 1, n)
        {
            int c = S[i] - 'a';
            h1[i] = ((ll)h1[i - 1] * b1 + c) % mod1;
        }
        sam.init();
        rep(i, 1, n) sam.extend(S[i] - 'a', i);

        sam.addpre();
        block = min(200, (int)sqrt(n));
        L = (n / block);
        memset(mk, 0, sizeof mk); 
        mkn = 0;
        for (int i = 1; i <= n; i += L)
        {
            mk[i] = ++ mkn;
            sam.add(mkn, i);
        }
        if (!mk[n]) mk[n] = ++ mkn, sam.add(mkn, n);

        rep(i, 1, n)
        {
            vector< pii > ass;
            qi[i].swap(ass);
        }
        rep(i, 1, Q)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            qi[x].pb(mp(i, y));
        }

        int now = sam.root;
        rep(i, 1, n)
        {
            now = sam.son[now][S[i] - 'a'];
            for (auto v : qi[i])
            {
                if (i + v.Y > n) ans[v.X] = 0;
                else ans[v.X] = sam.query(now, n - v.Y + 1);
            }
        }
        rep(i, 1, Q) printf("%d\n", ans[i]);
    }
    return 0;
}