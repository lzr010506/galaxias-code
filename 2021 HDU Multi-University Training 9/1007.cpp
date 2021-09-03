#include <bits/stdc++.h>

const int PT = 1e7 + 1 , MAX_M = 1e7 + 5 ;

char op ;
int pre[MAX_M] , nxt[MAX_M] , pl[MAX_M] ;
int q , ara , ans , L , R , fir , ed , tot ;

void del(int x) {
    int p = pre[x] , n = nxt[x] ;

    if (p != -1) nxt[p] = n ;
    if (n != -1) pre[n] = p ;
    --tot ;

    if (x == fir) fir = nxt[fir] ;
    if (x == ed) ed = pre[ed] ;
}

int main() {
    tot = 0 ; L = PT ; R = L - 1 ;
    scanf("%d" , &q) ; ara = q << 1 ;

    int nw = 0 ;
    for (; q-- ;) {
        getchar() ; scanf("%c" , &op) ;

        if (op == 'L') {
            ++nw ;

            if (!tot) {
                pre[nw] = nxt[nw] = -1 ; fir = ed = ans = nw ;
                pl[nw] = --L ; ++tot ;
            }
            else {
                pre[nw] = pre[fir] ; nxt[nw] = fir ; pre[fir] = nw ;
                pl[nw] = --L ; fir = nw ;

                if (!(tot & 1)) ans = pre[ans] ;
                ++tot ;
            }
        }
        else if (op == 'R') {
            ++nw ;

            if (!tot) {
                pre[nw] = nxt[nw] = -1 ; fir = ed = ans = nw ;
                pl[nw] = ++R ; ++tot ;
            }
            else {
                nxt[nw] = nxt[ed] ; pre[nw] = ed ; nxt[ed] = nw ;
                pl[nw] = ++R ; ed = nw ;

                if (tot & 1) ans = nxt[ans] ;
                ++tot ;
            }
        }
        else if (op == 'G') {    
            int x ; scanf("%d" , &x) ;
            int px = pl[x] , py = pl[ans] ;

            if (tot & 1) {
                if (px <= py) ans = nxt[ans] ;
            }
            else {
                if (py <= px) ans = pre[ans] ;
            }

            del(x) ;
        }
        else printf("%d\n" , ans) ;
    }

    return 0 ;
}