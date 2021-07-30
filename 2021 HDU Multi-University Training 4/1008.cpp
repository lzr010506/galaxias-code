#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 1e5 + 20 , INF = 0x3f3f3f3f ;

struct Node {
    int num , lazy ;
}tre[MAX_N << 2] ;

std::vector<int> pt[MAX_N] ;

int T , n , m , k ;

void build(int t , int x , int y) {
    tre[t] = (Node){0 , -1} ;
    if (x == y) return ;

    int mid = (x + y) >> 1 ;
    build(t << 1 , x , mid) ; build(t << 1 | 1 , mid + 1 , y) ;
}

void init() {
    build(1 , 1 , m) ;
    for (int i = 1 ; i <= n ; ++i) pt[i].clear() ;
}

void down(int t , int x , int y) {
    if (tre[t].lazy == -1) return ;

    int a = tre[t].lazy , L = t << 1 , R = t << 1 | 1 , mid = (x + y) >> 1 ;

    tre[t].lazy = -1 ; tre[L].lazy = tre[R].lazy = a ;
    tre[L].num = (mid - x + 1) * a ; tre[R].num = (y - mid) * a ;
}

void fill(int t , int x , int y , int fx , int fy , int a) {
    if (fx > fy) return ;
    if (y < fx || fy < x) return ;
    if (fx <= x && y <= fy) {
        tre[t].lazy = a ;
        tre[t].num = (y - x + 1) * a ;

        return ;
    }
    down(t , x , y) ;

    int mid = (x + y) >> 1 ;
    fill(t << 1 , x , mid , fx , fy , a) ; fill(t << 1 | 1 , mid + 1 , y , fx , fy , a) ;

    tre[t].num = tre[t << 1].num + tre[t << 1 | 1].num ;
}

int find(int t , int x , int y , int fx , int fy) {
    if (!tre[t].num) return INF ;
    if (y < fx || fy < x) return INF ;
    if (x == y) return x ;
    down(t , x , y) ;

    int mid = (x + y) >> 1 , s1 = find(t << 1 , x , mid , fx , fy) ;
    if (s1 != INF) return s1 ;
    else return find(t << 1 | 1 , mid + 1 , y , fx , fy) ;
}

void run(int x , int y) {
    if (x > y) return ;

    int pl = find(1 , 1 , n , x , y) ;
    if (pl == INF) return ;
    else fill(1 , 1 , m , pl , y , 1) ;
}
int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d %d %d" , &n , &m , &k) ;
        init() ;

        for (int i = 0 ; i < k ; ++i) {
            int x , y ; scanf("%d %d" , &x , &y) ;
            pt[x].push_back(y) ;
        }
        for (int i = 1 ; i <= n ; ++i)
            if (pt[i].size()) std::sort(pt[i].begin() , pt[i].end()) ;

        ///

        int l = pt[1].size() ? pt[1][0] : m + 1 ;
        fill(1 , 1 , m , 1 , l - 1 , 1) ;

        ll ans = tre[1].num ;
        for (int i = 2 ; i <= n ; ++i) {
            if (!pt[i].size()) run(1 , m) ;
            else {
                int siz = pt[i].size() , pre = 1 ;
                for (int j = 0 ; j < siz ; ++j) fill(1 , 1 , m , pt[i][j] , pt[i][j] , 0) ;

                for (int j = 0 ; j < siz ; ++j) {
                    int a = pt[i][j] ;
                    run(pre , a - 1) ; pre = a + 1 ;
                }
                run(pre , m) ;
            }

            ans += tre[1].num ;
        }

        printf("%lld\n" , ans) ;
    }

    return 0 ;
}