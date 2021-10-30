#include <bits/stdc++.h>

#define ll long long

const int L = 61 , MAX_L = 64 + 5 , MAX_N = 200 + 10 , MAX_M = 2e5 ;

std::bitset<200010> f[MAX_L] , g ;

ll n , S ;
int T , m , a[MAX_N] ;

void update(int x , int ty) {
	for (int i = 0 ; i <= MAX_M ; ++i)
		if ((i & 1) == ty) f[x][i >> 1] = g[i] ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%lld %lld %d" , &n , &S , &m) ;

		for (int i = 0 ; i < m ; ++i) scanf("%d" , &a[i]) ;
		for (int i = 0 ; i <= L ; ++i) f[i].reset() ;

		///

		f[0][0] = 1 ;
		for (int i = 0 ; i < L ; ++i) {
			g.reset() ;

			if ((n >> i) & 1) for (int j = 0 ; j < m ; ++j) g ^= (f[i] << a[j]) ;
			else g = f[i] ;

			update(i + 1 , (S >> i) & 1) ;
		}

		std::cout << f[L][0] << std::endl ;
	}

	return 0 ;
}