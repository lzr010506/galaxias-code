#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 ;

struct data {
	int m , p , pl ;
}a[MAX_N] ;
struct info {
	ll num ; int pl ;
	friend bool operator <(info a , info b) {return a.num > b.num || (a.num == b.num && a.pl > b.pl) ;}
} ;

std::set<info> ch , sw1 ;

int n , sta[MAX_N] , lst1[MAX_N] , lst2[MAX_N] ;

bool cmp1(data a , data b) {return a.m > b.m ;}

bool cmp2(data a , data b) {return a.p > b.p ;}

bool cmp3(data a , data b) {return a.pl < b.pl ;}

bool check(int k) {
	if ((k << 1) > n) return 0 ;

	ll sum = 0 ;
	ch.clear() ; sw1.clear() ;
	for (int i = 1 ; i <= n ; ++i) sta[i] = -1 ;

	for (int i = 1 ; i <= k ; ++i) {
		int x = lst1[i] ;
		sum += a[x].m ; sta[x] = 0 ;
		sw1.insert((info){-a[x].m + a[x].p , x}) ;
	}

	int ned = k ;
	for (int i = 1 ; i <= n && ned ; ++i) {
		int x = lst2[i] ;
		if (!sta[x]) continue ;

		--ned ; sum += a[x].p ; sta[x] = 1 ;
		ch.insert((info){a[x].p , x}) ;
	}

	///

	if (sum >= 0) return 1 ;

	for (int i = k + 1 ; i <= n ; ++i) {
		int x = lst1[i] ;

		if (sta[x] == -1) {
			ll chg = a[x].m + sw1.begin()->num - ch.rbegin()->num ;
			if (chg <= 0) continue ;

			sum += chg ; sta[x] = 0 ;

			info y = *sw1.begin() , z = *ch.rbegin() ;
			sta[y.pl] = 1 ; sw1.erase(y) ; ch.insert((info){a[y.pl].p , y.pl}) ;
			sta[z.pl] = -1 ; ch.erase(z) ;
		}
		else if (sta[x] == 1) {
			ll chg = -a[x].p + a[x].m + sw1.begin()->num ;
			if (chg <= 0) continue ;

			ch.erase((info){a[x].p , x}) ;

			sum += chg ; sta[x] = 0 ;
			sw1.insert((info){-a[x].m + a[x].p , x}) ;

			info y = *sw1.begin() ;
			sta[y.pl] = 1 ; ch.insert((info){a[y.pl].p , y.pl}) ; sw1.erase(y) ;
		}
	}

	return sum >= 0 ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i].m) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i].p) , a[i].p = -a[i].p ;
	for (int i = 1 ; i <= n ; ++i) a[i].pl = i ;

	///

	std::sort(a + 1 , a + 1 + n , cmp1) ;
	for (int i = 1 ; i <= n ; ++i) lst1[i] = a[i].pl ;
	std::sort(a + 1 , a + 1 + n , cmp2) ;
	for (int i = 1 ; i <= n ; ++i) lst2[i] = a[i].pl ;
	std::sort(a + 1 , a + 1 + n , cmp3) ;

	int L = 0 , R = n + 1 ;
	for (; L + 1 < R ;) {
		int mid = (L + R) >> 1 ;
		if (check(mid)) L = mid ;
		else R = mid ;
	}

	printf("%d\n" , L) ;

	return 0 ;
}