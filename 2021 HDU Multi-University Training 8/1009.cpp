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
#define ULL unsigned long long
using namespace std;
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
    char c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
const int N = 1000010;
char s[N], p[N];
unordered_map<ULL, int> M[50], ans[50];

int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%s",s + 1);
        int n = strlen(s + 1);
        rep(i, 1, 30) M[i].clear(), ans[i].clear();

        rrep(i, n, 1)
        {
            ULL st = 0;
            for(int j = i, k = 1; j <= n && k <= 30; k ++, j ++)
            {
                st = st * 137ull + s[j] - 'a' + 1;
                if(M[k][st] == 0)
                {
                    M[k][st] = i;
                    ans[k][st] = 1;
                }
                else 
                {
                    if(M[k][st] > j)
                    {
                        M[k][st] = i;
                        ans[k][st] = ans[k][st] + 1;
                    }
                } 
            }
        }
        int Q;
        scanf("%d", &Q);
        while(Q --)
        {
            scanf("%s", p + 1);
            int m = strlen(p + 1);
            ULL st = 0;
            rep(i, 1, m)
                st = st * 137ULL + p[i] - 'a' + 1;
            if(M[m][st]) printf("%d\n", ans[m][st]);
            else puts("0");
        }
    }
    return 0;
}
