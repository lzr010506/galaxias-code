#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 3e5 + 10 , mod = 998244353 ;

struct data {
    int mi[2] , ma[2] ;
}t[MAX_N] ;

int T , n , a[MAX_N] , b[MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;
        for (int i = 0 ; i < n ; ++i) scanf("%d" , &b[i]) ;

        for (int i = 0 ; i < n ; ++i) {
            t[i].mi[0] = t[i].ma[0] = a[i] ;
            t[i].mi[1] = t[i].ma[1] = b[i] ;
        }

        ///

        int tot = 0 ;
        for (; (1 << tot) < n ; ++tot) ;

        for (int j = n - 1 ; j >= 0 ; --j)
            for (int i = 0 ; i < tot ; ++i) {
                if (j & (1 << i)) continue ;

                int k = j + (1 << i) ;
                if (k >= n) continue ;

                for (int p = 0 ; p < 2 ; ++p)
                    t[j].mi[p] = std::min(t[j].mi[p] , t[k].mi[p]) ,
                    t[j].ma[p] = std::max(t[j].ma[p] , t[k].ma[p]) ;
            }

        int res = 0 ;
        for (int i = 0 ; i < n ; ++i) {
            ll t1 = std::max((ll)t[i].mi[0] * t[i].mi[1] , (ll)t[i].ma[0] * t[i].ma[1]) ,
               t2 = std::max((ll)t[i].mi[0] * t[i].ma[1] , (ll)t[i].ma[0] * t[i].mi[1]) ,
               tmp = std::max(t1 , t2) % mod ;
            (res += tmp) %= mod ; (res += mod) %= mod ;
        }

        printf("%d\n" , res) ;
    }

    return 0 ;
}