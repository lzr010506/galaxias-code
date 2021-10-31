#include <bits/stdc++.h>

#define ll long long

const int L = 2e5 , MAX_N = 2e5 + 10 ;

struct Node {
    ll y , sum[3] , lazy ;
    //[0]: x * y , [1] x * x , [2] x

    void init() {sum[0] = sum[1] = sum[2] = lazy = y = 0 ;}
}tre[MAX_N << 2] ;

ll tot ;
int T , n , q , a[MAX_N] ;

void down(int t) {
    int lzy = tre[t].lazy , L = t << 1 , R = t << 1 | 1 ;
    if (!lzy) return ;
    tre[t].lazy = 0 ;

    tre[L].y += lzy ; tre[R].y += lzy ;
    tre[L].lazy += lzy ; tre[R].lazy += lzy ;
    tre[L].sum[0] += tre[L].sum[2] * lzy ; tre[R].sum[0] += tre[R].sum[2] * lzy ;
}

void build(int t , int x , int y) {
    tre[t].init() ;
    if (x == y) {a[x] = 0 ; return ;}

    int mid = (x + y) >> 1 ;
    build(t << 1 , x , mid) ; build(t << 1 | 1 , mid + 1 , y) ;
}

void merge(int t) {
    int L = t << 1 , R = t << 1 | 1 ;
    for (int i = 0 ; i < 3 ; ++i)
        tre[t].sum[i] = tre[L].sum[i] + tre[R].sum[i] ;
}

void update1(int t , int x , int y , int fx , int fy , int a) {
    if (y < fx || fy < x) return ;
    if (fx <= x && y <= fy) {
        tre[t].sum[0] += tre[t].sum[2] * a ;
        tre[t].y += a ; tre[t].lazy += a ; return ;
    }
    down(t) ;

    int mid = (x + y) >> 1 ;
    update1(t << 1 , x , mid , fx , fy , a) ; update1(t << 1 | 1 , mid + 1 , y , fx , fy , a) ;
    merge(t) ;
}

void update2(int t , int x , int y , int f , int a) {
    if (f < x || y < f) return ;
    if (x == y) {
        tre[t].sum[2] += a ;
        tre[t].sum[0] = tre[t].sum[2] * tre[t].y ;
        tre[t].sum[1] = tre[t].sum[2] * tre[t].sum[2] ;
        return ;
    }
    down(t) ;

    int mid = (x + y) >> 1 ;
    update2(t << 1 , x , mid , f , a) ; update2(t << 1 | 1 , mid + 1 , y , f , a) ;
    merge(t) ;
}

void add(int x , int y) {
    a[x] += y ; tot += y ;
    update1(1 , 1 , L , x , L , y) ;
    update2(1 , 1 , L , x , y) ;
}

int find(int t , int x , int y , ll ad) {
    if (x == y) return x ;

    int mid = (x + y) >> 1 ;
    ll L = (tre[t << 1].sum[2] + ad) << 1 , R = tot + a[mid] ;

    if (L <= R) return find(t << 1 | 1 , mid + 1 , y , ad + tre[t << 1].sum[2]) ;
    else return find(t << 1 , x , mid , ad) ;
}

ll cal(int t , int x , int y , int fx , int fy , int ty) {
    if (y < fx || fy < x) return 0 ;
    if (fx <= x && y <= fy) return tre[t].sum[ty] ;
    down(t) ;

    int mid = (x + y) >> 1 ;
    return cal(t << 1 , x , mid , fx , fy , ty) + cal(t << 1 | 1 , mid + 1 , y , fx , fy , ty) ;
}

ll gcd(ll x , ll y) {return y ? gcd(y , x % y) : x ;}

void work() {
    int p = find(1 , 1 , L , 0) ;
    ll p1 = cal(1 , 1 , L , 1 , p - 1 , 0) , p2 = cal(1 , 1 , L , 1 , p - 1 , 2) ,
       p3 = cal(1 , 1 , L , p , L , 0) , p4 = cal(1 , 1 , L , p , L , 1) ;

    ll x = p2 * tot - p1 + p3 - p4 , y = tot * (tot - 1) , d = gcd(x , y) ;

    if (!x) printf("0/1\n") ;
    else {
        x /= d ; y /= d ;
        printf("%lld/%lld\n" , x , y) ;
    }
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d" , &n , &q) ;
        tot = 0 ; build(1 , 1 , L) ;

        for (int i = 0 ; i < n ; ++i) {
            int x ; scanf("%d" , &x) ;
            add(x , 1) ;
        }

        ///

        for (; q-- ;) {
            int op , x , y ;
            scanf("%d" , &op) ;

            if (op == 1) {
                scanf("%d %d" , &x , &y) ;
                add(y , x) ;
            }
            else work() ;
        }
    }

    return 0 ;
}