#include <bits/stdc++.h>



int SET = 670 , MAX_N = 1e5 + 10 , MAX_L = SET + 10 ;

int f[2][MAX_L] ;
int T , n , k , x[MAX_N] , y[MAX_N] ;

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ;
		
		for (int i = 1 ; i <= n ; ++i) {
			int r ; scanf("%d" , &r) ;
			scanf("%d %d" , &x[r] , &y[r]) ;
		}

		///

		f[0][0] = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			int st = i&1;
			memset(f[st],-0x3f,sizeof(int)*(std::min(n, SET)+1));
			if(1<=std::min(i-1, SET)) f[st][0] =std::max(f[st][0] , f[st^1][1] - y[i] + k);
			f[st][0] = std::max(f[st][0],f[st^1][0]-y[i]);
			for (int j = 1 ; j <= std::min(SET, i) ; ++j) {
				if(j != 0)f[st][j] = std::max(f[st][j], f[st^1][j - 1] - x[i]) ;
				if (j+1 <= std::min(i-1, SET)) f[st][j] = std::max(f[st][j] , f[st^1][j + 1] - y[i] + k) ;
			}
		}

		int ans = f[n&1][0] ;
		for (int i = 0 ; i <= std::min(SET, n) ; ++i) ans = std::max(ans , f[n&1][i]) ;
		printf("%d\n" , ans) ;
	}

	return 0 ;
}
