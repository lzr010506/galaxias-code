#include <bits/stdc++.h>

const int MAX_N = 2e5 + 10 , lgN = 30 + 5 ;

struct data {
	int x , y ;
}a[MAX_N] ;
struct Node {
	int num ;
	Node *ch[2] ;

	void init() {num = 0 ; ch[0] = ch[1] = NULL ;}
}tre[MAX_N * lgN] ;

Node *root[MAX_N] ;
int n , q , tot , L , R , v[MAX_N] , lef[MAX_N] , rig[MAX_N] , ch[MAX_N][2] ;

///

bool cmp(data a , data b) {return a.x < b.x ;}

void dfs(int x) {
	if (!x) return ;

	int l = ch[x][0] , r = ch[x][1] ;
	dfs(l) ; dfs(r) ;

	a[x].x = v[x] ; a[x].y = v[x] ;
	if (l) a[x].x = std::min(a[x].x , a[l].x) , a[x].y = std::max(a[x].y , a[l].y) ;
	if (r) a[x].x = std::min(a[x].x , a[r].x) , a[x].y = std::max(a[x].y , a[r].y) ;
}

///

int findpt(int x) {
	int L = 0 , R = n + 1 ;
	for (; L + 1 < R ;) {
		int mid = (L + R) >> 1 ;
		if (a[mid].x < x) L = mid ;
		else R = mid ;
	}

	return L ;
}

void add(Node *ort , Node *&rt , int x , int y , int f) {
	(rt = &tre[tot++])->init() ;
	*rt = *ort ; ++rt->num ;
	
	if (x == y) return ;

	int mid = (x + y) >> 1 ;
	if (f <= mid) add(ort->ch[0] , rt->ch[0] , x , mid , f) ;
	else add(ort->ch[1] , rt->ch[1] , mid + 1 , y , f) ;
}

int calc(Node *r1 , Node *r2 , int x , int y , int fx , int fy) {
	if (r1->num == r2->num) return 0 ;
	if (y < fx || fy < x) return 0 ;
	if (fx <= x && y <= fy) return r1->num - r2->num ;

	int mid = (x + y) >> 1 ;
	return calc(r1->ch[0] , r2->ch[0] , x , mid , fx , fy) + calc(r1->ch[1] , r2->ch[1] , mid + 1 , y , fx , fy) ;
}

///

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) scanf("%d %d %d" , &ch[i][0] , &ch[i][1] , &v[i]) ;

	///

	dfs(1) ; L = a[1].x ; R = a[1].y ;
	std::sort(a + 1 , a + 1 + n , cmp) ;

	(root[0] = &tre[tot++])->init() ;
	root[0]->ch[0] = root[0]->ch[1] = root[0] ;

	for (int i = 1 ; i <= n ; ++i) add(root[i - 1] , root[i] , L , R , a[i].y) ;

	///

	scanf("%d" , &q) ;
	for (; q-- ;) {
		int x , y ; scanf("%d %d" , &x , &y) ;

		///

		int pl = findpt(x) , pr = findpt(y + 1) , res = calc(root[pr] , root[pl] , L , R , x , y) ;
		if (L < x) res += calc(root[pl] , root[0] , L , R , L , x - 1) ;
		if (y < R) res += calc(root[n] , root[pr] , L , R , y + 1 , R) ;

		printf("%d\n" , ((n - res) << 1) + 1) ;
	}

	return 0 ;
}