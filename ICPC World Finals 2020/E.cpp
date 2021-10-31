#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 2e5 + 10 ;

int n , m ;
ll a[MAX_N] , b[MAX_N] ;

void add(int x , int y , ll *f , int t) {
	f[x] += t ; f[y + 1] -= t ; ;
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (; m-- ;) {
		char c ; int x , y ; getchar() ;
		scanf("%c %d %d" , &c , &x , &y) ;

		if (c == 'R') add(x , y , b , 1) ;
		else if (c == 'D') add(x , y , b , -1) ;
		else if (c == 'H') {
			if (x == y) add(x , x , b , 1) ;
			else {
				int len = y - x , d = len >> 1 ;

				add(x , x + d , a , 1) ;
				add(x , x + d , b , 1 - x) ;

				if (!(len & 1)) --d ;
				add(y - d , y , a , -1) ;
				add(y - d , y , b , y + 1) ;
			}
		}
		else {
			if (x == y) add(x , x , b , -1) ;
			else {
				int len = y - x , d = len >> 1 ;

				add(x , x + d , a , -1) ;
				add(x , x + d , b , x - 1) ;

				if (!(len & 1)) --d ;
				add(y - d , y , a , 1) ;
				add(y - d , y , b , -y - 1) ;
			}
		}
	}

	///

	for (int i = 1 ; i <= n ; ++i) {
		a[i] += a[i - 1] , b[i] += b[i - 1] ;
		printf("%lld\n" , a[i] * i + b[i]) ;
	}

	return 0 ;
}