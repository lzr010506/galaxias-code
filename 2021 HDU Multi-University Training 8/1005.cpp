#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e6 + 10 , mod = 998244353 ;

char s[MAX_N] ;
int T , n , k , sum[MAX_N] , A[MAX_N] , B[MAX_N] , f[MAX_N] , jc[MAX_N] , inv[MAX_N] ;

int cal(int n , int m) {
    if (n < m) return 0 ;

    return (ll)jc[n] * inv[m] % mod * inv[n - m] % mod ;
}

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;

    return s ;
}

void work(int k) {
    if (k < 0) for (int i = 0 ; i <= n ; ++i) f[i] = 0 ;
    else {
        f[0] = 1 ;
        for (int i = 1 ; i <= n ; ++i) {
            int pre = (f[i - 1] + cal(i - 1 , k + 1) - 1) % mod ;
            f[i] = (f[i - 1] + pre + 1) % mod ;
            f[i] = (f[i] - cal(i , k + 1) + mod) % mod ;
        }
    }
}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %s" , &k , s + 1) ;
        n = strlen(s + 1) ;

        ///

        jc[0] = 1 ;
        for (int i = 1 ; i <= n ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
        inv[n] = qpow(jc[n] , mod - 2) ;
        for (int i = n - 1 ; i >= 0 ; --i) inv[i] = (ll)inv[i + 1] * (i + 1) % mod ;

        ///

        sum[0] = 0 ;
        for (int i = 1 ; i <= n ; ++i) sum[i] = (sum[i - 1] + s[i] - '0') % mod ;
        for (int i = 1 ; i <= n ; ++i) A[i] = (ll)sum[n - i] * qpow(10 , i - 1) % mod ;
        for (int i = 1 ; i <= n ; ++i) B[i] = (ll)(s[n + 1 - i] - '0') * qpow(10 , i - 1) % mod ;

        int res = 0 ;
        work(k - 2) ;
        for (int i = 1 ; i <= n ; ++i) {
            int tmp ;
            if (n - 1 - i < 0) tmp = 0 ;
            else tmp = (ll)A[i] * f[n - 1 - i] % mod ;

            (res += tmp) %= mod ;
        }

        work(k - 1) ;
        for (int i = 1 ; i <= n ; ++i) {
            int tmp = (ll)B[i] * f[n - i] % mod ;
            (res += tmp) %= mod ;
        }

        printf("%d\n" , res) ;
    }

    return 0 ;
}