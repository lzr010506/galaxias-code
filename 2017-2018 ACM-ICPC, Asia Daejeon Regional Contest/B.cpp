#include <bits/stdc++.h>

const int S = 5e7 + 10 , MAX_N = 16 + 10 , dx[8] = {-1 , -1 , -1 , 1 , 1 , 1 , 0 , 0} , dy[8] = {-1 , 0 , 1 , -1 , 0 , 1 , -1 , 1} ;

bool ap[S] ;
int x , a , b , ans , mp[MAX_N][MAX_N] , dep[MAX_N] , pw[MAX_N] ;

bool check() {
	for (int i = 1 ; i <= 4 ; ++i)
		for (int j = 1 ; j <= 4 ; ++j) {
			if (!mp[i][j]) continue ;
			for (int k = 0 ; k < 8 ; ++k) {
				int x = i , y = j ;

				bool ok = 1 ;
				for (int t = 0 ; t < 2 ; ++t) {
					int nx = x + dx[k] , ny = y + dy[k] ;
					if (nx < 1 || nx > 4 || ny < 1 || ny > 4) {ok = 0 ; break ;}
					if (mp[x][y] != mp[nx][ny]) {ok = 0 ; break ;}

					x = nx ; y = ny ;
				}

				if (ok) return 1 ;
			}
		}

	return 0 ;
}

int trans(int x , int y) {
	--x ; --y ; y += 4 * x ;

	return pw[y] ;
}

void work(int x , int y , int nw , int hash) {
	if (ap[hash]) return ;
	if (check()) {
		if (x == a && y == b && nw == 2) ++ans ;
		return ;
	}

	ap[hash] = 1 ; nw = 3 - nw ;
	for (int j = 1 ; j <= 4 ; ++j) {
		if (dep[j] == 4) continue ;

		int i = ++dep[j] ;
		mp[i][j] = nw ;

		work(i , j , nw , hash + trans(i , j) * nw) ;

		mp[i][j] = 0 ;
		--dep[j] ;
	}
}

int main() {
	scanf("%d %d %d" , &x , &a , &b) ;
	mp[1][x] = 1 ; ++dep[x] ;

	pw[0] = 1 ;
	for (int i = 1 ; i <= 16 ; ++i) pw[i] = pw[i - 1] * 3 ;

	work(1 , x , 1 , trans(1 , x) * 1) ;

	printf("%d\n" , ans) ;

	return 0 ;
}