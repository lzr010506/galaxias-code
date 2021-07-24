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
const int N = 5010;
int n , m , a , mm, b , c , d , p , tot  ;

int closest[N],lowcost[N];
int G[N][N];//邻接矩阵
int prim()
{
    for(int i=0;i<=mm;i++)
    {
        lowcost[i] = INF;
    }
    for(int i=0;i<=mm;i++)
    {
        closest[i] = 0;
    }
    closest[1] = -1;
    int num = 0,ans = 0,e = 0;
    while (num < mm-1)
    {
        int micost = INF,miedge = -1;
        if(e <= n)
        {
            for(int i = n + 1; i <= mm; i ++)
                if(closest[i] != -1)
                {
                    int temp = G[e][i - n];
                    if(temp < lowcost[i])
                    {
                        lowcost[i] = temp;
                        closest[i] = e;
                    }
                    if(lowcost[i] < micost)
                        micost = lowcost[miedge = i];
                }
        }
        else
        {
            for(int i = 1; i <= n; i ++)
                if(closest[i] != -1)
                {
                    int temp = G[e - n][i];
                    if(temp < lowcost[i])
                    {
                        lowcost[i] = temp;
                        closest[i] = e;
                    }
                    if(lowcost[i] < micost)
                        micost = lowcost[miedge = i];
                }
        }
        ans += micost;
        closest[e = miedge] = -1;
        num++;
    }
    return ans;
}

int main()
{
    scanf("%d %d %d %d %d %d %d" , &n , &m , &a , &b , &c , &d , &p) ;
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= m ; ++j) {
            a = (1LL * a * a * b + 1LL * a * c + d) % p ;
            G[i][j] = a;
           // cout <<G[i][j] << " "; 
        }
    mm = n + m;
    printf("%d\n", prim());



    return 0;
}