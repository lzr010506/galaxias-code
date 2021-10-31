#include <bits/stdc++.h>

#define db double

const int MAX_N = 8e5 + 10 , INF = 0x3f3f3f3f ;

std::vector<int> a , b ;
std::map<int , int> cnt ;
std::map<int , bool> ap ;
std::map<int , std::vector<int> > p1 , p2 ;

int n , nxt[MAX_N] , f[MAX_N] , g[MAX_N] ;

void calc(int l1) {
	if (l1 == 1) {
		int cir = a[0] - b[0] ;
		if (cir < 0) cir += 3600000 ;
		
		++cnt[cir] ;
		return ;
	}

	///

	int l2 = l1 << 1 ;
	--l1 ; --l2 ;

	for (int i = 1 ; i <= l1 ; ++i) f[i] = a[i] - a[i - 1] ;
	for (int i = 1 ; i <= l2 ; ++i) g[i] = b[i] - b[i - 1] ;

	f[l1 + 1] = INF ;

	///

	int p = 0 ; nxt[0] = nxt[1] = 0 ;
	for (int i = 2 ; i <= l1 ; ++i) {
		for (; p && f[p + 1] != f[i] ; p = nxt[p]) ;
		if (f[p + 1] == f[i]) ++p ;

		nxt[i] = p ;
	}

	ap.clear() ;

	p = 0 ;
	for (int i = 1 ; i <= l2 ; ++i) {
		for (; p && f[p + 1] != g[i] ; p = nxt[p]) ;
		if (f[p + 1] == g[i]) ++p ;

		if (p == l1) {
			db cir = a[p] - b[i] ;
			if (cir < 0) cir += 3600000 ;

			if (ap.count(cir)) continue ;
			ap[cir] = 1 ; ++cnt[cir] ;
		}
	}
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 0 ; i < n ; ++i) {
		db x , y ; scanf("%lf %lf" , &x , &y) ;
		p1[round(x * 10000)].push_back(round(y * 10000)) ;
	}
	for (int i = 0 ; i < n ; ++i) {
		db x , y ; scanf("%lf %lf" , &x , &y) ;
		p2[round(x * 10000)].push_back(round(y * 10000)) ;
	}

	///

	for (std::map<int , std::vector<int> > :: iterator p = p1.begin() ; p != p1.end() ; ++p) {
		int idx = p->first ;
		std::sort(p->second.begin() , p->second.end()) ;
		std::sort(p2[idx].begin() , p2[idx].end()) ;

		///

		if (p->second.size() != p2[idx].size()) {printf("Different\n") ; return 0 ;}

		a.clear() ; b.clear() ;
		int siz = p->second.size() ;
		for (int i = 0 ; i < siz ; ++i) a.push_back(p->second[i]) ;
		for (int i = 0 ; i < siz ; ++i) b.push_back(p2[idx][i]) ;
		for (int i = 0 ; i < siz ; ++i) b.push_back(p2[idx][i] + 3600000) ;

		calc(siz) ;
	}

	///

	int ned = p1.size() ;
	for (std::map<int , int> :: iterator p = cnt.begin() ; p != cnt.end() ; ++p)
		if (p->second == ned) {printf("Same\n") ; return 0 ;}
	printf("Different\n") ;

	return 0 ;
}