#include <bits/stdc++.h>

#define ll long long

std::map<ll , ll> f ;

int T ;
ll n , k ;

ll solve(ll x) {
	if (x <= k) return 1 ;
	if (f.count(x)) return f[x] ;

	ll res = 1 + solve(x >> 1) + solve(x - (x >> 1)) ;
	return (f[x] = res) ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%lld %lld" , &n , &k) ;

		f.clear() ; f[1] = 1 ;
		printf("%lld\n" , solve(n)) ;
	}

	return 0 ;
}