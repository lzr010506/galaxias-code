#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
inline ll read1()
{
    ll x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 8e5 + 10;
 
int n, Q, cnt, a[N];
int sum[N], tot[N];
pair<int, int> q[N];
 
int main()
{
    int n, Q;
    n = read();
    Q = read();
    rep(i, 1, n) a[i] = read();
    rep(i, 1, Q)
    {
        int op = read();
        int l = read();
        int r = read();
        int x = read();
        if(op == 0) {sum[l] ^= x; sum[r + 1] ^= x; continue;}
        q[++ cnt] = mp(l + 1, l - x);
        q[++ cnt] = mp(r + 1, l - x);
        sum[l] ^= x;
        sum[r + 1] ^= (x + r - l);
    }
    rep0(k, 30)
    {
        rep(i, 1, n + 1) tot[i] = 0;
        int msk = (1 << k) - 1;
        rep(i, 1, cnt)
        {
            int p = ((q[i].X >> k) << k) + (q[i].Y & msk);
            if(p < q[i].X) p += (1 << k);
            if(p <= n) tot[p] ^= (1 << k);
        }
        rep(i, (1 << k), n)
            tot[i] ^= tot[i - (1 << k)];
        rep(i, 1, n) sum[i] ^= tot[i];
    }
    rep(i, 1, n + 1) tot[i] = 0;
    rep(i, 1, n)
    {
        sum[i] ^= sum[i - 1];
        a[i] ^= sum[i];
    }
    rep(i, 1, n) printf("%d ",a[i]);
    return 0;
}
