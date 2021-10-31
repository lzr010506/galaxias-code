#include<bits/stdc++.h>
#define maxn 5005
using namespace std;

pair<int,int> a[maxn], b[maxn];
int aa[maxn], bb[maxn];
int visa[maxn], visb[maxn];
int rk[maxn];
int n;

int nd[maxn];

int cal2(int x) {
    for(int i=1; i<=n; i++) nd[i] = 0;
    int pt = n;
    int cnt = 0;
    for(int i=1; i<=n; i++) {
        if(visa[i]) continue;
        while(pt>=2 && a[i].first+b[pt].first>x) {
            pt--;
            cnt++;
        }
        nd[i] = cnt;
    }
    int cur = 0;
    for(int i=1; i<=n; i++) {
        if(nd[i]>cur) {
            cur++;
        }

    }
    return cur+1;
}

int cal1(int x) {
    for(int i=1; i<=n; i++) nd[i] = 0;
    int pt = 1;
    int cnt = 0;
    for(int i=n; i>=1; i--) {
        if(visa[i]) continue;
        while(pt<=n-1 && a[i].first+b[pt].first<=x) {
            pt++;
            cnt++;
        }
        nd[i] = cnt;
    }
    int cur = 0;
    for(int i=n; i>=1; i--) {
        if(nd[i]>cur) {
            cur++;
        }
    }
    return n-cur;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        scanf("%d",&n);

        for(int i=1; i<=n; i++) scanf("%d",&a[i].first), aa[i] = a[i].first, a[i].second = i;
        for(int i=1; i<=n; i++) scanf("%d",&b[i].first), bb[i] = b[i].first;
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        for(int i=1; i<=n; i++) {
            rk[a[i].second] = i;
        }
        for(int i=1; i<=n; i++) {
            int tmp = aa[i]+b[n].first;
            visa[rk[i]]=1;
            visb[n] = 1;
            printf("%d ",cal1(tmp));
            visb[n] = 0;
            int tmpp = aa[i]+b[1].first;
            visb[1] = 1;
            printf("%d\n",cal2(tmpp));
            visb[1] = 0;
            visa[rk[i]] = 0;
        }
    }
}