#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 , MAX_M = 3e5 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_M << 1] ;

Link *head[MAX_N] ;
int n , m , cur , deg[MAX_N] , f[MAX_N] , wk[MAX_N] ;

bool cmp(int x , int y) {return deg[x] > deg[y] ;}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 0 ; i < m ; ++i) {
		int x , y ; scanf("%d %d" , &x , &y) ;
		++deg[x] ; ++deg[y] ; 

		ins(x , y) ; ins(y , x) ;
	}

	///

	for (int i = 0 ; i < n ; ++i) wk[i] = i ;
	std::sort(wk + 0 , wk + n , cmp) ;

	int ans = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		int x = wk[i] ; f[x] = 1 ;
		for (Link *h = head[x] ; h ; h = h->next) {
			int nx = h->num ;
			if (deg[nx] <= deg[x]) continue ;

			f[x] = std::max(f[x] , f[nx] + 1) ;
		}

		ans = std::max(ans , f[x]) ;
	}

	printf("%d\n" , ans) ;

	return 0 ;
}