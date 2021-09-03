#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 4e5 + 10 , lgN = 20 + 5 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N] ;

Link *head[MAX_N] ;
int n , mj , q , cur , dep[MAX_N] , fa[MAX_N][lgN] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dfs(int x , int f) {
	fa[x][0] = f ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == f) continue ;

		dep[nx] = dep[x] + 1 ; dfs(nx , x) ;
	}
}

int getlca(int x , int y) {
	if (dep[x] > dep[y]) std::swap(x , y) ;

	for (int i = mj ; i >= 0 ; --i) {
		int fy = fa[y][i] ;
		if (dep[x] > dep[fy]) continue ;

		y = fy ;
	}

	if (x == y) return x ;

	for (int i = mj ; i >= 0 ; --i) {
		int fx = fa[x][i] , fy = fa[y][i] ;
		if (fx != fy) {x = fx ; y = fy ;}
	}

	return fa[x][0] ;
}

int main() {
	scanf("%d %d" , &n , &q) ;
	for (int i = 1 ; i < n ; ++i) {
		int x , y ; scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ;
	}

	///

	dep[1] = 1 ; dfs(1 , 1) ;
	for (mj = 1 ; (1 << mj) <= n ; ++mj)
		for (int i = 1 ; i <= n ; ++i) fa[i][mj] = fa[fa[i][mj - 1]][mj - 1] ;
	--mj ;

	for (; q-- ;) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;

		int d = getlca(x , y) ;
		ll l = dep[x] + dep[y] - (dep[d] << 1) - 1 , res = n + 1 + l + ((l * (l + 1)) >> 1) ;

		printf("%lld\n" , res) ;
	}

	return 0 ;
}