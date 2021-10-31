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
const int N = 1000010;
int a[N];
vector<int> ans;
struct Node
{
    int l, id;
    vector<int> ans;
}b[N];
bool cmp(Node a, Node b)
{
    return a.l > b.l;
}
bool cmp1(Node a, Node b)
{
    return a.id < b.id;
}
int main()
{
    int T = read();
    rep(Cas, 1, T)
    {
        int n = read();
        int k = read();
        ans.clear();
        for(int i=1; i<=n/2; ++i)
        {
            ans.pb(n);
            int now = i;
            for(int j=1; j<=n-1; ++j)
            {
                a[j] = now;
                ++now;
                if(now >= n) now = 1;
            }

            int L = n - 1, R = 1;
            while(1)
            {
                //a.pb(mp(L, R));
                //printf("%d %d ", a[L], a[R]);
                ans.pb(a[L]);
                ans.pb(a[R]);
                --L, ++R;
                if(R > L) break;
            }
            
            //printf("%d\n", n);
        }
        ans.pb(n);
        //for(auto x : ans) printf("%d ", x);
        //ans.pb(ans[0]);
        //puts("xxx");
        int x = 0;
        printf("Case #%d:\n", Cas);
        rep(i, 1, k) b[i].l = read(), b[i].id = i, b[i].ans.clear();
        sort(b + 1, b + k + 1, cmp);
        rep(i, 1, k)
        {
            b[i].ans.pb(ans[x]);
            while(b[i].l --) 
                b[i].ans.pb(ans[++ x]);
        }
        sort(b + 1, b + k + 1, cmp1);
        rep(i, 1, k)
        {
            rep0(j, sz(b[i].ans))
                printf("%d%c", b[i].ans[j], (j == sz(b[i].ans) - 1 ? '\n' : ' '));
        }
    }

}