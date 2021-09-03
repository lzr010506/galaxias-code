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
const int mod = 1e9 + 7;
int qpow(int x, int times)
{
    int res = 1;
    while(times)
    {
        if(times & 1) res = 1LL * res * x % mod;
        times >>= 1;
        x = 1LL * x * x % mod;
    }
    return res;
}
const int N = 1e6 + 10;
int dp[N], sum[N];

int f(int x) 
{
    if (x <= 2) return 0;
    if (dp[x]) return dp[x];
    int ret = 0;
    ret = 1 + f(x / 2);
    if (x & 1) ret += f(x / 2);
    else ret += f((x / 2) - 1);
    ret %= mod;
    dp[x] = ret;
    return ret;
}

int main()
{
    rep(i, 1, 1000000) 
    {
        sum[i] = sum[i - 1] + f(i);
        sum[i] %= mod;
    }
    int T = read();
    while(T --)
    {
        int n = read();
        int ans = n;
        if (n > 2) ans = (ans + 1LL * sum[n - 2] * 2LL % mod) % mod;
        if (n > 2) ans = ans + 1LL * (n - 2) * 2LL % mod;
        ans %= mod;
        ans = 1LL * ans * qpow(n, mod - 2) % mod;
        printf("%d\n", ans);
    }
    return 0;
}