#include <bits/stdc++.h>

#define ll long long

const int tr[3] = {2 , 3 , 6} ;

int n ;

inline ll cal(int x) {
	ll s = 1 ;
	for (int i = 0 ; i <= x ; ++i) s *= 3 ;

	return ((s - 1) >> 1) - 1 ;
}

inline ll pw(int x) {
	ll s = 1 ;
	for (int i = 0 ; i < x ; ++i) s *= 3 ;

	return s ;
}

int main() {
	scanf("%d" , &n) ; --n ;
	if (!n) {printf("2\n") ; return 0 ;}

	int l = 0 ;
	for (; cal(l) < n ; ++l) ;

	n -= cal(l - 1) ;
	for (; l-- ;) {
		int ned = pw(l) , a ;
		if (ned) {a = n / ned ; n %= ned ;}
		else a = n ;

		printf("%d" , tr[a]) ;
	}
	printf("\n") ;

	return 0 ;
}