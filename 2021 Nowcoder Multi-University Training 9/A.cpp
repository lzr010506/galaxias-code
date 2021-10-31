#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 110, M = 998244353, DD=201;
int f[DD][N][N], C[N][N], A[N][N];
int ksm(int x, int y) {
    int ans = 1;

    for (; y; y >>= 1, x = x * x % M)
        if (y & 1)
            (ans *= x) %= M;

    return ans;
}
int S(int n, int m) {
    int s = 0;

    for (int i = 0, v = 1; i <= m + 1; i++, (v *= n) %= M)
        (s += A[m][i] * v) %= M;

    return s;
}
int solve(int k1, int k2, int a, int b, int c, int n, int dep) {
    assert(dep<DD);
    if (f[dep][k1][k2] != -1)
        return f[dep][k1][k2];

    int v = 0;

    if (a == 0)
        return f[dep][k1][k2] = S(n, k1) * ksm(b / c, k2) % M;

    if (a >= c || b >= c) {
        for (int i = 0; i <= k2; i++)
            for (int j = 0; j <= k2 - i; j++) {
                int k = k2 - i - j;
                (v += C[k2][i] * C[k2 - i][j] % M * ksm(a / c, i) % M * ksm(b / c, j) % M * solve(k1 + i, k, a % c, b % c, c,
                        n, dep + 1)) %= M;
            }

        return f[dep][k1][k2] = v;
    }

    int m = (a * n + b) / c - 1;
    v = S(n, k1) * ksm(m + 1, k2) % M;

    for (int i = 0; i <= k2 - 1; i++)
        for (int j = 0; j <= k1 + 1; j++)
            (v += M - C[k2][i] * A[k1][j] % M * solve(i, j, c, c - b - 1, a, m, dep + 1) % M) %= M;

    return f[dep][k1][k2] = v;
}
/*
signed main() {
    scanf("%lld", &T);
    C[0][0] = 1;

    for (int i = 1; i < N; i++) {
        C[i][0] = 1;

        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }

    A[0][1] = A[0][0] = 1;

    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= i + 1; j++)
            A[i][j] = C[i + 1][j];

        for (int j = 0; j < i; j++)
            for (int k = 0; k <= j + 1; k++)
                (A[i][k] += M - C[i + 1][j] * A[j][k] % M) %= M;

        int Inv = ksm(i + 1, M - 2);

        for (int j = 0; j <= i + 1; j++)
            (A[i][j] *= Inv) %= M;
    }

    while (T--) {
        scanf("%lld%lld%lld%lld%lld%lld", &n, &a, &b, &c, &k1, &k2);
        memset(f, -1, sizeof f);
        printf("%lld\n", solve(k1, k2, a, b, c, n, 0));
    }
}
*/

////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX_N = 100 + 10 , mod = 998244353 ;

int n , a , b , c , p , q ;
int sum[MAX_N] , K[MAX_N] , g[MAX_N] ;

int qpow(int x , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , x = x * x % mod)
        if (t & 1) s = s * x % mod ;

    return s ;
}

void get_A(int n , int *y) {
    for (int i = 1 ; i <= n + 1 ; ++i) {
        int xs = y[i] ;
        for (int j = 1 ; j <= n + 1 ; ++j) {
            if (i == j) continue ;
            int tmp = (i - j + mod) % mod ;
            xs = xs * qpow(tmp , mod - 2) % mod ;
        }

        ///

        for (int j = 0 ; j <= n ; ++j) g[j] = 0 ;
        g[0] = xs ;

        for (int j = 1 ; j <= n + 1 ; ++j) {
            if (i == j) continue ;

            int ned = (mod - j) % mod ;
            for (int k = n ; k ; --k) g[k] = (g[k] * ned % mod + g[k - 1]) % mod ;
            g[0] = g[0] * ned % mod ;
        }

        for (int j = 0 ; j <= n ; ++j) (K[j] += g[j]) %= mod ;
    }
}

int check(int n , int a , int b , int c , int p , int q) {
    int s = 0 ;
    for (int i = 0 ; i <= n ; ++i) {
        int p1 = qpow(i , p) , q1 = qpow((a * i + b) / c , q) ;
        p1 = p1 * q1 % mod ;

        (s += p1) %= mod ;
    }

    return s ;
}

signed main() {
    C[0][0] = 1;

    for (int i = 1; i < N; i++) {
        C[i][0] = 1;

        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % M;
    }

    A[0][1] = A[0][0] = 1;

    for (int i = 1; i < N - 1; i++) {
        for (int j = 0; j <= i + 1; j++)
            A[i][j] = C[i + 1][j];

        for (int j = 0; j < i; j++)
            for (int k = 0; k <= j + 1; k++)
                (A[i][k] += M - C[i + 1][j] * A[j][k] % M) %= M;

        int Inv = ksm(i + 1, M - 2);

        for (int j = 0; j <= i + 1; j++)
            (A[i][j] *= Inv) %= M;
    }

    ///

    scanf("%lld %lld %lld %lld %lld %lld" , &a , &b , &c , &p , &q , &n) ;

    sum[1] = 1 ;
    for (int i = 2 ; i <= q + 2 ; ++i) sum[i] = (sum[i - 1] + qpow(i , q)) % mod ;
    get_A(q + 1 , sum) ;

    int res = 0 ;
    memset(f, -1, sizeof f);
    for (int i = 0 ; i <= q + 1 ; ++i) {
        int tmp = K[i] * solve(p , i , a , b , c , n , 0) % mod ;
        (res += tmp) %= mod ;
    }
    printf("%lld\n" , res) ;
}