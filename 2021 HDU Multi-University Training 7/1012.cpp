#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 , mod = 998244353 ;

std::vector<int> ap[MAX_N] ;

char s[MAX_N] ;
int T , n , c1[MAX_N] , c2[MAX_N] ;

int squ(int x) {return (ll)x * x % mod ;}

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%s" , s + 1) ;
        n = strlen(s + 1) ;

        for (int i = 'a' ; i <= 'z' ; ++i) {
            ap[i].clear() ; ap[i].push_back(0) ;
        }
        for (int i = 1 ; i <= n ; ++i) ap[s[i]].push_back(i) ;

        ///

        int res = 0 ;
        for (int c = 'a' ; c <= 'z' ; ++c) {
            int siz = ap[c].size() - 1 ;
            if (!siz) continue ;

            for (int i = 1 ; i <= siz ; ++i) c1[i] = ap[c][i] - ap[c][i - 1] ;
            for (int i = 1 ; i < siz ; ++i) c2[i] = ap[c][i + 1] - ap[c][i] ;
            c2[siz] = n - ap[c][siz] + 1 ;

            int t1 = 0 , t2 = 0 , t3 = 0 ;
            for (int i = 1 ; i <= siz ; ++i) {
                int ii = i + 1 ;
                (t1 += c1[i]) %= mod ; t2 = (t2 + (ll)i * c1[i] % mod) % mod ;
                t3 = (t3 + (ll)squ(i) * c1[i] % mod) % mod ;

                int p1 = (ll)squ(ii) * t1 % mod , p2 = 2LL * ii * t2 % mod ;
                p1 = (p1 - p2 + mod) % mod ; (p1 += t3) %= mod ; p1 = (ll)p1 * c2[i] % mod ;

                (res += p1) %= mod ;
            }
        }

        printf("%d\n" , res) ;
    }

    return 0 ;
}