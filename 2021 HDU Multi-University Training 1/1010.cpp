#include <bits/stdc++.h>

const int BK = 317 , MAX_N = 1e5 + 10 ;

struct data {
	int x , y , fx , fy , ibk , pl ;
}qry[MAX_N] ;

int T , n , m , ma , a[MAX_N] , ans[MAX_N] ;
int nL , nR , ara[MAX_N] , L[MAX_N] , R[MAX_N] , cnt[MAX_N] , res[MAX_N] ;

inline int read() {
	char c = getchar() ;
	int num = 0 , f = 1 ;
	
	for (; c < '0' || c > '9' ; c = getchar()) if (c == '-') f = -f ;
	for (; c >= '0' && c <= '9' ; c = getchar()) num = num * 10 - '0' + c ;

	return num * f ;
}

bool cmp(data a , data b) {return a.ibk < b.ibk || (a.ibk == b.ibk && a.y < b.y) ;}

inline void add(int x) {
	int num = a[x] , b = ara[num] ;

	if (!cnt[num]) ++res[b] ;
	++cnt[num] ;
}

inline void dec(int x) {
	int num = a[x] , b = ara[num] ;

	--cnt[num] ;
	if (!cnt[num]) --res[b] ;
}

inline void move(int x , int y) {
	for (; nR < y ;) add(++nR) ;
	for (; x < nL ;) add(--nL) ;
	for (; nL < x ;) dec(nL++) ;
	for (; y < nR ;) dec(nR--) ;
}

inline int cal(int x , int y) {
	int sum = 0 ;
	for (int i = x ; i <= y ; ++i) if (cnt[i]) ++sum ;

	return sum ;
}

inline int query(int x , int y) {
	int bx = ara[x] , by = ara[y] ;
	if (bx == by) return cal(x , y) ;

	int ans = 0 ;
	for (int i = bx + 1 ; i < by ; ++i) ans += res[i] ;
	return ans + cal(x , R[bx]) + cal(L[by] , y) ;
}

int main() {
	T = read() ;
	for (; T-- ;) {
		ma = 0 ;

		n = read() ; m = read() ;
		for (int i = 1 ; i <= n ; ++i)
			{a[i] = read() ; ma = std::max(ma , a[i]) ;}
		for (int i = 0 ; i <= ma ; ++i) {
			int ibk = i / BK ;
			ara[i] = ibk ; R[ibk] = i ;
			if (!L[ibk]) L[ibk] = i ;
		}

		///

		for (int i = 0 ; i < m ; ++i) {
			qry[i].x = read() ; qry[i].fx = read() ; qry[i].y = read() ; qry[i].fy = read() ;
			qry[i].pl = i ; qry[i].ibk = qry[i].x / BK ;
		}

		std::sort(qry + 0 , qry + m , cmp) ;

		nL = 1 ; nR = 0 ;
		for (int i = 0 ; i < m ; ++i) {
			data *p = &qry[i] ;
			move(p->x , p->y) ; ans[p->pl] = query(p->fx , p->fy) ;
		}

		for (int i = 0 ; i < m ; ++i) printf("%d\n" , ans[i]) ;

		move(1 , 0) ;
	}

	return 0 ;
}