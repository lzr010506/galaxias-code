#include <bits/stdc++.h>

const int MAX_N = 100 + 10 , INF = 0x3f3f3f3f ;

int n , p ;
char s[MAX_N] ;

int main() {
	scanf("%d" , &n) ;

	int res = INF , pl = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		scanf("%d %s" , &p , s) ;

		int len = strlen(s) , ze = 0 , on = 0 , tw = 0 ;
		for (int j = 0 ; j < len ; ++j)
			if (s[j] == '0') ++ze ;
			else if (s[j] == '1') ++on ;
			else if (s[j] == '2') ++tw ;

		if (ze >= 1 && on >= 1 && tw >= 2)
			if (res > p) res = p , pl = i ;
	}

	printf("%d\n" , pl) ;

	return 0 ;
}