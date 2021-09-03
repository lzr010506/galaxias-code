#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 , lgN = 30 + 5 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N << 1] ;
struct Node {
	int num ;
	Node *ch[2] ;

	void init() {num = 0 ; ch[0] = ch[1] = NULL ;}
}tre[MAX_N * lgN] ;

Link *head[MAX_N] ;
Node *root[MAX_N] ;
int n , q , cur , tot , ti , mt , mjmp , t[MAX_N] ;
int xl[MAX_N] , siz[MAX_N] , L[MAX_N] , R[MAX_N] , f[MAX_N][lgN] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;
}

void dfs(int x , int fa) {
	f[x][0] = fa ; siz[x] = 1 ;
	L[x] = ++ti ; xl[ti] = t[x] ;

	for (Link *h = head[x] ; h ; h = h->next) {
		int nx = h->num ;
		if (nx == fa) continue ;

		dfs(nx , x) ; siz[x] += siz[nx] ;
	}
	R[x] = ti ;
}

void add(Node *r1 , Node *&r2 , int x , int y , int f) {
	(r2 = &tre[tot++])->init() ;
	*r2 = *r1 ; ++r2->num ;

	if (x == y) return ;

	int mid = (x + y) >> 1 ;
	if (f <= mid) add(r1->ch[0] , r2->ch[0] , x , mid , f) ;
	else add(r1->ch[1] , r2->ch[1] , mid + 1 , y , f) ;
}

int query(Node *r1 , Node *r2 , int x , int y , int fx , int fy) {
	if (y < fx || fy < x) return 0 ;
	if (fx <= x && y <= fy) return r2->num - r1->num ;

	int mid = (x + y) >> 1 ;
	return query(r1->ch[0] , r2->ch[0] , x , mid , fx , fy) + query(r1->ch[1] , r2->ch[1] , mid + 1 , y , fx , fy) ;
}

void jump(int &r , int tmp) {
	for (int i = mjmp ; i >= 0 ; --i) {
		int x = f[r][i] ;
		if (t[x] <= tmp) r = x ;
	}
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i < n ; ++i) {
		int x , y ; scanf("%d %d" , &x , &y) ;
		ins(x , y) ; ins(y , x) ;
	}
	for (int i = 1 ; i <= n ; ++i) scanf("%d" , &t[i]) , mt = std::max(mt , t[i]) ;

	///

	dfs(1 , 1) ;
	for (int j = 1 ; (1 << j) <= n ; ++j) {
		mjmp = j ;
		for (int i = 1 ; i <= n ; ++i) f[i][j] = f[f[i][j - 1]][j - 1] ;
	}

	(root[0] = &tre[tot++])->init() ; root[0]->ch[0] = root[0]->ch[1] = root[0] ;
	for (int i = 1 ; i <= n ; ++i) add(root[i - 1] , root[i] , 1 , mt , xl[i]) ;

	///

	scanf("%d" , &q) ;
	for (; q-- ;) {
		int rt , l , r ;
		scanf("%d %d %d" , &rt , &l , &r) ;
		if (t[rt] < l || t[rt] > r) {printf("0\n") ; continue ;}

		jump(rt , r) ;
		if (l == 1) printf("%d\n" , siz[rt]) ;
		else printf("%d\n" , siz[rt] - query(root[L[rt] - 1] , root[R[rt]] , 1 , mt , 1 , l - 1)) ;
	}

	return 0 ;
}