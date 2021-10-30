#include <bits/stdc++.h>

#define ll long long

const ll INF = 1e15 ;
const int MAX_N = 2e5 + 10 ;

struct Edge {
	int x , y , w ;
}eg[MAX_N] ;

ll s[MAX_N] , f[MAX_N] ;
int n , m , tot , cur , a[MAX_N] , fa[MAX_N] , ch[MAX_N][2] ;

int findset(int x) {return fa[x] == -1 ? x : (fa[x] = findset(fa[x])) ;}

bool cmp1(Edge a , Edge b) {
	return a.w > b.w ;
}

void calc(int x) {
	s[x] = 0 ;
	if (x <= n) s[x] = a[x] ;
	else {
		calc(ch[x][0]) ; calc(ch[x][1]) ;
		s[x] = s[ch[x][0]] + s[ch[x][1]] ;
	}
}

void dp(int x) {
	if (x <= n) {f[x] = INF ; return ;}

	int l = ch[x][0] , r = ch[x][1] ;
	dp(l) ; dp(r) ;

	if (f[l] == -1 || f[r] == -1) f[x] = -1 ;
	else {
		//left to right
		ll st1 = std::min(std::min(f[l] , f[r] - s[l]) , a[x] - s[l]) ;
		if (st1 <= 0) st1 = -1 ;

		//right to left
		ll st2 = std::min(std::min(f[r] , f[l] - s[r]) , a[x] - s[r]) ;
		if (st2 <= 0) st2 = -1 ;

		f[x] = std::max(st1 , st2) ;
	}
}

int main() {
	scanf("%d %d" , &n , &m) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
	for (int i = 1 ; i <= m ; ++i)
		scanf("%d %d %d" , &eg[i].x , &eg[i].y , &eg[i].w) ;

	///

	std::sort(eg + 1 , eg + 1 + m , cmp1) ;
	for (int i = 1 ; i <= (n << 1) ; ++i) fa[i] = -1 ;

	tot = n ;
	for (int i = 1 ; i <= m ; ++i) {
		int x = eg[i].x , y = eg[i].y ;
		x = findset(x) ; y = findset(y) ;

		if (x == y) continue ;

		int nw = ++tot ; fa[x] = fa[y] = nw ;
		ch[nw][0] = x ; ch[nw][1] = y ; a[nw] = eg[i].w ;
	}

	calc(tot) ; dp(tot) ;
	printf("%lld\n" , f[tot]) ;	

	return 0 ;
}