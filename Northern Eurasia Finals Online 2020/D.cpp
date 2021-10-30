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
const int N = 3e5 + 10;
const int K = 8;
bitset<1 << K> dp[N];
int mask[N], nxt[N];
char ch[K]; 
int main() 
{
    int n;
    scanf("%d", &n);
    rep(i, 1, n)
    {
        scanf("%s", ch);
        rep0(j, K) mask[i] |= (ch[j] == 'W') << j;
    }
    rep(i, 1, n)
    {
        nxt[i] = 0;
        rep0(dis, K)
        {
            int j = i + 1 + dis;
            if(j <= n && j - i <= K - __builtin_popcount(mask[i] ^ mask[j])) nxt[i] |= 1 << dis;
        }
    }

    rep0(mask, 1 << K) dp[0][mask] = mask & 1;
 
    rep(i, 1, n)
    {
        rep0(mask, (1 << K))
        {
            int val = 0;
            rep0(dis, K)
                if((nxt[i] & (1 << dis)) && !(mask & (1 << dis))) val = 1;
            int nw = (mask << 1 | val) % (1 << K);
            dp[i][mask] = dp[i - 1][nw];
        }
        printf("%d", 2 - dp[i][(1 << K) - 1]);
    }
}
