#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;

const int MAX_N = 1e5 + 10 ;

int n , k , sum ;

int main()
{
	scanf("%d %d" , &n , &k) ;
	for (int i = 1 ; i <= n ; ++i) {
		int a ;
		scanf("%d" ,&a) ; sum += a ;
	}

	///

	printf("%d." , sum / n) ;
	sum %= n ; sum *= 10 ;
	for (int i = 0 ; i < k ; ++i) {
		printf("%d" , sum / n) ;
		sum %= n ; sum *= 10 ;
	}

	return 0;
}
