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
#define maxn 10000000
int prime[10000010],num;
int vst[10000010];
int numm[10000010];
int d[10000010], sump[10000010];


inline void pre() {
    d[1] = 1;
    for (int i=2; i<=10000000; i++) {
        if (!vst[i]) prime[++num]=i,d[i]=2,numm[i]=1, sump[num]=sump[num-1]+1;
        for (int j=1; j<=num && i<=10000000/prime[j]; j++) {
            vst[i*prime[j]]=1;
            if (i%prime[j]==0) {
                numm[i * prime[j]] = numm[i] + 1;
                break;
            } else {
                numm[i * prime[j]] = numm[i] + 1;
            }
        }
    }

}


int main()
{
    pre();
  //  cout << numm[12];
    int T = read();
    while(T --)
    {
        int n = read();
        int x = 0;
        rep(i, 1, n)
        {
            int y = read();
            x ^= numm[y];
        }
        if(x) puts("Alice");
        else puts("Bob");
    }

    return 0;
}