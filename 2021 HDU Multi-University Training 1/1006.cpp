#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

const int L = 30 , MAX_N = 1e5 + 10 , lgN = L + 5 , INF = 0x3f3f3f3f ;

struct Node {
	int pl ;
	Node *ch[2] ;

	void init() {
		pl = 0 ;
		ch[0] = ch[1] = NULL ;
	}
}tre[MAX_N * lgN] ;

Node *root ;
int T , n , k , tot , a[MAX_N] , s[MAX_N] ;

void add(Node *&rt , int num , int p , int a) {
	if (!rt) (rt = &tre[tot++])->init() ;
	rt->pl = a ;

	if (p < 0) return ;

	int d = num & (1 << p) ? 1 : 0 ;
	add(rt->ch[d] , num , p - 1 , a) ;
}

int getans(Node *rt , int num , int p) {
	if (!rt) return -INF ;
	if (p < 0) return rt->pl ;
	int a = num & (1 << p) ? 1 : 0 , ned = k & (1 << p) ? 1 : 0 ;

	if (ned == 1) return getans(rt->ch[a ^ 1] , num , p - 1) ;
	else {
		int r1 = rt->ch[a ^ 1] ? rt->ch[a ^ 1]->pl : -INF ;
		return std::max(getans(rt->ch[a] , num , p - 1) , r1) ;
	}
}

int main() {
	scanf("%d" , &T) ;
	for (; T-- ;) {
		root = NULL ; tot = 0 ;

		scanf("%d %d" , &n , &k) ;
		for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

		if (!k) {printf("1 1\n") ; continue ;}

		///

		s[0] = 0 ; add(root , s[0] , L , 0) ;
		for (int i = 1 ; i <= n ; ++i) s[i] = s[i - 1] ^ a[i] ;

		int len = INF , pl = -1 ;
		for (int i = 1 ; i <= n ; ++i) {
			int lef = getans(root , s[i] , L) ;
			int nl = i - lef ;
			if (nl < len) len = nl , pl = i ;

			add(root , s[i] , L , i) ;
		}

		if (pl != -1) printf("%d %d\n" , pl - len + 1 , pl) ;
		else printf("-1\n") ;
	}

	return 0 ;
}