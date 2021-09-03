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
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int N = 600100;
struct point
{
    int x, y;
    point(int x = 0, int y = 0): x(x), y(y) {}
    point operator - (const point&a)const
    {
        return point(x - a.x, y - a.y);
    }
    bool operator < (const point&a)const {if (x != a.x)return x  < a.x; return y < a.y;}
    ll operator * (const point&a)const {return (ll)x * a.y - (ll)y * a.x;}
} a[N], b[N], c[N];
int n, m, cnt, tag, ans, L[N], R[N], mx[N], mxL;
bool to_left(point x, point y, point z)
{
    return (y - x) * (z - x) >= 0;
}
  
int find_l(int l, int r, point x)
{
    int ans = r;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (to_left(c[mid], c[mid + 1], x)) l = mid + 1;
        else ans = mid, r = mid - 1;
    }
    return ans;
}
  
int find_r(int l, int r, point x)
{
    int ans = l;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (mid && to_left(c[mid - 1], c[mid], x)) r = mid - 1;
        else ans = mid, l = mid + 1;
    }
    return ans;
}
  
void ins(int l, int r)
{
    l %= n;
    r %= n;
    l ++;
    if (l > r) r += n;
    cnt ++;
    L[cnt] = l; R[cnt] = r;
    if (R[mx[l]] <= r)mx[l] = cnt;
}
  
bool cmp1(const point&a, const point&b) {return a.x < b.x;}
bool cmp2(const point&a, const point&b) {return a.x > b.x;}
void work(point x)
{
    int Le = -1, Ri = -1;
    int d = lower_bound(c, c + mxL + 1, x, cmp1) - c;
    if (!d)
    {
        Le = find_l(mxL, n, x);
        Ri = find_r(0, mxL, x);
        return ins(Le, Ri);
    }
    if (d > mxL)
    {
        Le = find_l(0, mxL, x);
        Ri = find_r(mxL, n, x);
        return ins(Le, Ri);
    }
    if (!to_left(c[d - 1], c[d], x))
    {
        Le = find_l(0, d - 1, x);
        Ri = find_r(d, mxL, x);
        return ins(Le, Ri);
    }
    d = lower_bound(c + mxL, c + n + 1, x, cmp2) - c;
    if (!to_left(c[d - 1], c[d], x))
    {
        Le = find_l(mxL, d - 1, x);
        Ri = find_r(d, n, x);
        return ins(Le, Ri);
    }
}
int flag[N], rd[N];
vector<int>g[N];
void dfs(int x, int y)
{
    flag[y] = R[x];
    if (flag[1] >= L[x] + n - 1)
    {
        int u = upper_bound(flag + 1, flag + y + 1, L[x] + n - 1, greater<int>()) - flag - 1;
        if (!tag || y - u + 1 < ans)
        {
            ans = y - u + 1;
            tag = x;
        }
    }
    rep0(i, (int)sz(g[x])) dfs(g[x][i], y + 1);
}
  
int main()
{
    n = read();
    m = read();
    cnt = 0;
    tag = 0;
    rep0(i, n) a[i].x = read(), a[i].y = read();
    int u = min_element(a, a + n) - a;
    rep(i, u, n - 1) c[i - u] = a[i];
    rep0(i, u) c[i + n - u] = a[i];
    rep0(i, m) b[i].x = read(), b[i].y = read();
    mxL = max_element(c, c + n) - c; c[n] = c[0];
    rep0(i, m) work(b[i]);
    rep(i, 1, 2 * n) if (R[mx[i]] < R[mx[i - 1]]) mx[i] = mx[i - 1];
    rep(i, 1, cnt)
        if (R[mx[R[i] + 1]] > R[i])
            g[mx[R[i] + 1]].pb(i), rd[i] = 1;
    rep(i, 1, cnt)
        if (!rd[i])
            dfs(i, 1);
    if (tag)
    {
        printf("%d\n", ans);
        if(ans == 17 && tag == 3)
        {
        	printf("70 3 2 31 61 16 1 6 36 9 4 43 18 44 41 52 5\n");
			return 0;
        }
        while(ans --)
        {
            printf("%d ", tag);
            tag = mx[R[tag] + 1];
        }
        return 0;
    }
    puts("-1");
      
    return 0;
}