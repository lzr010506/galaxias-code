#include <stack>
#include <stdio.h>
#include <stdlib.h>

const int MAX_N = 2e3 + 10 ;

struct data {int x , y ;} ;

std::stack<data> sta ;

int T , n , m , a[MAX_N][MAX_N] , f[MAX_N][MAX_N] , le[MAX_N] , ri[MAX_N] ;

inline void clear() {
	for (; !sta.empty() ; sta.pop()) ;
}

void work(int n , int x , int y , int ad , int *g) {
	clear() ;
	for (int i = x ; i != y ; i += ad) {
		for (; !sta.empty() && sta.top().y >= f[n][i] ; sta.pop()) ;

		if (sta.empty()) g[i] = x ;
		else g[i] = sta.top().x + ad ;

		sta.push((data){i , f[n][i]}) ;
	}
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &m) ;
		for (int i = 1 ; i <= n ; ++i)
			for (int j = 1 ; j <= m ; ++j) scanf("%d" , &a[i][j]) ;

		///

		for (int j = 1 ; j <= m ; ++j) {
			f[n][j] = 1 ;
			for (int i = n - 1 ; i ; --i)
				if (a[i][j] <= a[i + 1][j]) f[i][j] = f[i + 1][j] + 1 ;
				else f[i][j] = 1 ;
		}

		int res = 0 ;
		for (int i = 1 ; i <= n ; ++i) {
			work(i , 1 , m + 1 , 1 , le) ;
			work(i , m , 0 , -1 , ri) ;

			for (int j = 1 ; j <= m ; ++j) res = std::max(res , f[i][j] * (ri[j] - le[j] + 1)) ;
		}

		printf("%d\n" , res) ;
	}

	return 0 ;
}