#include <bits/stdc++.h>

const int MAX_N = 2e3 + 10 ;

struct data {
	int x , y , id ;
}a[MAX_N] ;

int n , m , ans[MAX_N] ;

bool cmp(data a , data b) {return a.x < b.x || (a.x == b.x && a.y < b.y) ;}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d %d" , &a[i].x , &a[i].y) , a[i].id = i ;

	///

	std::sort(a + 1 , a + 1 + n , cmp) ;

	printf("%d\n" , (n << 1) - 1) ;
	for (int i = 1 ; i <= n ; ++i) printf("%d " , a[i].id) ;
	for (int i = n - 1 ; i ; --i) printf("%d " , a[i].id) ;

	return 0 ;
}