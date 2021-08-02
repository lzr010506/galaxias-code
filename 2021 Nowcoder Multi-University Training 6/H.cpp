#include <bits/stdc++.h>

const int MAX_N = 1e5 + 10 ;

struct data {int l , r ;} ;
struct operate {int yl , yr , num ;} ;
struct Node {
	Node *ch[2] ;
	int cnt , sum ;
}tre[MAX_N << 2] ;

std::vector<data> p1 , p2 ;
std::vector<operate> op[MAX_N] ;

int n , d ;

void update(int t , int x , int y , int fx , int fy , int a) {
	if (y < fx || fy < x) return ;
	if (fx <= x && y <= fy) {
		tre[t].cnt += a ;

		if (tre[t].cnt > 0) tre[t].sum = y - x + 1 ;
		else {
			if (x == y) tre[t].sum = 0 ;
			else tre[t].sum = tre[t << 1].sum + tre[t << 1 | 1].sum ;
		}

		return ;
	}

	int mid = (x + y) >> 1 ;
	update(t << 1 , x , mid , fx , fy , a) ;
	update(t << 1 | 1 , mid + 1 , y , fx , fy , a) ;

	if (!tre[t].cnt) tre[t].sum = tre[t << 1].sum + tre[t << 1 | 1].sum ;
}

int find(int t , int x , int y) {
	if (tre[t].sum == y - x + 1) return -1 ;
	if (x == y) return x ;

	int mid = (x + y) >> 1 , tmp = find(t << 1 , x , mid) ;
	if (tmp == -1) return find(t << 1 | 1 , mid + 1 , y) ;
	else return tmp ;
}

void trans(std::vector<data> &p , int x , int y) {
	if (y - x + 1 >= d) p.push_back((data){0 , d - 1}) ;
	else {
		x %= d ; y %= d ;
		(x += d) %= d ; (y += d) %= d ;

		if (x <= y) p.push_back((data){x , y}) ;
		else {p.push_back((data){0 , y}) ; p.push_back((data){x , d - 1}) ;}
	}
}

int main() {
	scanf("%d %d" , &n , &d) ;
	for (int i = 0 ; i < n ; ++i) {
		int x1 , y1 , x2 , y2 ;
		scanf("%d %d %d %d" , &x1 , &y1 , &x2 , &y2) ;
		--x2 ; --y2 ;

		p1.clear() ; p2.clear() ;
		trans(p1 , x1 , x2) ; trans(p2 , y1 , y2) ;

		///

		int s1 = p1.size() , s2 = p2.size() ;
		for (int p = 0 ; p < s1 ; ++p)
			for (int q = 0 ; q < s2 ; ++q) {
				int xl = p1[p].l , yl = p2[q].l , xr = p1[p].r , yr = p2[q].r ;

				op[xl].push_back((operate){yl , yr , 1}) ;
				op[xr + 1].push_back((operate){yl , yr , -1}) ;
			}
	}

	///

	int x = -1 , y = -1 ;
	for (int i = 0 ; i < d ; ++i) {
		int siz = op[i].size() ;
		for (int j = 0 ; j < siz ; ++j) {
			int yl = op[i][j].yl , yr = op[i][j].yr , a = op[i][j].num ;
			update(1 , 0 , d - 1 , yl , yr , a) ;
		}

		if (tre[1].sum < d) {
			x = i ; y = find(1 , 0 , d - 1) ;
			break ;
		}
	}

	if (x != -1) printf("YES\n%d %d\n" , x , y) ;
	else printf("NO\n") ;

	return 0 ;
}