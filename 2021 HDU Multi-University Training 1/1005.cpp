#include <stdio.h>
#include <stdlib.h>

#define ll long long

const int MAX_N = 1e7 + 10 ;

ll sum[MAX_N] ;

bool ap[MAX_N] ;
int T , n , tot , pri[MAX_N] ;

void init() {
	int N = 1e7 ;

	for (int i = 2 ; i <= N ; ++i) {
		if (!ap[i]) pri[tot++] = i ;

		for (int j = 0 ; j < tot ; ++j) {
			int tmp = i * pri[j] ;
			if (tmp > N) break ;

			ap[tmp] = 1 ;
			if (!(i % pri[j])) break ;
		}
	}

	sum[2] = 0 ;
	for (int i = 3 ; i <= N ; ++i) {
		sum[i] = sum[i - 1] ;
		if (!ap[i]) sum[i] += i ;
	}
}

int main() {
	init() ;

	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d" , &n) ;

		ll res = sum[n] + (((ll)n * (n + 1)) >> 1) - 3 ;
		printf("%lld\n" , res) ;
	}

	return 0 ;
}