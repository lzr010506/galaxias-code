#include <bits/stdc++.h>

const int x[5] = {4 , 8 , 13 , 20 , 30} ;

int n , a[5] ;

int main() {
	scanf("%d" , &n) ;
	for (; n-- ;) {
		for (int i = 0 ; i < 5 ; ++i) scanf("%d" , &a[i]) ;

		int p = 0 ;
		for (; p < 5 && a[0] > x[p] ; ++p) ;

		for (int i = 0 ; i < p ; ++i) printf("0.0 ") ;
		if (p < 5) printf("1.0 ") ;
		for (int i = 0 ; i < 4 - p ; ++i) printf("0.0 ") ;
		printf("\n") ; fflush(stdout) ;
	}

	return 0 ;
}

/*
#include <bits/stdc++.h>

#define db double
#define ll long long

const db INF = 1e15 ;
const int MAX_N = 100 + 10 ;

int n = 100 , g[MAX_N][MAX_N] ;
db pi[MAX_N] , f[MAX_N][MAX_N] ;

ll rep(ll x , int t) {
	ll s = 1 ;
	for (int i = 0 ; i < t ; ++i) s *= (x - i) ;
	for (int i = 1 ; i <= t ; ++i) s /= i ;

	return s ;
}

int main() {
	f[0][0] = 0 ;
	for (int i = 1 ; i <= n ; ++i) f[0][i] = INF ;

	pi[0] = 0 ;
	for (int i = 1 ; i <= n ; ++i)
		pi[i] = pi[i - 1] + rep(100 - i , 4) * 1.0 / rep(100 , 5) ;

	///

	for (int i = 1 ; i <= 6 ; ++i) {
		for (int j = 0 ; j < i ; ++j) f[i][j] = INF ;
		for (int j = i ; j <= n ; ++j) {
			db res = INF ; int p = 0 ;
			for (int k = 0 ; k < j ; ++k) {
				db tmp = f[i - 1][k] + (pi[j] - pi[k]) * (pi[j] - pi[k]) ;
				if (res > tmp) res = tmp , p = k ;
			}
			f[i][j] = res ; g[i][j] = p ;
		}
	}

	int p = g[6][n] ;
	printf("%0.8lf\n" , 1 - f[6][n]) ;
	for (int i = 5 ; i ; --i) {
		printf("%d\n" , p) ;
		p = g[i][p] ;
	}

	return 0 ;
}
*/