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
const int N = 3010;
char s[N];
int A[N], B[N];
int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        rep(i, 1, n) A[i] = B[i] = 0;
        rep(p, 1, n)
        {
            int pos = n, l = 0, lim = 0;
            rrep(st, p, 1)
            {
                lim += (s[st] != s[pos] ? 1 : 0);
                l ++;
                while(lim > k || st + l - 1 > pos)
                {
                    lim -= (s[st + l - 1] != s[pos + l - 1] ? 1 : 0);
                    l --;
                }
                B[st] ++;
                B[st + l] --;
                A[pos] -= l;
                pos --;
            }
        }
        int ans = 0, wt = 0;
        rep(i, 1, n - 1)
        {
            wt += B[i];
            ans += wt;
            ans += A[i];
            printf("%d\n", ans);
        }
    }

    return 0;
}