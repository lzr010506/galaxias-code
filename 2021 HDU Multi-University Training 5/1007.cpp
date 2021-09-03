#include <bits/stdc++.h>

#define ll long long

const int mod = 1e9 + 7 ;

ll n ;
int T ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;

    return s ;
}

int main() {
    int ny1 = qpow(12 , mod - 2) , ny2 = qpow(2 , mod - 2) , ny3 = qpow(6 , mod - 2) ;

    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%lld" , &n) ; n %= mod ;

        int p1 , p2 , p3 , tot ;
        p1 = (ll)n * n % mod ;
        p1 = (ll)p1 * (2LL * n + 1) % mod * (n + 1) % mod * (n + 1) % mod ;
        p1 = (ll)p1 * ny1 % mod ;

        tot = (ll)p1 * n % mod * n % mod ;

        p3 = (((ll)n * n % mod + n) % mod + mod - 2) % mod ;
        p3 = (ll)p3 * ny2 % mod ;

        p2 = 2LL * n * n % mod * n % mod ;
        (p2 += 3LL * n % mod * n % mod) %= mod ;
        (p2 += n) %= mod ; (p2 += (mod - 6)) %= mod ;
        p2 = (ll)p2 * ny3 % mod ;
        p2 = (ll)p3 * ((p2 + p3) % mod) % mod ;

        (p1 += p2) %= mod ;
        printf("%d\n%d\n" , p1 , tot) ;
    }

    return 0 ;
}