#include <bits/stdc++.h>

#define ll long long

int T , n , p ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &p) ;

		int d = 0 ;
		for (; (1LL << d) < p ; ++d) ;

		d = std::min(d , n) ;

		ll tot = 0 ;
		for (int i = d ; i < n ; ++i) tot += (1LL << i) ;

		printf("%lld\n" , (tot + p - 1) / p + d) ;
	}

	return 0 ;
}