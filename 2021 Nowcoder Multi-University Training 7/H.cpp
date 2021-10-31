#include <bits/stdc++.h>

#define ll long long

const int N = 1e6 , MAX_N = 1e6 + 10 ;

int n , cnt[MAX_N] ;

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		int a ; scanf("%d" , &a) ;
		++cnt[a] ;
	}

	///

	ll ans = 0 ;
	for (int i = 1 ; i <= N ; ++i)
		for (int j = i ; j <= N ; j += i) {
			int k = j / i ;

			ans += (ll)cnt[i] * cnt[j] * cnt[k] ;
		}

	printf("%lld\n" , ans) ;

	return 0 ;
}