#include <bits/stdc++.h>

const int N = 1e5 , MAX_N = 1e5 + 10 ;

struct Link {
	int num ;
	Link *next ;
}list[MAX_N] ;

std::queue<int> que ;
std::vector<int> pt[MAX_N] ;

Link *head[MAX_N] ;
int n , m , cur , lk[MAX_N] , f[MAX_N] ;

void ins(int x , int y) {
	list[cur].num = y ;
	list[cur].next = head[x] ;
	head[x] = &list[cur++] ;

	++lk[y] ;
}

int main() {
	scanf("%d" , &n) ;
	for (int i = 1 ; i <= n ; ++i) {
		scanf("%d" , &m) ;
		for (int j = 0 ; j < m ; ++j) {
			int x ; scanf("%d" , &x) ;
			pt[x].push_back(i) ;
		}
	}

	for (int i = 1 ; i <= N ; ++i) {
		int s = pt[i].size() ;
		for (int j = 0 ; j < s - 1 ; ++j) {
			int x = pt[i][j] , y = pt[i][j + 1] ;
			ins(x , y) ;
		}
	}

	///

	for (int i = 1 ; i <= n ; ++i)
		if (!lk[i]) {que.push(i) ; f[i] = 1 ;}

	int res = 1 ;
	for (; !que.empty() ;) {
		int x = que.front() ; que.pop() ;
		for (Link *h = head[x] ; h ; h = h->next) {
			int nx = h->num ; --lk[nx] ;

			f[nx] = std::max(f[nx] , f[x] + 1) ;
			res = std::max(res , f[nx]) ;
			if (!lk[nx]) que.push(nx) ;
		}
	}

	printf("%d\n" , res) ;

	return 0 ;
}