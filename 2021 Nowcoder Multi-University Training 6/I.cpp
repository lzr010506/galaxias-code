#include <bits/stdc++.h>

const int MAX_N = 1e3 + 10 ;

struct data {int x , y ;} ;

std::vector<data> ara ;

int T , n , k , s[MAX_N] ;

void add(int x , int y) {
	++s[x] ; --s[y + 1] ;
}

int main() {
	scanf("%d" , &T) ;

	for (; T-- ;) {
		scanf("%d %d" , &n , &k) ;
		for (int i = 0 ; i <= n + 1 ; ++i) s[i] = 0 ;
		for (; k-- ;) {
			int x , y ; scanf("%d %d" , &x , &y) ;

			if (x > y) add(x , n) , add(1 , y) ;
			else add(x , y) ;
		}

		for (int i = 1 ; i <= n + 1 ; ++i) s[i] += s[i - 1] ;

		///

		ara.clear() ;

		int pre ;
		for (int i = 1 ; i <= n + 1 ; ++i)
			if (s[i] && !s[i - 1]) pre = i ;
			else if (!s[i] && s[i - 1]) ara.push_back((data){pre , i - 1}) ;

		int m = ara.size() ;
		if (m > 1 && ara[m - 1].y == n && ara[0].x == 1) {
			ara[0].x = ara[m - 1].x ;
			--m ;
		}

		///

		printf("%d\n" , m) ;
		for (int i = 0 ; i < m ; ++i) {
			int j = (i + 1) % m ;
			printf("%d %d\n" , ara[j].x , ara[i].y) ;
		}
	}

	return 0 ;
}