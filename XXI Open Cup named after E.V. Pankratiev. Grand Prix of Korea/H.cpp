#include <bits/stdc++.h>
using namespace std ;

#define ll long long

const int MAX_N = 2e5 + 10 ;

int n ;
ll sum , b[MAX_N] , c[MAX_N] ;

bool check(int x) {
	for (int i = 0 ; i < x ; ++i) b[i] = 0 ;
	for (int i = x ; i <= n ; ++i) b[0] += c[i] ;
	for (int i = 0 ; i < x ; ++i) b[i] += c[i] ;

	ll ned = 1 ;
	for (int i = x - 1 ; i >= 0 ; --i) {
		if (ned > sum) return 0 ;

		if (ned < b[i]) b[0] += b[i] - ned ;
		else ned = ned + ned - b[i] ;
	}

	if (ned <= b[0]) return 1 ;
	else return 0 ;
}

int main() {
	sum = 0 ;
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) scanf("%lld" , &c[i]) , sum += c[i] ;

	if(sum == 1)
	{
		if(c[0] == 1) cout << 1 << endl;
		else for (int i = 0 ; i < n ; ++i) if(c[i] == 1) cout << i << endl;
		return 0;
	}

	///

	int L = 0 , R = n + 100 ;
	for (; L + 1 < R ;) {
		int mid = (L + R) >> 1 ;
		if (check(mid)) L = mid ;
		else R = mid ;
	}

	printf("%d\n" , L) ;

	return 0 ;
} 