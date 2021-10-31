#include <bits/stdc++.h>

const int MAX_N = 4e7 + 10 ;

bool ap[MAX_N] ;
int T , n , t1 , t2 , pri[MAX_N] , ok[MAX_N] ;

void init() {
    int n = 3e7 ; ap[1] = 1 ;

    for (int i = 2 ; i <= n ; ++i) {
        if (!ap[i]) pri[t1++] = i ;

        for (int j = 0 ; j < t1 ; ++j) {
            int tmp = i * pri[j] ;
            if (tmp > n) break ;

            ap[tmp] = 1 ;
            if (!(i % pri[j])) break ;
        }
    }

    n = 2e7 ;
    for (int i = 1 ; i <= n ; ++i) if (!ap[i + i + 1]) ok[t2++] = i ;
}

int find(int *a , int siz , int n) {
    return *std::lower_bound(a + 0 , a + siz , n) ;
}

int main() {
    init() ;
    scanf("%d" , &T) ;

    for (; T-- ;) {
        scanf("%d" , &n) ;

        int res ;
        if (!n) res = 3 ;
        else if (n < 0) res = std::min(find(pri , t1 , -n + 1) << 1 , (find(ok , t2 , -n + 1) << 1) + 1) ;
        else {
            if (!ap[n]) res = 1 ;
            else if (!ap[n + n - 1]) res = 2 ;
            else if (!ap[n + n + 1]) res = 2 ;
            else res = std::min(find(pri , t1 , n + 1) << 1 , (find(ok , t2 , n + 1) << 1) + 1) ;
        }

        printf("%d\n" , res) ;
    }

    return 0 ;
}