#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e6 + 10 , mod = 998244353 ;

bool ap[MAX_N] ;
int m , k , tot , pri[MAX_N] , mu[MAX_N] ;

int qpow(int a , int t) {
	int s = 1 ;
	for (; t ; t >>= 1 , a = (ll)a * a % mod)
		if (t & 1) s = (ll)s * a % mod ;

	return s ;
}

void init() {
	mu[1] = 1 ;
	for (int i = 2 ; i <= k ; ++i) {
		if (!ap[i]) {mu[i] = mod - 1 ; pri[tot++] = i ;}

		for (int j = 0 ; j < tot ; ++j) {
			int tmp = i * pri[j] ;
			if (tmp > k) break ;

			ap[tmp] = 1 ;
			if (!(i % pri[j])) {mu[tmp] = 0 ; break ;}
			else mu[tmp] = mod - mu[i] ;
		}
	}
}

int main() {
	scanf("%d %d" , &m , &k) ;
	init() ;

	int res = 1 ;
	for (int i = 1 ; i <= k ; ++i) {
		int tmp = mu[i] , pw = (qpow(((k / i) << 1) + 1 , m) + mod - 1) % mod ;
		tmp = (ll)tmp * pw % mod ;

		(res += tmp) %= mod ;
	}

	printf("%d\n" , res) ;

	return 0 ;
}