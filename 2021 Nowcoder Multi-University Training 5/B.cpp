#include <bits/stdc++.h>

#define db double

const db eps = 1e-13 ;
const int MAX_N = 1e5 + 10 ;

int n , m ;
db C , w[MAX_N] , s[MAX_N] ;

db cal(db s , int k) {
	for (; fabs(s) > eps && k ; --k) s /= 2.0 ;

	return s ;
}

int main() {
	scanf("%d %lf" , &n , &C) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%lf" , &w[i]) ;

	std::sort(w + 1 , w + 1 + n) ;

	s[0] = 0 ;
	for (int i = 1 ; i <= n ; ++i) s[i] = s[i - 1] + w[i] ;

	///

	db ans = C ;
	for (int i = 1 ; i < n ; ++i) ans += cal(s[i] , n - i) ;

	if (ans > s[n]) printf("%0.7lf\n" , s[n]) ;
	else printf("%0.7lf\n" , ans) ;

	return 0 ;
}