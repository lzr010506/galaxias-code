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

const int mod = 1e9 + 7;
const int N = 6e5 + 10;

int b[N], a[N], vis[N], id[N];
int cnt, A, B;

void dfs(int rt, int num)
{
    vis[rt] = 1;
    if(num & 1) num --, a[rt] = 2;
    if(num)
    {
        dfs(ls, num >> 1);
        dfs(rs, num >> 1);
    }
}

void cal(int rt)
{
    if(a[rt] == 0) a[rt] = 1, cnt ++;
    if(vis[ls]) cal(ls);
    if(vis[rs]) cal(rs);
}

void dfs1(int rt, int cnt)
{
    vis[rt] = 1;
    if(!a[rt] && cnt) a[rt] = 1, cnt --;
    if(cnt > 0)
    {
        int L = cnt / 2, R = cnt - cnt / 2;
        dfs1(ls, L);
        dfs1(rs, R);
    }
}

void fp(int rt)
{
    if(a[rt]) b[rt] = ++ cnt, id[cnt] = rt;
    if(vis[ls]) fp(ls);
    if(vis[rs]) fp(rs);
}

int main()
{
    A = read();
    B = read();
    dfs(1, B);
    //puts("1111");
    cal(1);

    if(cnt > A) {puts("-1"); return 0;}
    A -= cnt;
    dfs1(1, A);
    //puts("11111");
    cnt = 0;
    fp(1);
    rep(i, 1, cnt)
        printf("%d %d %d\n", a[id[i]], b[id[i] << 1], b[id[i] << 1 | 1]);
    return 0;
}