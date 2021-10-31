#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll mod=998244353,G=3; //G为原根 pi为phi(p)的质因子,g^(p-1)/pi != 1
 
ll w[1<<21|3];
ll quickmi(ll a,ll b)
{
    ll t=1;
    for (; b; b>>=1,a=1ll*a*a%mod)
        if (b&1) t=1ll*t*a%mod;
    return t;
}
ll pp[1<<21|3];
void dft(vll &A,ll fl)
{
    ll n=A.size(); pp[0]=0;
    for (ll i=1; i<n; i++)
        pp[i]=(pp[i>>1]>>1)|((i&1)?(n>>1):0);
    for (ll i=0; i<n; i++)
        if (pp[i]<i) swap(A[i],A[pp[i]]);
    for (ll i=1; i<n; i<<=1)
        for (ll j=0; j<n; j+=(i<<1))
            for (ll k=0; k<i; k++)
            {
                ll t1=A[j+k],t2=1ll*w[i+k]*A[i+j+k]%mod;
                A[j+k]=(t1+t2>=mod?t1+t2-mod:t1+t2);
                A[i+j+k]=(t1<t2?t1-t2+mod:t1-t2);
            }
    if (fl==-1)
    {
        ll inv=quickmi(n,mod-2);
        for (ll i=0; i<n; i++) A[i]=1ll*A[i]*inv%mod;
        for (ll i=1; i<(n>>1); i++) swap(A[i],A[n-i]);
    }
}
  
vll mul(vll A,vll B,bool bo=0)
{
    ll nA=A.size(),nB=B.size(),L=1;
    while (L<nA+nB-1) L<<=1;
    if (L<=256)
    {
        vll C; C.resize(nA+nB-1);
        for (ll i=0; i<nA; i++)
            for (ll j=0; j<nB; j++)
                C[i+j]=(C[i+j]+1ll*A[i]*B[j])%mod;
        return C;
    }
    A.resize(L),dft(A,1);
    if (!bo) B.resize(L),dft(B,1);
    for (ll i=0; i<L; i++) A[i]=1ll*A[i]*(bo?A[i]:B[i])%mod;
    dft(A,-1),A.resize(nA+nB-1); return A;
}
  
vll getinv(vll A,ll m)
{
    ll n=A.size(); vll B,C;
    B.push_back(quickmi(A[0],mod-2));
    for (ll nw=1; nw<m; nw<<=1)
    {
        B.resize(nw<<2),C.clear(),C.resize(nw<<1);
        for (ll i=0; i<(nw<<1)&&i<n; i++) C[i]=A[i];
        C.resize(nw<<2),dft(B,1),dft(C,1);
        for (ll i=0; i<(nw<<2); i++) B[i]=((2-1ll*C[i]*B[i])%mod+mod)*B[i]%mod;
        dft(B,-1),B.resize(nw<<1);
    }
    B.resize(m); return B;
}
  
vll getmod(vll A,vll B)
{
    ll n=A.size()-1,m=B.size()-1;
    if (n<m) return A;
    vll C=A;
    reverse(C.begin(),C.end());
    reverse(B.begin(),B.end());
    vll D=getinv(B,n-m+1);
    reverse(B.begin(),B.end());
    C.resize(n-m+1);
    C=mul(C,D),C.resize(n-m+1);
    reverse(C.begin(),C.end()),C=mul(C,B),D.resize(m);
    for (ll i=0; i<m; i++) D[i]=(A[i]<C[i]?A[i]-C[i]+mod:A[i]-C[i]);
    return D;
}
void init(){
    for (ll i=0; i<21; i++)
    {
        ll wn=quickmi(G,(mod-1)>>(i+1)); w[1<<i]=1;
        for (ll j=(1<<i)+1; j<(1<<i+1); j++) w[j]=1ll*w[j-1]*wn%mod;
    }   
}
ll n,q,s[102],c[102];
vll f[102],g[102];
vector<ll> ve[102];
ll ru[103]={0};
void dfs(ll u){
    f[u].push_back(1);
    g[u].push_back(1);
    for(ll i=0;i<ve[u].size();i++){
        dfs(ve[u][i]);
        f[u]=mul(f[u],f[ve[u][i]]);
        g[u]=mul(g[u],g[ve[u][i]]);
    }
    vll dw;
    for(ll i=0;i<=s[u];i++) dw.push_back(0);
    dw[0]=1;
    dw[s[u]]=-1;
    g[u]=mul(g[u],dw);
    // printf("u : %lld\n",u);
    // printf("G: ");
    // for(ll i=0;i<g[u].size();i++) printf("%lld ",g[u][i]);
    // printf("\n");
    // printf("F: ");
    // for(ll i=0;i<f[u].size();i++) printf("%lld ",f[u][i]);
    // printf("\n");
    if(c[u]==0) return;
    vll uc=f[u];
    uc.resize(c[u]);
    // printf("uc: ");
    // for(ll i=0;i<uc.size();i++) printf("%lld ",uc[i]);
    // printf("\n");
     vll inu=mul(uc,getinv(g[u],c[u]));
    // printf("inu: ");
    // for(ll i=0;i<inu.size();i++) printf("%lld ",inu[i]);
    // printf("\n");
    inu.resize(c[u]);
    inu=mul(inu,g[u]);
    if(f[u].size()<inu.size()){
        f[u].resize(inu.size());
    }
    for(ll i=0;i<inu.size();i++){
        f[u][i]=(f[u][i]-inu[i])%mod;
    }
}
ll calc(vll A,vll B,ll n){
    if(n<=A.size()){
        vll C=mul(A,getinv(B,A.size()));
        return (C[n]%mod+mod)%mod;
    }
    ll m=max(3,int(B.size()))-1;
    B.resize(m+1);
    A=getmod(A,B);
    vll C=getinv(B,m+1);
    C=mul(C,A);
    C.resize(m+1);
    reverse(B.begin(),B.end());
    vll c={0,1};
    n--;
    vll gg={1};
    while(n){
        if(n&1){
            gg=getmod(mul(gg,c),B);
        }
        c=getmod(mul(c,c),B);
        n>>=1;
    }
    ll ans=0;
    gg.resize(m);
    for(ll i=0;i<m;i++){
        ans=(ans+1ll*gg[i]*C[i+1])%mod;
    }
    ans=(ans%mod+mod)%mod;
    return ans;
}
int main(){
    init();
    scanf("%lld%lld",&n,&q);
    for(ll i=0;i<n-1;i++){
        ll u,v;
        scanf("%lld%lld",&u,&v);
        ve[u].push_back(v);
        ru[v]++;
    }
    for(ll i=1;i<=n;i++) scanf("%lld",&s[i]);
    for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
    ll root=0;
    for(ll i=1;i<=n;i++){
        if(ru[i]==0) root=i;
    }
    dfs(root);
    while(q--){
        ll w;
        scanf("%lld",&w);
        printf("%lld\n",calc(f[root],g[root],w));
    }
}