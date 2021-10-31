#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 ;

struct data {
	int c , p ;
}a[MAX_N] ;

std::vector<data> lst ;

ll tot ;
int n , S , cnt , sump[MAX_N] ;

bool cmp(data a , data b) {return a.p > b.p ;}

inline int cal(int x) {return lst[x].c + lst[x].p * x + sump[x + 1] ;}

int main() {
	scanf("%d %d" , &n , &S) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i].c) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i].p) ;
	std::sort(a + 1 , a + 1 + n , cmp) ;

	///

	for (int i = 1 ; i <= n ; ++i) {
		int siz = lst.size() ;
		ll ad = a[i].c + (ll)a[i].p * siz ;

		if (tot + ad <= S) {
			lst.push_back(a[i]) ;
			tot += ad ;
		}
		else if (siz) {
			ad -= a[i].p ; sump[siz] = 0 ;
			for (int j = siz - 1 ; j >= 0 ; --j) sump[j] = sump[j + 1] + lst[j].p ;

			///

			int mp = 0 , mval = cal(0) ;
			for (int j = 1 ; j < siz ; ++j) {
				int tmp = cal(j) ;
				if (mval < tmp) mval = tmp , mp = j ; 
			}

			if (ad < mval) {
				tot += ad - mval ;
				lst.erase(lst.begin() + mp) ; lst.push_back(a[i]) ;
			}
		}
	}

	printf("%lu\n" , lst.size()) ;

	return 0 ;
}