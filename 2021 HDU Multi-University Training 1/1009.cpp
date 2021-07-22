#include <bits/stdc++.h>

const int MAX_N = 5e5 + 10 ;

struct data {int x , y , d ;}eg[MAX_N] ;

int T , n , m , k , sum , fa[MAX_N] ;

int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

bool check(int x) {
	for (int i = 1 ; i <= n ; ++i) fa[i] = -1 ;

	sum = n ;
	for (int i = 0 ; i < m ; ++i) {
		data *p = &eg[i] ;
		if (p->d > x) continue ;

		int fx = findset(p->x) , fy = findset(p->y) ;
		if (fx == fy) continue ;
		fa[fx] = fy ; --sum ;
	}

	return sum > k ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		int L = -1 , R = 0 ;

		scanf("%d %d %d" , &n , &m , &k) ;
		for (int i = 0 ; i < m ; ++i)
			scanf("%d %d %d" , &eg[i].x , &eg[i].y , &eg[i].d) , R = std::max(R , eg[i].d) ;

		///

		for (; L + 1 < R ;) {
			int mid = (L + R) >> 1 ;
			if (check(mid)) L = mid ;
			else R = mid ;
		}

		check(R) ;
		if (sum == k) printf("%d\n" , R) ;
		else printf("-1\n") ;
	}

	return 0 ;
}