#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int n, L, R, a[200001];
int b[200001];
ll c[200010];
unsigned ll seed;
unsigned ll xorshift64()
{
	unsigned ll x = seed;
	x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
	return seed = x;
}

int gen()
{
	return xorshift64() % (R - L + 1) + L;
}

struct data {
	int x , y , val ;
} ;

std::vector<data> eg ;
int fa[200001] , ud[200001] ;

bool cmp(data a , data b) {return a.val < b.val ;}

int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

int main()
{
	scanf("%d%d%d%llu", &n, &L, &R, &seed);
	rep(i, 1, n) a[i] = gen();
	if(L == R)
	{
		printf("%lld\n", 1LL * (n - 1) * L);
		return 0;
	}
	if(R - L > 10000)
	{
		int g = a[1];
		rep(i, 1, n) g = __gcd(g, a[i]);
		printf("%lld\n", 1LL * g * (n - 1));
		return 0;
	}
	rep(i, 1, n) b[a[i]] ++;

	rep(i, L, R)
		rep(j, i+1, R)
		{
			if (!b[i] || !b[j]) continue ;

			int g = __gcd(i, j);
			eg.push_back((data){i , j , g}) ;
		}

	int m = eg.size() ;
	if (!m) {
		printf("%lld\n" , a[1] * (n - 1)) ;
		return 0 ;
	}

	std::sort(eg.begin() , eg.end() , cmp) ;
	for (int i = 1 ; i <= R ; ++i) fa[i] = -1 , ud[i] = 0 ;

	ll res = 0 ;
	for (int i = 0 ; i < m ; ++i) {
		int x = eg[i].x , y = eg[i].y , v = eg[i].val ,
			fx = findset(x) , fy = findset(y) ;

		if (fx == fy) continue ;

		fa[fx] = fy ; res += v ;
		if (!ud[x]) ud[x] = 1 , res += (ll)v * (b[x] - 1) ;
		if (!ud[y]) ud[y] = 1 , res += (ll)v * (b[y] - 1) ;
	}

	printf("%lld\n" , res) ;
	
	return 0;
}