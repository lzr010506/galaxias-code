#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define ll unsigned long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
/*
ll fac[100];
int tot;

ll qmul(ll a, ll x, ll mod)
{
	ll res = 0;
	while(x)
	{
		if(x & 1) res = (res + a) % mod;
		a = (a + a) % mod;
		x >>= 1;
	}
	return res;
}

ll qpow(ll a, ll x, ll mod)
{
	ll res = 1;
	while(x)
	{
		if(x & 1) res = 1LL * res * a % mod;
		a = 1LL * a * a % mod;
		x >>= 1;
	} 
	return res;
}

bool miller_rabin(ll n, int S = 50)
{
	if(n == 2) return 1;
	if(n < 2 || !(n & 1)) return 0;
	ll a, x, y, u = n - 1;
	int t = 0;
	while( (u & 1) == 0 ) {u >>= 1; t ++;}
	srand(time(0));
	rep0(i, S) 
	{
		a = rand() % (n - 1) + 1;
		x = qpow(a, u, n);
		rep0(j, t)
		{
			y = qmul(x, x, n);
			if(y == 1 && x != 1 && x != n - 1) return 0;
			x = y;
		}
		if(x != 1) return false;
	}
	return 1;
}

ll pollard_rho(ll x, ll c)
{
	ll i = 1, k = 2;
	ll x0 = rand() % (x - 1) + 1;
	ll y = x0;
	while(1)
	{
		i ++;
		x0 = (qmul(x0, x0, x) + c) % x;
		ll d = abs(__gcd(y - x0, x));
		if(d != 1 && d != x) return d;
		if(y == x0) return x;
		if(i == k) {y = x0; k += k;}
	}
}

void findfac(ll n)
{
	if(n == 1) return;
	if(miller_rabin(n))
	{
		fac[tot ++] = n;
		return;
	}
	ll p = n;
	while(p >= n) p = pollard_rho(p, rand() % (n - 1) + 1);
	findfac(p);
	findfac(n / p);
}
*/
const int MAX_N = 1e5 + 10 ;

ll n ;
int tot , lk[MAX_N] ;

int work(ll n) {
	int rt = ++tot ;
	if (n <= 4) {
		int nw = rt ;
		for (int j = 0 ; j < n - 2 ; ++j) {
			int x = ++tot ;
			lk[x] = nw ; nw = x ;
		}

		return rt ;
	}

	--n ; int nw = rt ;
	if (n & 1) {
		int x = ++tot ;
		lk[x] = rt ; nw = x ; --n ;
	}

	lk[work(2)] = nw ; lk[work(n >> 1)] = nw ;
	return rt ;
}

int main() {
	scanf("%lld" , &n) ;

	work(n) ;

	printf("%d\n" , tot) ;
	for (int i = 2 ; i <= tot ; ++i) printf("%d %d\n" , lk[i] , i) ;

	return 0 ;
}