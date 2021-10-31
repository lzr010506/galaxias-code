#include<bits/stdc++.h>
#define maxn 200005
#define INF 0x3f3f3f3f
#define int long long
using namespace std;
int a[maxn], b[maxn];
signed main() {
    int T;
    cin >> T;
    while(T--) {
        int n, s, t, h;
        scanf("%lld%lld%lld%lld",&n,&s,&t,&h);
        swap(s,t);
        for(int i=1; i<=n-1; i++) scanf("%lld",&a[i]);
        for(int i=1; i<=n-1; i++) scanf("%lld",&b[i]);
        sort(a+1,a+n);
        sort(b+1,b+n);
        a[0] = 1, a[n] = h;
        b[0] = 1, b[n] = h;
        int la = a[s], ra = a[n-t];
        int lb = b[s], rb = b[n-t];
        int maxx = ra-lb, minn = la-rb;
        int suma = 0, sumb = 0;
        for(int i=s+1; i<=n-t-1; i++) {
            suma += a[i], sumb += b[i];
        }

        if(suma>sumb) {
            int tmpl = la;
            int tmpr = la+suma-sumb-1;
            int ans = sumb-suma+1;
            if(ans<1-h) ans =1-h;
            if(tmpr >= lb) {
                if(tmpr >= rb) ans = min(ans, 1-h);
                else ans = min(ans, 1-tmpr);
            }
            tmpr = rb;
            tmpl = rb-(suma-sumb-1);
            if(tmpl<=ra) {
                if(tmpl <= la) ans = min(ans, 1-h);
                else ans = min(ans, tmpl-h);
            }
            printf("%lld\n",ans);
        } else {
            if(sumb-suma+1>maxx) {
                printf("IMPOSSIBLE\n");
            } else {
                int ans = sumb-suma+1;
                int tmpa=la, tmpb=la+suma-sumb-1;
                if(tmpb>=lb) {
                    if(tmpb >= rb) ans = min(ans, 1-h);
                    else ans = min(ans, 1-tmpb);
                }
                tmpb = rb;
                tmpa = rb-(suma-sumb-1);
                if(tmpa<=ra) {
                    if(tmpa <= la) ans = min(ans, 1-h);
                    else ans = min(ans, tmpa-h);
                }

                printf("%lld\n",ans);
            }
        }


    }
}