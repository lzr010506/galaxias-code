#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 600 + 10 , mod = 998244353 ;

int T , n , m , A[MAX_N][MAX_N] , B[MAX_N][MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;

    return s ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ; m = n << 1 ;
        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= m ; ++j) A[i][j] = B[i][j] = 0 ;

        for (int i = 1 ; i <= n ; ++i) {
            for (int j = 1 ; j <= n ; ++j) scanf("%d" , &A[i][j]) ;

            int s = 0 ;
            for (int j = 1 ; j <= n ; ++j) s += A[i][j] ;

            s = qpow(s , mod - 2) ;
            for (int j = 1 ; j <= n ; ++j) A[i][j] = (ll)A[i][j] * s % mod ;

            ///

            B[i][i] = A[i][i] ; A[i][i] = 1 ;
            for (int j = 1 ; j <= n ; ++j)
                if (i != j) A[i][j] = (mod - A[i][j]) % mod ;
        }

        ///

        for (int i = 1 ; i <= n ; ++i) A[i][i + n] = 1 ;
        for (int i = 1 ; i <= n ; ++i) {
            if (!A[i][i]) {
                int j ;
                for (j = i + 1 ; j <= n ; ++j) if (A[i][j]) break ;
                for (int k = 1 ; k <= m ; ++k) std::swap(A[i][k] , A[j][k]) ;
            }

            int ny = qpow(A[i][i] , mod - 2) ;
            for (int j = i + 1 ; j <= n ; ++j) {
                int xs = (ll)A[j][i] * ny % mod ;

                for (int k = i ; k <= m ; ++k) {
                    int tmp = (ll)A[i][k] * xs % mod ;
                    A[j][k] = (A[j][k] - tmp + mod) % mod ;
                }
            }
        }

        for (int i = n ; i ; --i) {
            int xs = qpow(A[i][i] , mod - 2) ;
            for (int j = i ; j <= m ; ++j) A[i][j] = (ll)A[i][j] * xs % mod ;

            for (int j = i - 1 ; j ; --j) {
                int rd = A[j][i] ;
                for (int k = i ; k <= m ; ++k) {
                    int tmp = (ll)A[i][k] * rd % mod ;
                    A[j][k] = (A[j][k] - tmp + mod) % mod ;
                }
            }
        }

        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j) A[i][j] = A[i][j + n] ;

        ///

        for (int i = 1 ; i <= n ; ++i)
            for (int j = 1 ; j <= n ; ++j) {
                int r = 0 ;
                for (int k = 1 ; k <= n ; ++k) {
                    int tmp = (ll)A[i][k] * B[k][j] % mod ;
                    (r += tmp) %= mod ;
                }

                printf("%d" , r) ;
                if (j < n) printf(" ") ;
                else printf("\n") ;
            }
    }

    return 0 ;
}