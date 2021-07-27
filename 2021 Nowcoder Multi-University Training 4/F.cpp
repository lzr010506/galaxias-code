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

struct Edge
{
    int u, v;
}e[210];
int deg[110], f[210];
int find(int x)
{
    if(f[x] == x) return x;
    return f[x] = find(f[x]);
}
int main()
{
    int n = read();
    int m = read();
    rep(i, 1, n) f[i] = i;
    int x = 0;
    rep(i, 1, m)
    {
        int u = read();
        int v = read();
        if(find(u) == find(v)) {x ++; continue;}
        f[find(u)] = find(v);
    }
    int y = 0;
    rep(i, 1, n)
        if(find(i) == i) y ++;
    if((y + x) & 1) puts("Alice");
    else  puts("Bob");



    return 0;
}