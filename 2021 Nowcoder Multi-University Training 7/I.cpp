#include <bits/stdc++.h>

#define ll long long

const int L = 31 ;

int x , s ;

int main() {
	scanf("%d %d" , &x , &s) ;

	ll r = 1 ;
	for (int i = 0 ; i < L ; ++i) {
		int p1 = x & (1 << i) ? 1 : 0 , p2 = s & (1 << i) ? 1 : 0 ;

		if (p1) {
			if (p2) r <<= 1 ;
			else r = 0 ;
		}
	}

	if (x == s) --r ;
	printf("%lld\n" , r) ;

	return 0 ;
}