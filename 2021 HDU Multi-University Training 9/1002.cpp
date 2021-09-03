#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 10 ;

std::vector<int> mp[MAX_N] ;

ll k ;
int T , n , m ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d %lld" , &n , &m , &k) ;
        for (int i = 0 ; i < n ; ++i) mp[i].clear() ;
        for (int i = 0 ; i < n ; ++i)
            for (int j = 0 ; j < m ; ++j) {
                int x ; scanf("%d" , &x) ;
                mp[i].push_back(x) ;
            }

        ///

        if (k == 1) {
            int res = mp[0][0] ;
            for (int i = 0 ; i < m ; ++i) res = std::max(res , mp[0][i]) ;

            printf("%d\n" , res) ;
        }
        else if (k & 1) {
            int res = mp[0][0] ;
            for (int i = 0 ; i < m ; ++i) res = std::max(res , mp[0][i]) ;

            for (int i = 0 ; i < n ; ++i) {
                int tmp = mp[i][0] ;
                for (int j = 0 ; j < m ; ++j) tmp = std::max(tmp , mp[i][j]) ;
                res = std::min(res , tmp) ;
            }

            printf("%d\n" , std::max(res , mp[0][0])) ;
        }
        else {
            int res = mp[0][0] ;

            for (int j = 0 ; j < m ; ++j) {
                int tmp = mp[0][j] ;
                for (int i = 0 ; i < n ; ++i) {
                    tmp = std::min(tmp , mp[i][j]) ;
                }

                res = std::max(res , tmp) ;
            }

            printf("%d\n" , res) ;
        }
    }

    return 0 ;
}