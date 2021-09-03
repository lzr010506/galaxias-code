#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 ;

struct data {
    ll x , y ;
}g[MAX_N] ;

std::vector<int> ap ;

bool vis[MAX_N] ;
int T , n , f[MAX_N] ;

ll gcd(ll a , ll b) {return b ? gcd(b , a % b) : a ;}

data work(int x) {
    if (vis[x]) {
        if (g[x].x == -1) {
            int siz = ap.size() , p = 0 ;
            for (; ap[p] != x ; ++p) ;

            ll res = 0 , fm = siz - p ;
            for (int i = p ; i < siz ; ++i) res += f[ap[i]] ;

            ll d = gcd(res , fm) ;
            res /= d ; fm /= d ;

            return (data){res , fm} ;
        }
        else return g[x] ;
    }

    vis[x] = 1 ; ap.push_back(x) ;
    return work(f[x]) ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &f[i]) ;

        ///

        for (int i = 1 ; i <= n ; ++i) g[i].x = -1 , vis[i] = 0 ;
        for (int i = 1 ; i <= n ; ++i)
            if (!vis[i]) {
                ap.clear() ;
                data res = work(i) ;

                int siz = ap.size() ;
                for (int i = 0 ; i < siz ; ++i) g[ap[i]] = res ;
            }

        bool ok = 1 ;
        for (int i = 2 ; i <= n ; ++i)
            if (g[i].x != g[i - 1].x || g[i].y != g[i - 1].y) ok = 0 ;

        if (ok) printf("YES\n") ;
        else printf("NO\n") ;
    }

    return 0 ;
}