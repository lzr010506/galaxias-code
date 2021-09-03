#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 , mod = 998244353 ;

struct Node {
    bool ok ;
    int num , sum , pw ;
}tre[MAX_N << 2] ;

int T , n , q , a[MAX_N] ;

inline int lowbit(int x) {return x & (-x) ;}

int cal(int &x) {
    int s = 0 ;
    for (; x != lowbit(x) ; x -= lowbit(x)) s += lowbit(x) ;
    return s ;
}

void update(int t) {
    tre[t].num = (tre[t << 1].num + tre[t << 1 | 1].num) % mod ;
    tre[t].sum = ((ll)tre[t << 1].sum * tre[t << 1].pw % mod + (ll)tre[t << 1 | 1].sum * tre[t << 1 | 1].pw % mod) % mod ;
    tre[t].ok = tre[t << 1].ok && tre[t << 1 | 1].ok ;
}

void build(int t , int x , int y) {
    if (x == y) {
        tre[t].num = cal(a[x]) ;
        tre[t].sum = a[x] ; tre[t].pw = 1 ;
        tre[t].ok = (tre[t].num == 0) ;

        return ;
    }

    int mid = (x + y) >> 1 ;
    build(t << 1 , x , mid) ; build(t << 1 | 1 , mid + 1 , y) ;

    update(t) ; tre[t].pw = 1 ;
}

int query(int t , int x , int y , int fx , int fy , int zs) {
    if (y < fx || fy < x) return 0 ;

    zs = (ll)tre[t].pw * zs % mod ;
    if (fx <= x && y <= fy) {
        int tmp = tre[t].num ;
        zs = (ll)zs * tre[t].sum % mod ;
        return (tmp + zs) % mod ;
    }

    int mid = (x + y) >> 1 ,
        s1 = query(t << 1 , x , mid , fx , fy , zs) ,
        s2 = query(t << 1 | 1 , mid + 1 , y , fx , fy , zs) ;

    return (s1 + s2) % mod ;
}

void decrease(int t , int x , int y , int fx , int fy) {
    if (y < fx || fy < x) return ;
    if (fx <= x && y <= fy && tre[t].ok) {tre[t].sum = tre[t].pw = 0 ; return ;}
    if (x == y) {
        tre[t].num -= lowbit(tre[t].num) ;
        tre[t].ok = (tre[t].num == 0) ;

        return ;
    }

    int mid = (x + y) >> 1 ;
    decrease(t << 1 , x , mid , fx , fy) ; decrease(t << 1 | 1 , mid + 1 , y , fx , fy) ;

    update(t) ;
}

void increase(int t , int x , int y , int fx , int fy) {
    if (y < fx || fy < x) return ;
    if (fx <= x && y <= fy) {(tre[t].pw <<= 1) %= mod ; return ;}

    int mid = (x + y) >> 1 ;
    increase(t << 1 , x , mid , fx , fy) ; increase(t << 1 | 1 , mid + 1 , y , fx , fy) ;

    update(t) ;
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;

        build(1 , 1 , n) ;

        ///

        scanf("%d" , &q) ;
        for (; q-- ;) {
            int op , x , y ;
            scanf("%d %d %d" , &op , &x , &y) ;

            if (op == 1) printf("%d\n" , query(1 , 1 , n , x , y , 1)) ;
            else if (op == 2) decrease(1 , 1 , n , x , y) ;
            else increase(1 , 1 , n , x , y) ;
        }
    }

    return 0 ;
}