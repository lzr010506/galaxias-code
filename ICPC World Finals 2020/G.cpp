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
using namespace std;
const int N = 2e5 + 10;
ll x[N], y[N], z[N];
ll mx[8], ans[N];
int main()
{
    int n = read();
    rep0(i, n) x[i] = read(), y[i] = read(), z[i] = read();
    rep0(t, 8)
        rep0(i, n)
        {
            ll s = 0;
            if(t & 1) s += x[i];
            if(t & 2) s += y[i];
            if(t & 4) s += z[i];
            mx[t] = max(mx[t], s);
        }
    rep0(i, n)
        rep0(t, 8)
        {
            ll s = 0;
            if(t & 1) s += x[i];
            if(t & 2) s += y[i];
            if(t & 4) s += z[i];
            ans[i] = max(ans[i], mx[t] - s);
        }
    ll mn = 1e18 + 10, id;
    rep0(i, n)
        if(mn > ans[i]) 
            mn = ans[i], id = i + 1;

    printf("%lld %lld\n", mn, id);


    return 0;
}