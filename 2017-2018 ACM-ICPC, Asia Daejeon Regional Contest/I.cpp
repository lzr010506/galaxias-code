#include <bits/stdc++.h>

const int MAX_N = 1e6 + 10 ;

int n , a[MAX_N] , fail[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[n - i]) ;

	///

	fail[0] = -1 ;
	for (int i = 1 ; i <= n ; ++i) {
		int p = fail[i - 1] ;
		for (; p > -1 && a[p + 1] != a[i] ; p = fail[p]) ;
		++p ; fail[i] = p ;
	}

	int k = n - 1 , p = 1 , ans = k + p ;
	for (int i = 0 ; i < n ; ++i) {
		int np = n - i - fail[n - i] ;
		if (i + np <= ans) {ans = i + np ; k = i ; p = np ;}
	}

	printf("%d %d\n" , k , p) ;

	return 0 ;
}