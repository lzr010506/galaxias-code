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
const int N = 1e6 + 15;
int n, a[N];
vector<int>lk[N];
ll ans;
int qa[N * 2], *ad = qa + N;
int q[N * 4], top;
void solve(const vector<int> &a) 
{
    ++ad[0];
    --ad[1];
    q[top = 1] = 0;
    q[top = 2] = 1;
    int mn = 0, cnt = 1, s = 0;
    int x = 0;
    int last = 0;

    for (auto i : a) 
    {
        if (i - 1 != last) 
        {
            int _x = x - (i - 1 - last);

            while (x > mn && x > _x) 
            {
                cnt -= ad[x];
                s -= cnt;
                --x;
                ans += s;
            }

            if (x > _x) 
            {
                mn = x = _x;
                cnt = 1;
                s = 0;
            } else ++cnt;

            ++ad[q[++top] = x];
            --ad[x + (i - 1 - last)];
        }

        s += cnt;
        ++x;
        ++ad[q[++top] = x];
        --ad[q[++top] = x + 1];
        cnt += ad[x];
        ans += s;

        last = i;
    }

    int _x = x - (n - last);

    while (x > mn && x > _x) 
    {
        cnt -= ad[x];
        s -= cnt;
        --x;
        ans += s;
    }

    for (; top; --top)
        ad[q[top]] = 0;
}
int main() 
{
    int T = read();
    while(T --)
    {
        rep(i, 0, 1000000) lk[i].clear();
        ans = 0;   
        n = read(); 
        rep(i, 1, n) a[i] = read();
        rep(i, 1, n) lk[a[i]].pb(i);
        rep(i, 0, 1000000)
            if (!lk[i].empty())
                solve(lk[i]);
        printf("%lld\n", ans);
    }
    
}
