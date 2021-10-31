#include <bits/stdc++.h>

const int MAX_N = 50 + 10 , MAX_M = 2500 + 10 , INF = 0x3f3f3f3f ;

struct data {int x , y ;} ;

std::vector<int> dis[MAX_M] ;
std::vector<data> pt[MAX_M] ;

int n , k ;

int cal(data a , data b) {
	return abs(a.x - b.x) + abs(a.y - b.y) ;
}

int main() {
	scanf("%d %d" , &n , &k) ;
	for (int i = 1 ; i <= n ; ++i)
		for (int j = 1 ; j <= n ; ++j) {
			int x ; scanf("%d" , &x) ;
			pt[x].push_back((data){i , j}) ;

			if (x > 1) dis[x].push_back(INF) ;
			else dis[x].push_back(0) ;
		}

	///

	bool ok = 1 ;
	for (int i = 1 ; i <= k ; ++i) if (!pt[i].size()) ok = 0 ;
	if (!ok) {printf("-1\n") ; return 0 ;}

	int res = k > 1 ? INF : 0 ;
	for (int i = 2 ; i <= k ; ++i) {
		int s1 = pt[i - 1].size() , s2 = pt[i].size() ;

		for (int p = 0 ; p < s1 ; ++p)
			for (int q = 0 ; q < s2 ; ++q)
				dis[i][q] = std::min(dis[i][q] , dis[i - 1][p] + cal(pt[i - 1][p] , pt[i][q])) ;

		if (i == k) for (int j = 0 ; j < s2 ; ++j) res = std::min(res , dis[i][j]) ;
	}

	printf("%d\n" , res) ;

	return 0 ;
}