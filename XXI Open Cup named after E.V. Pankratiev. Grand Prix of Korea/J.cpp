#include <map>
#include <set>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define pir std::pair<int , int>
#define mp(x , y) std::make_pair(x , y)
#define DEBUG printf("Passing [%s] in Line %d\n" , __FUNCTION__ , __LINE__) ;

const int MAX_N = 3e5 + 10 , dx[4] = {-1 , 1 , 0 , 0} , dy[4] = {0 , 0 , 1 , -1} ;

char s[MAX_N] ;
pir ans[MAX_N] ;
int n , m , a[MAX_N] ;
std::map<pir , std::set<int> > mp ;

int trans(char c) {
	if (c == 'L') return 0 ;
	else if (c == 'R') return 1 ;
	else if (c == 'U') return 2 ;
	else return 3 ;
}

inline pir work(pir a , int ty) {
	return mp(a.first + dx[ty] , a.second + dy[ty]) ;
}

void merge(pir a , pir b) {
	if (mp[b].size() > mp[a].size()) mp[a].swap(mp[b]) ;
	for (std::set<int>::iterator p = mp[b].begin() ; p != mp[b].end() ; ++p) mp[a].insert(*p) ;
	mp[b].clear() ;
}

int main() {
	scanf("%d%s" , &n , s) ;
	for (int i = 0 ; i < n ; ++i) a[i] = trans(s[i]) ^ 1 ;

	scanf("%d" , &m) ;
	for (int i = 0 ; i < m ; ++i) {
		int x , y ;
		scanf("%d %d" , &x , &y) ;
		mp[mp(x , y)].insert(i) ;
	}

	///

	pir nw = mp(0 , 0) ;
	for (int i = 0 ; i < n ; ++i) {
		pir np = work(nw , a[i]) , nnp = work(np , a[i]) ;

		if (mp.count(np) && !mp[np].empty()) merge(nnp , np) ;
		nw = np ;
	}

	for (std::map<pir , std::set<int> >::iterator p = mp.begin() ; p != mp.end() ; ++p)
		for (std::set<int>::iterator q = p->second.begin() ; q != p->second.end() ; ++q)
			ans[*q] = mp(p->first.first - nw.first , p->first.second - nw.second) ;

	for (int i = 0 ; i < m ; ++i) printf("%d %d\n" , ans[i].first , ans[i].second) ;

	return 0 ;
}