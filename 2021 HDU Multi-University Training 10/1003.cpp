#include <bits/stdc++.h>

const int N = 700 , M = 244650 , MAX_N = M + 10 ;

std::vector<int> ans ;

int T , n , f[MAX_N] ;

int main() {
    for (int i = 0 ; i <= M ; ++i) f[i] = N + 1 ;

    f[0] = 0 ;
    for (int i = 1 ; i <= M ; ++i)
        for (int j = 2 ; j <= N ; ++j) {
            int tmp = (j * (j - 1)) >> 1 ;
            if (tmp > i) break ;

            f[i] = std::min(f[i - tmp] + j , f[i]) ;
        }

    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        int mres = (n * (n - 1)) >> 1 ;

        ///

        ans.clear() ;
        for (int i = 0 ; i <= mres ; ++i) if (f[mres - i] <= n) ans.push_back(i) ;

        int siz = ans.size() ;
        std::sort(ans.begin() , ans.end()) ;
        for (int i = 0 ; i < siz ; ++i) {
            printf("%d" , ans[i]) ;
            if (i != siz - 1) printf(" ") ;
            else printf("\n") ;
        }
    }

    return 0 ;
}