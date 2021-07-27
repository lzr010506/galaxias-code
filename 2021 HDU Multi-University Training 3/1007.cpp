#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

struct data {
	int r , g , b ;

	void inf() {
		r = std::min(r , 255) ;
		g = std::min(g , 255) ;
		b = std::min(b , 255) ;
	}
	friend data operator +(data a , data b) {return (data){a.r + b.r , a.g + b.g , a.b + b.b} ;} ;
	friend data operator -(data a , data b) {return (data){a.r - b.r , a.g - b.g , a.b - b.b} ;} ;
}col[MAX_N] , sum[MAX_N] ;

char s[MAX_N] ;
int T , n , q , a[MAX_N] , mp[MAX_N] , ty[MAX_N] ;

int trans(char c) {
	if (c >= '0' && c <= '9') return c - '0' ;
	else return c - 'A' + 10 ;
}

void rtrans(int a) {
	if (a < 10) printf("%d" , a) ;
	else printf("%c" , char(a + 'A' - 10)) ;
}

void printcol(data a) {
	a.inf() ;

	rtrans(a.r / 16) ; rtrans(a.r % 16) ;
	rtrans(a.g / 16) ; rtrans(a.g % 16) ;
	rtrans(a.b / 16) ; rtrans(a.b % 16) ;
	printf("\n") ;
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		scanf("%d %d" , &n , &q) ;
		for (int i = 1 ; i <= n ; ++i) {
			scanf("%d %s" , &ty[i] , s) ;

			for (int j = 0 ; j < 6 ; ++j) a[j] = trans(s[j]) ;
			col[i] = (data){a[0] * 16 + a[1] , a[2] * 16 + a[3] , a[4] * 16 + a[5]} ;
		}

		///

		mp[0] = 0 ; sum[0] = (data){0 , 0 , 0} ;
		for (int i = 1 ; i <= n ; ++i) {
			mp[i] = mp[i - 1] ;
			sum[i] = sum[i - 1] + col[i] ;
			if (ty[i] == 1) mp[i] = i ;
		}

		for (; q-- ;) {
			int x , y ; scanf("%d %d" , &x , &y) ;
			x = std::max(x , mp[y]) ;
			printcol(sum[y] - sum[x - 1]) ;
		}
	}

	return 0 ;
}