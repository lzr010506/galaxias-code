#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 ;

struct ANS{int id ; ll l , r ;} ;

std::vector<ANS> ans[MAX_N] ;

ll s ;
int n , m , a[MAX_N] ;

bool check(ll k) {
	ll lef = k ; int nw = 1 ;
	for (int i = 1 ; i <= n ; ++i) {
		if (a[i] > lef) {++nw ; lef = k - (a[i] - lef) ;}
		else lef -= a[i] ;

		if (!lef) {lef = k ; ++nw ;}
	}

	if (lef == k) --nw ;
	return nw <= m ;
}

void work(ll k) {
	ll lef = k ; int nw = 1 ;
	for (int i = 1 ; i <= n ; ++i) {
		if (a[i] > lef) {
			ans[i].push_back((ANS){nw + 1 , 0LL , a[i] - lef}) ;
			ans[i].push_back((ANS){nw , k - lef , k}) ;
			++nw ; lef = k - (a[i] - lef) ;
		}
		else {
			ans[i].push_back((ANS){nw , k - lef , k - lef + a[i]}) ;
			lef -= a[i] ;
		}

		if (!lef) {lef = k ; ++nw ;}
	}
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

	///

	ll L = a[1] ; s = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		s += a[i] ; L = std::max(L , (ll)a[i]) ;
	}

	ll R = s ; --L ;
	for (; L + 1 < R ;) {
		ll mid = (L + R) >> 1 ;

		if (check(mid)) R = mid ;
		else L = mid ;
	}

	///

	work(R) ;

	for (int i = 1 ; i <= n ; ++i) {
		int s = ans[i].size() ;

		printf("%d " , s) ;
		for (int j = 0 ; j < s ; ++j) {
			printf("%d %lld %lld" , ans[i][j].id , ans[i][j].l , ans[i][j].r) ;

			if (j + 1 != s) printf(" ") ;
			else printf("\n") ;
		}
	}

	return 0 ;
}