#include <bits/stdc++.h>

const int MAX_N = 2e6 + 10 ;

std::vector<int> vt[MAX_N] ;
std::vector<int> lk[MAX_N] ;

char s[MAX_N] ;
int n , ed , fa[MAX_N] , pre[MAX_N] , nxt[MAX_N] , cnt[MAX_N] , ans[MAX_N] , lst[MAX_N] , tmp[MAX_N] ;

void del(int x) {
	int l = pre[x] , r = nxt[x] ;
	nxt[l] = nxt[x] ; pre[r] = pre[x] ;

	if (x == ed) ed = l ;
}

void update(int x) {
	int num = vt[x].back() , l = x - 1 ;
	vt[x].pop_back() ; vt[l].push_back(num) ;

	if (pre[x] != l) {
		pre[l] = pre[x] ; nxt[l] = x ;
		nxt[pre[x]] = l ; pre[x] = l ;
	}

	if (!vt[x].size()) del(x) ;
}

bool cmp(int a , int b) {return lk[a].size() > lk[b].size() ;}

int main() {
	scanf("%d %s" , &n , s) ;
	for (int i = 1 ; i <= n ; ++i) {
		int x ; scanf("%d" , &x) ;
		++cnt[x] ;
	}

	for (int i = 1 ; i <= n ; ++i) {
		if (cnt[i]) vt[cnt[i]].push_back(i) ;
		ed = std::max(ed , cnt[i]) ;
	}

	for (int i = 1 ; i <= n ; ++i) pre[i] = i - 1 , nxt[i] = i + 1 ;
	nxt[ed] = pre[0] = nxt[0] = 0 ;
	for (int i = 1 ; i <= n ; ++i) if (!vt[i].size()) del(i) ;

	///

	int m = strlen(s) , rt = 0 , nw = 0 ;
	for (int i = 0 ; i < m ; ++i)
		if (s[i] == '(') {
			++nw ; fa[nw] = rt ;
			lk[rt].push_back(nw) ; rt = nw ;
		}
		else rt = fa[rt] ;

	///

	for (int i = 0 ; i <= n ; ++i) lst[i] = i ;
	std::sort(lst + 0 , lst + n + 1 , cmp) ;

	for (int p = 0 ; p <= n ; ++p) {
		int i = lst[p] , siz = lk[i].size() , x = ed , y = vt[x].size() - 1 ;

		for (int j = 0 ; j < siz ; ++j) {
			if (!x) {printf("NO\n") ; return 0 ;}

			ans[lk[i][j]] = vt[x][y] ; tmp[j] = x ;

			if (y) --y ;
			else {x = pre[x] ; y = vt[x].size() - 1 ;}
		}

		for (int j = siz - 1 ; j >= 0 ; --j) update(tmp[j]) ;
		for (; !vt[ed].size() ; ed = pre[ed]) ;
	}

	printf("YES\n") ;
	for (int i = 1 ; i <= n ; ++i) printf("%d " , ans[i]) ;
	printf("\n") ;

	return 0 ;
}