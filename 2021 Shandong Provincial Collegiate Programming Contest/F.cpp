#include <bits/stdc++.h>
using namespace std ;

#define ll long long

const int L = 4e5 , MAX_N = 4e5 + 10 , base = 27 , mod1 = 1e9 + 7 , mod2 = 1e9 + 9 ;

struct data {
	int x , y ;

	friend data operator *(data a , int x) {return (data){int((ll)a.x * x % mod1) , int((ll)a.y * x % mod2)} ;}
	friend data operator +(data a , int x) {return (data){(a.x + x) % mod1 , (a.y + x) % mod2} ;}

	friend data operator +(data a , data b) {return (data){(a.x + b.x) % mod1 , (a.y + b.y) % mod2} ;}
	friend data operator *(data a , data b) {return (data){int((ll)a.x * b.x % mod1) , int((ll)a.y * b.y % mod2)} ;}
	friend data operator -(data a , data b) {return (data){(a.x - b.x + mod1) % mod1 , (a.y - b.y + mod2) % mod2} ;}

	friend bool operator <(data a , data b) {return a.x < b.x || (a.x == b.x && a.y < b.y) ;}
	friend bool operator >(data a , data b) {return a.x > b.x || (a.x == b.x && a.y > b.y) ;}
	friend bool operator ==(data a , data b) {return a.x == b.x && a.y == b.y ;}
	friend bool operator !=(data a , data b) {return !(a == b) ;}
} ;

std::map<data , int> cnt ;
std::vector<data> h[MAX_N] ;

int n ;
data pw[MAX_N] ;
string s[MAX_N] ;

void gethash(int x) {
	int len = s[x].size() ;
	data nw = (data){0 , 0} ;

	for (int i = 0 ; i < len ; ++i) {
		nw = nw * base ; nw = nw + (s[x][i] - 'a' + 1) ;
		h[x].push_back(nw) ;
	}
	++cnt[nw] ;
}

void cal(int x , ll &p1 , ll &p2) {
	int len = s[x].size() ;
	data tot = h[x][len - 1] ; p2 += (cnt[tot] - 1) ;

	for (int i = 1 ; i < len ; ++i) {
		int lef = len - i ;
		data fr = h[x][lef - 1] , bh = tot - h[x][i - 1] * pw[lef] ;

		if (fr != bh || i <= lef) continue ;

		data fd1 = h[x][i - 1] - h[x][lef - 1] * pw[i - lef] ,
			 fd2 = h[x][len - lef - 1] - h[x][lef - 1] * pw[i - lef] ;
		if (fd1 != fd2) p1 += cnt[fd1] + cnt[fd2] ;
		else p1 += cnt[fd1] ;
	}
}

int main() {
	pw[0] = (data){1 , 1} ;
	for (int i = 1 ; i <= L ; ++i) pw[i] = pw[i - 1] * base ;

	cin >> n ;
	for (int i = 0 ; i < n ; ++i) cin >> s[i] ;

	///

	for (int i = 0 ; i < n ; ++i) gethash(i) ;

	ll p1 = 0 , p2 = 0 ;
	for (int i = 0 ; i < n ; ++i) {
		cal(i , p1 , p2) ;
		// printf("%d (%lld , %lld)\n" , i , p1 , p2) ;
	}

	// printf("%lld %lld\n" , p1 , p2) ;

	p2 >>= 1 ;
	printf("%lld\n" , p1 + p2) ;

	return 0 ;
}
