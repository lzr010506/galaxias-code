#include <bits/stdc++.h>

#define ll long long

const ll INF = 6e18 ;
const int MAX_N = 5e3 + 10 ;

struct POINT {int x , y ;}a[MAX_N] ;

int T , n ;
bool ud[MAX_N] ;
ll lowcost[MAX_N] ;

ll cal(int x , int y) {
    ll p1 = abs(a[x].x - a[y].x) , p2 = abs(a[x].y - a[y].y) ;
    return p1 * p1 + p2 * p2 ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i)
            scanf("%d %d" , &a[i].x , &a[i].y) , lowcost[i] = INF , ud[i] = 0 ;

        ///

        for (int i = 2 ; i <= n ; ++i) lowcost[i] = cal(1 , i) ;

        ll ans = 0 ; ud[1] = 1 ;
        for (int i = 1 ; i < n ; ++i) {
            ll lc = INF ; int p = 0 ;
            for (int j = 1 ; j <= n ; ++j)
                if (!ud[j] && lc > lowcost[j]) lc = lowcost[j] , p = j ;

            ud[p] = 1 ; ans = std::max(ans , lowcost[p]) ;

            for (int i = 1 ; i <= n ; ++i)
                if (!ud[i]) lowcost[i] = std::min(lowcost[i] , cal(p , i)) ;
        }

        printf("%lld\n" , ans) ;
    }

    return 0 ;
}