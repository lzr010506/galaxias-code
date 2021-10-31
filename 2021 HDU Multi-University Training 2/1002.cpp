#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N << 1] ;
struct data {
	ll s[3] ;

	void init(ll x) {
		s[0] = 1 ; s[1] = x ; s[2] = x * x ;
	}
	ll trans(int x) {
		return s[0] * x * x + (x << 1) * s[1] + s[2] ;
	}
	friend data operator +(data a , data b) {
		data tmp ;
		for (int i = 0 ; i < 3 ; ++i) tmp.s[i] = a.s[i] + b.s[i] ;
		return tmp ;
	}
	friend data operator *(data a , int b) {
		for (int i = 0 ; i < 3 ; ++i) a.s[i] *= b ;
		return a ;
	}
}tre[MAX_N << 2] ;

Link *head[MAX_N] ;
int n , q , cur , ti , siz[MAX_N] , fa[MAX_N] , lfa[MAX_N] , dfn[MAX_N] , dep[MAX_N] ;

void add(int t , int x , int y , int fx , int fy , data num) {
	if (y < fx || fy < x) return ;
	if (fx <= x && y <= fy) {
		tre[t] = tre[t] + num ;
		return ;
	}

	int mid = (x + y) >> 1 ;
	add(t << 1 , x , mid , fx , fy , num) ; add(t << 1 | 1 , mid + 1 , y , fx , fy , num) ;
}

data calc(int t , int x , int y , int f) {
	if (x == y) return tre[t] ;

	int mid = (x + y) >> 1 ;
	if (f <= mid) return tre[t] + calc(t << 1 , x , mid , f) ;
	else return tre[t] + calc(t << 1 | 1 , mid + 1 , y , f) ;
}

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dfs(int x , int f) {
	siz[x] = 1 ; fa[x] = f ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == f) continue ;

		dep[nx] = dep[x] + 1 ;
		dfs(nx , x) ; siz[x] += siz[nx] ;
	}
}

void dlink(int x , int f) {
	dfn[x] = ++ti ; lfa[x] = f ;

	int hson = -1 , msiz = -1 ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa[x]) continue ;

		if (msiz < siz[nx]) {msiz = siz[nx] ; hson = nx ;}
	}

	if (hson != -1) dlink(hson , f) ;
	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa[x] || nx == hson) continue ;

		dlink(nx , nx) ;
	}
}

int lca(int x , int y) {
	for (; lfa[x] != lfa[y] ;) {
		if (dep[lfa[x]] > dep[lfa[y]]) std::swap(x , y) ;
		y = fa[lfa[y]] ;
	}

	if (dep[x] > dep[y]) return y ;
	else return x ;
}

void modify(int x , int d , int h , int ty) {
	data num ;
	num.init(h) ; num = num * ty ;

	for (; lfa[x] != lfa[d] ;) {
		add(1 , 1 , n , dfn[lfa[x]] , dfn[x] , num) ;
		x = fa[lfa[x]] ;
	}
	add(1 , 1 , n , dfn[d] , dfn[x] , num) ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i < n ; ++i) {
		int x , y ; scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ;
	}

	///

	dep[1] = 1 ;
	dfs(1 , 1) ; dlink(1 , 1) ;

	///

	scanf("%d" , &q) ;
	for (; q-- ;) {
		int op , x , y ;
		scanf("%d %d" , &op , &x) ;

		if (op == 1) {
			scanf("%d" , &y) ;
			int d = lca(x , y) ;

			modify(x , d , - dep[x] - 1 , 1) ;
			modify(y , d , - dep[d] + dep[x] - dep[d] + 1 , 1) ;
			modify(d , d , - dep[d] + dep[x] - dep[d] + 1 , -1) ;
		}
		else printf("%lld\n" , calc(1 , 1 , n , dfn[x]).trans(dep[x])) ;
	}

	return 0 ;
}