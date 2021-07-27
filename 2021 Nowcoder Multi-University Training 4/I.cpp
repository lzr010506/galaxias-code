#include<bits/stdc++.h>
#define maxn 200005
#define INF 1e18
#define int long long
using namespace std;

int dp[maxn][2];
int a[maxn];
int indexx[maxn];
int tree[maxn*4];
void pu(int rt) {
    tree[rt] = tree[rt*2]+tree[rt*2+1];
}

void upd(int rt, int l, int r,int tar) {
    if(l == r) {
        tree[rt]++;
        return;
    }
    int mid = l+r>>1;
    if(tar<=mid) upd(rt*2,l,mid,tar);
    else upd(rt*2+1,mid+1,r,tar);
    pu(rt);
}

int query(int rt, int l, int r, int al, int ar) {
    if(al<=l && ar>=r) {
        return tree[rt];
    }
    int mid = l+r>>1;
    int ans = 0;
    if(al<=mid) ans += query(rt*2,l,mid,al,ar);
    if(ar>mid) ans += query(rt*2+1,mid+1,r,al,ar);
    return ans;
}
int pre[maxn];
signed main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) scanf("%lld",&a[i]),indexx[a[i]] = i;
    dp[1][0] = dp[1][1] = 0;
    for(int i=2; i<=n; i++) dp[i][0]=dp[i][1] = INF;
    for(int i=1;i<=n;i++) {
        pre[i] = query(1,1,n,1,indexx[i]);
        upd(1,1,n,indexx[i]);
    }
    for(int i=2; i<=n; i++) {
        int del = pre[i];
        dp[i][0] = min(dp[i][0], dp[i-1][0]+(i-del-1));
        if(indexx[i-1]>indexx[i])
            dp[i][0] = min(dp[i][0], dp[i-1][1]+(i-del-1)-1);
        else dp[i][0] = min(dp[i][0], dp[i-1][1]+(i-del-1));
        dp[i][1] = min(dp[i][1], dp[i-1][0]+(i-del-1));
        dp[i][1] = min(dp[i][1], dp[i-1][1]+(i-del-1));
        
    }
    
    printf("%lld\n",min(dp[n][1], dp[n][0]));
}