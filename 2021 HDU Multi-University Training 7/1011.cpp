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
const int mod = 998244353;
const int MOD = mod;
const int M = 1e6 + 10;
struct Com {
    db r, i;
    Com(db _x = 0, db _y = 0) {
        r = _x;
        i = _y;
    }
    inline Com operator + (const Com& rhs) const {
        return (Com) {r + rhs.r, i + rhs.i};
    }
    inline Com operator - (const Com& rhs) const {
        return (Com) {r - rhs.r, i - rhs.i};
    }
    inline Com operator * (const Com& rhs) const {
        return (Com) {r*rhs.r - i*rhs.i, r*rhs.i + i*rhs.r};
    }
} w[M];
const db PI = acos(-1);
int rev[M];
inline void FFT(Com a[], int N) {
    rep(i, 0, N - 1) {
        if (rev[i] > i) {
            swap(a[rev[i]], a[i]);
        }
    }
    for (int d = 1, t = N >> 1; d < N; d <<= 1, t >>= 1) {
        for (int i = 0; i < N; i += (d << 1)) {
            rep(j, 0, d - 1) {
                Com tmp = w[t * j] * a[i + j + d];
                a[i + j + d] = a[i + j] - tmp;
                a[i + j] = a[i + j] + tmp;
            }
        }
    }
}
inline void MTT(int *f, int *g, int n, int m, int mod) {
    static Com p1[M], p2[M], q[M];
    int N = 1, L = 0;
    for (; N <= (n + m); N <<= 1, ++L);
    rep(i, 0, N - 1) 
{
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
        w[i] = Com(std::cos(2.0 * i * PI / N), std::sin(2.0 * i * PI / N));
    }
    int lim = 32768;
    rep(i, 0, N) 
    {
        p1[i].r = p1[i].i = 0;
        p2[i].r = p2[i].i = 0;
        q[i].r = q[i].i = 0;
    }
    rep(i, 0, n - 1) 
    {
        p1[i] = Com(f[i] / lim, f[i] % lim);
        p2[i] = Com(f[i] / lim, -f[i] % lim);
    }
    rep(i, 0, m - 1) 
    {
        q[i] = Com(g[i] / lim, g[i] % lim);
    }
    FFT(p1, N), FFT(p2, N), FFT(q, N);
    rep(i, 0, N - 1) 
    {
        q[i].r /= N, q[i].i /= N;
    }
    rep(i, 0, N - 1) 
    {
        p1[i] = p1[i] * q[i];
        p2[i] = p2[i] * q[i];
        w[i].i = -w[i].i;
    }
    FFT(p1, N), FFT(p2, N);
    rep(i, 0, n + m - 1) 
    {
        ll a1b1, a1b2, a2b1, a2b2;
        a1b1 = (ll)floor((p1[i].r + p2[i].r) / 2 + 0.5) % mod;
        a1b2 = (ll)floor((p1[i].r + p2[i].i) / 2 + 0.5) % mod;
        a2b1 = ((ll)floor(p1[i].i + 0.5) - a1b2) % mod;
        a2b2 = ((ll)floor(p2[i].r + 0.5) - a1b1) % mod;
        f[i] = (((a1b1 * lim + a1b2 + a2b1) * lim + a2b2) % mod + mod) % mod;
    }
}
int qpow(int x, int times)
{
    int res = 1;
    while (times)
    {
        if (times & 1) res = 1LL * x * res % mod;
        times >>= 1;
        x = 1LL * x * x % mod;
    }
    return res;
}
int a[M], sum[M];
int p[M], q[M], pos[M];
inline getm(int l, int r)
{
    int mid = l, L = l, R = r;
    while (L <= R) 
    {
        int mm = (L + R) / 2;
        if (sum[mm] - sum[L - 1] <= sum[R] - sum[mm]) L = (mid = mm) + 1;
        else R = mm - 1;
    }
    return mid;
}
inline int solve(int l, int r)
{
    //cerr << l << " " << r << endl;
    if (l == r)
    {
        if (a[l]) pos[sum[l]] = 1;
        return 1 + (a[l] == 0);
    }
    int mid = getm(l, r);
    if (mid == r) mid = r - 1;
    int l0 = solve(l, mid);
    int r0 = solve(mid + 1, r);
    int n = sum[mid] - sum[l - 1];
    int m = sum[r] - sum[mid];
    p[0] = l0, q[0] = r0;
    rep(i, 1, n) p[i] = pos[sum[l - 1] + i];
    rep(i, 1, m) q[i] = pos[sum[mid] + i];
    MTT(p, q, n + 1, m + 1, MOD - 1);
    int ret = p[0];
    rep(i, 1, n + m) 
    {
        pos[sum[l - 1] + i] = p[i];
    }
    return ret;
}

int main()
{
    int T = read();
    while (T --)
    {
        int n = read();
        rep(i, 1, n) a[i] = read();
        sort(a + 1, a + n + 1);
        rep(i, 1, n) sum[i] = sum[i - 1] + a[i];
        rep(i, 1, sum[n]) pos[i] = 0;
        solve(1, n);
        int ans = 1;
        rep(i, 1, sum[n])
            ans = 1LL * ans * qpow(i, pos[i]) % mod;
        if (a[1] == 0) ans = 0;
        printf("%d\n", ans);
    }
}