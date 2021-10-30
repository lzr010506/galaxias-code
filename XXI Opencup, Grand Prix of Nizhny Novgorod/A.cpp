#include <bits/stdc++.h>

const int MAX_M = 11 + 5 , MAX_N = 1e3 + 10 ;

bool ans[MAX_N] , tmp[MAX_N] ;
int n , m , pre[MAX_M] , ch[MAX_M] , a[MAX_M][MAX_N] ;

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 1 ; i <= m ; ++i)
		for (int j = 0 ; j < n ; ++j) scanf("%d" , &a[i][j]) ;

	for (int i = 1 ; i <= m ; ++i) pre[i] = i ;

	///

	int ti = 1 ;
	for (int i = 2 ; i <= m ; ++i) ti *= i ;

	for (; ti-- ;) {
		for (int i = 1 ; i <= m ; ++i) {
			int nw = pre[i] , j = 0 ;
			for (; tmp[a[nw][j]] ; ++j) ;
			ch[i] = a[nw][j] ; tmp[ch[i]] = 1 ;
		}

		for (int i = 1 ; i <= m ; ++i) ans[ch[i]] = 1 , tmp[ch[i]] = 0 ;
		std::next_permutation(pre + 1 , pre + 1 + m) ;
	}

	int cnt = 0 ;
	for (int i = 1 ; i <= n ; ++i) if (ans[i]) ++cnt ;

	printf("%d\n" , cnt) ;
	for (int i = 1 ; i <= n ; ++i) if (ans[i]) printf("%d " , i) ;

	return 0 ;
}