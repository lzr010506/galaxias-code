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
const int N = 100010;
int c[N];
ll a[N];
int gcd(int x, int y)
{
    while(x)
    {
        int z = x;
        x = y % x;
        y = z;
    }
    return y;
}
int main()
{
    int T = read();
    while(T --)
    {
        int n = read();
        rep(i, 1, n)
        {
            int xa = read();
            int ya = read();
            int xb = read();
            int yb = read();
            int xx = xb - xa;
            int yy = yb - ya;
            int gg = gcd(abs(xx), abs(yy));
            xx /= gg;
            yy /= gg;
            if(xx < 0) xx = -xx, yy = -yy;
            if(xx == 0) yy = 1;
            a[i] = 3000000000LL * xx + yy;
            c[i] = 0;
        }
        sort(a + 1, a + n + 1);
        int cnt = 0;
        a[n + 1] = a[n] + 1;
        rep(i, 1, n)
        {
            cnt ++;
            if(a[i] != a[i + 1])
            {
                c[cnt] ++;
                cnt = 0;
            }
        }
        rrep(i, n - 1, 1) c[i] += c[i + 1];
        int j = 0, lim = 0;
        rep(i, 1, n)
        {
            for (; lim < i; lim += c[j + 1], j++);
            write(max(0, i - j), '\n');
        }
    }
    fwrite(obuf, 1, fos - obuf, stdout);

    return 0;
}