#include <bits/stdc++.h>
 
#define ll long long
#define db double
 
const db eps = 1e-8 ;
const int MAX_N = 1e5 + 10 ;
 
ll s[MAX_N] ;
int n , m , x , y , a[MAX_N] , b[MAX_N] ;
 
bool check(int x , int n , db k) {
    db mi = s[0] ;
    for (int i = x ; i <= n ; ++i) {
        mi = std::min(mi , s[i - x] - k * (i - x)) ;
 
        db nw = s[i] - k * i ;
        if (nw - mi > eps) return 1 ;
    }
 
    return 0 ;
}
 
db work(int n , int *a , int x) {
    s[0] = 0 ;
    for (int i = 1 ; i <= n ; ++i) s[i] = s[i - 1] + a[i] ;
 
    ///
 
    db L = 0 , R = s[n] ;
    for (; fabs(L - R) > eps ;) {
        db mid = (L + R) / 2.0 ;
        if (check(x , n , mid)) L = mid ;
        else R = mid ;
    }
 
    return L ;
}
 
int main() {
    scanf("%d %d %d %d" , &n , &m , &x , &y) ;
    for (int i = 1 ; i <= n ; ++i) scanf("%d" , &a[i]) ;
    for (int i = 1 ; i <= m ; ++i) scanf("%d" , &b[i]) ;
 
    ///
 
    printf("%0.7lf\n" , work(n , a , x) + work(m , b , y)) ;
 
    return 0 ;
}
