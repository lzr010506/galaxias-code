#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 5e5 + 10 ;

int n , a[MAX_N] , s[MAX_N] , g[MAX_N] , cnt[3][3] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	s[0] = g[0] = 0 ;
	for (int i = 1 ; i <= n ; ++i) s[i] = (s[i - 1] + a[i]) % 3 ;
	for (int i = 1 ; i <= n ; ++i) {
		int tmp = a[i] % 3 * s[i] ;
		g[i] = (g[i  - 1] + tmp) % 3 ;
	}

	ll ans = 0 ;
	++cnt[0][0] ;
	for (int i = 1 ; i <= n ; ++i) {
		int nw = (s[i] * s[i] % 3 + 3 - g[i]) % 3 ;

		for (int p = 0 ; p < 3 ; ++p)
			for (int q = 0 ; q < 3 ; ++q) {
				int nn = ((nw - s[i] * p % 3 + 3) % 3 + q) % 3 ;
				if (!nn) ans += cnt[p][q] ;
			}

		++cnt[s[i]][g[i]] ;
	}

	printf("%lld\n" , ans) ;

	return 0 ; 
}