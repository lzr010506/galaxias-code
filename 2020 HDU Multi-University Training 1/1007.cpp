#include <unordered_map>
#include <bits/stdc++.h>

#define ll long long

const int mod = 998244353 ;

int T , n , x ;

///banzi

ll a , z , p ;
std::unordered_map<ll , int> ha ;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}

int exbsgs(int a , int b , int x) {
    ha.clear() ;
    a %= x ; b %= x ; ll m = ceil(sqrt((double)x)) ;
    if (b == 1) return 0 ;

    ll tmp = 1 , cnt = 0 , D = 1 ;
    while ((tmp = gcd(a , x)) != 1) {
        if (b % tmp) return x ;
        ++cnt ; b /= tmp ; x /= tmp ; D = (D * (a / tmp)) % x ;
    }
    ha[b % x] = 0 ; ll q = 1 ;

    for (int i = 1 ; i <= m ; ++i) q = (q * a) % x , ha[q * b % x] = i ;
    for (int i = 1 ; i <= m ; ++i) {
        D = (D * q) % x ;
        if (ha[D]) {ll s = i * m - ha[D] + cnt ; return (s % x + x) % x ;}
    }
    return x ;
}

///

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &x) ;

        int ned = (ll)n * x % mod ,
            p1 = (ned + (n - 1)) % mod ,
            p2 = (ned + mod - (n - 1)) % mod ;
        
        int r1 = exbsgs(n - 1 , p1 , mod) , r2 = exbsgs(n - 1 , p2 , mod) ;

        if (r1 != mod && !(r1 & 1)) r1 = mod ;
        if (r2 != mod && (r2 & 1)) r2 = mod ;

        r1 = std::min(r1 , r2) ;
        if (r1 == mod) printf("-1\n") ;
        else printf("%d\n" , r1) ;
    }
}