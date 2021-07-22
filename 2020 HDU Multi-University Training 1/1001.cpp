#include <stdio.h>
#include <stdlib.h>

#define ll long long

ll n ;
int T ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%lld" , &n) ;
		--n ; n >>= 1 ;

		ll r = 1 ;
		for (; n ; n >>= 1 , r <<= 1) ;
		printf("%lld\n" , r - 1) ;
	}

	return 0 ;
}