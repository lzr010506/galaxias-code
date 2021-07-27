#include <bits/stdc++.h>

#define ll long long

const int G = 3 , MAX_N = 1e6 + 10 , mod = 998244353 ;

char s1[MAX_N] , s2[MAX_N] ;
int T , n , m , ed , res[MAX_N] , ans[MAX_N] ;
int N , M , L , f[MAX_N] , g[MAX_N] , rev[MAX_N] ;

void init() {
	M = n + m ; N = 1 ; L = 0 ;
	for (; N <= M ; N <<= 1 , ++L) ;
	for (int i = 1 ; i < N ; ++i) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1)) ;

	for (int i = 0 ; i <= ed ; ++i) res[i] = 0 ;
	for (int i = 0 ; i <= m + 1 ; ++i) ans[i] = 0 ;
}

int qpow(int a , int t) {
	int s = 1 ;
	for (; t ; t >>= 1 , a = (ll)a * a % mod)
		if (t & 1) s = (ll)s * a % mod ;

	return s ;
}

void fnt(int *f , int ty) {
	for (int i = 0 ; i < N ; ++i) if (i < rev[i]) std::swap(f[i] , f[rev[i]]) ;

	for (int L = 2 ; L <= N ; L <<= 1) {
		int phi = mod - 1 , hf = L >> 1 , wn ;

		if (ty == 1) wn = qpow(G , phi / L) ;
		else wn = qpow(G , phi - phi / L) ;

		for (int i = 0 ; i < N ; i += L)
			for (int j = 0 , w = 1 ; j < hf ; ++j , w = (ll)w * wn % mod) {
				int tmp = (ll)f[i + j + hf] * w % mod ;
				f[i + j + hf] = (f[i + j] - tmp + mod) % mod ;
				(f[i + j] += tmp) %= mod ;
			}
	}

	if (ty == -1) {
		int ny = qpow(N , mod - 2) ;
		for (int i = 0 ; i < N ; ++i) f[i] = (ll)f[i] * ny % mod ;
	}
}

void work(char c) {
	for (int i = 0 ; i < N ; ++i) f[i] = g[i] = 0 ;

	for (int i = 0 ; i <= n ; ++i) if (s1[i] == c) f[i] = 1 ;
	if (c == '*') for (int i = 0 ; i <= m ; ++i) g[i] = 1 ;
	else for (int i = 0 ; i <= m ; ++i) g[i] = (s2[m - i] == '*') || (s2[m - i] == c) ;

	fnt(f , 1) ; fnt(g , 1) ;
	for (int i = 0 ; i < N ; ++i) f[i] = (ll)f[i] * g[i] % mod ;
	fnt(f , -1) ;

	for (int i = 0 ; i <= M ; ++i) {
		int j = i - m ;
		if (j < 0 || j > ed) continue ;

		res[j] += f[i] ;
	}
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d %s %s" , &n , &m , s1 , s2) ;
		--n ; --m ; ed = n - m ; init() ;

		///

		work('*') ;
		for (char c = '0' ; c <= '9' ; ++c)
			work(c) ;

		for (int i = 0 ; i <= ed ; ++i) ++ans[(m + 1) - res[i]] ;
		for (int i = 1 ; i <= m + 1 ; ++i) ans[i] += ans[i - 1] ;
		for (int i = 0 ; i <= m + 1 ; ++i) printf("%d\n" , ans[i]) ;
	}

	return 0 ;
}