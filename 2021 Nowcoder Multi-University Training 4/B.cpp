#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 100 + 10 , mod = 998244353 ;

inline int qpow(int a , int t) {
	int s = 1 ;
	for (; t ; t >>= 1 , a = (ll)a * a % mod)
		if (t & 1) s = (ll)s * a % mod ;

	return s ;
}

struct data {
	int a , b , c ;
	// a = sum p^k , b = sum k * p^k , c = sum k^2 * p^k

	friend data operator +(data x , data y) {
		return (data){(x.a + y.a) % mod , (x.b + y.b) % mod , (x.c + y.c) % mod} ;
	}
	friend data operator *(data x , data y) {
		data ans ;

		ans.a = (ll)x.a * y.a % mod ;
		ans.b = ((ll)x.b * y.a % mod + (ll)y.b * x.a % mod) % mod ;
		ans.c = (ll)y.a * x.c % mod ;
		ans.c = (ans.c + (ll)x.a * y.c) % mod ;
		ans.c = (ans.c + 2LL * x.b % mod * y.b % mod) % mod ;

		return ans ;
	}
	void cal(int p) {
		int ny = qpow((mod + 1 - p) % mod , mod - 2) ;
		a = (ll)p * ny % mod ;
		b = (ll)ny * ny % mod * p % mod ;
		c = (ll)ny * ny % mod * ny % mod ;
		c = (ll)c * p % mod * (p + 1) % mod ;
	}
}f[MAX_N] ;

int n , tw , p[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &p[i]) , tw += p[i] ;

	tw = qpow(tw , mod - 2) ;
	for (int i = 1 ; i <= n ; ++i) p[i] = (ll)p[i] * tw % mod ;

	///

	f[1].cal(p[1]) ;
	for (int i = 2 ; i <= n ; ++i) {
		data nw , res = (data){0 , 0 , 0} ;

		nw.cal(p[i]) ; res = res + nw ;
		for (int j = 1 ; j < i ; ++j) res = res + f[j] * nw ;
		f[i] = res ;
	}

	int ans = 0 ;
	for (int i = 2 ; i <= n ; ++i)
		for (int j = 1 ; j < i ; ++j) {
			data *pt = &f[i] ; int p2 = p[j] ;

			ans = (ans + (ll)p2 * pt->c % mod) % mod ;
			ans = (ans + 2LL * p2 % mod * pt->b % mod) % mod ;
			ans = (ans + (ll)p2 * pt->a % mod) % mod ;
		}

	printf("%d\n" , ans) ;

	return 0 ;
}