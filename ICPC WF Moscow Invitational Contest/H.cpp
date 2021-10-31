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
const int N = 1e4 + 10;
char a[N];
int s[N], n;
int ans[N];
int dy[N];
 
int dfs(int l, int r) 
{
    if (l >= r - 1) return 0;
    int S = 0;
    rep(i, l, r)
    {
        if (a[i] == '(') S ++;
        if (a[i] == ')') S --;
        if (S == 0) 
        {
            if (i == r) return dfs(l + 1, r - 1);
            return max(dfs(l, i) + 1, dfs(i + 3, r));
            break;
        }
    }
    return 0;
}
 
int main()
{
    scanf("%s", a);
    n = strlen(a);
    printf("%d\n", dfs(0, n - 1));
        
    
 
    return 0;
}