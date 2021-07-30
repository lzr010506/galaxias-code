#include<cstdio>
#include<algorithm>
#define N 662150
const int mod = 1e9 + 7;
typedef long long ll;
ll ans[N];
int n,m,i,j,l1,r1,a[N],q[N],t,cnt;ll t1,t2,len[N];
struct Q{
  int i,l,r,p,t;
  Q(){}
  Q(int _i,int _l,int _r,int _p,int _t){i=_i,l=_l,r=_r,p=_p,t=_t;}
}b[N];
inline bool cmp(const Q&a,const Q&b){return a.i<b.i;}
struct tag{
  ll a,b,c,d;
  tag(){a=1,b=c=d=0;}
  tag(ll _a,ll _b,ll _c,ll _d){a=_a,b=_b,c=_c,d=_d;}
  inline bool ex(){return a!=1||b||c||d;}
  inline tag operator+(const tag&B){
    return tag(a*B.a%mod,(b*B.a+B.b)%mod,(a*B.c+c)%mod,(d+b*B.c+B.d)%mod);
  }
}tmp;
struct Node{ll v,s;int l;tag t;}T[N];
inline void add1(int x,tag p){
  (T[x].s+=p.c*T[x].v+p.d*T[x].l)%=mod;
  T[x].v=(p.a*T[x].v+p.b*T[x].l)%mod;
  T[x].t=T[x].t+p;
}
inline void pb(int x){
  if(T[x].t.ex()){
    add1(x<<1,T[x].t);
    add1(x<<1|1,T[x].t);
    T[x].t=tag();
  }
}
inline void up(int x){
  T[x].v=T[x<<1].v+T[x<<1|1].v;
  T[x].s=T[x<<1].s+T[x<<1|1].s;
}
void build(int x,int a,int b){
  T[x].v=T[x].s=0,T[x].l=b-a+1,T[x].t=tag();
  if(a==b)return;
  int mid=(a+b)>>1;
  build(x<<1,a,mid),build(x<<1|1,mid+1,b);
}
void add(int x,int a,int b,int c,int d){
  if(c<=a&&b<=d){add1(x,tmp);return;}
  pb(x);
  int mid=(a+b)>>1;
  if(c<=mid)add(x<<1,a,mid,c,d);
  if(d>mid)add(x<<1|1,mid+1,b,c,d);
  up(x);
}
ll ask(int x,int a,int b,int c,int d){
  if(c<=a&&b<=d)return T[x].s;
  pb(x);
  int mid=(a+b)>>1;ll t=0;
  if(c<=mid)(t=ask(x<<1,a,mid,c,d))%=mod;
  if(d>mid)(t+=ask(x<<1|1,mid+1,b,c,d))%=mod;
  return up(x),t;
}
int qpow(ll a , int t) {
  a %= mod ;

  int s = 1;
  for (; t ; t >>= 1 , a=(ll)a*a%mod)
    if (t & 1)s = (ll)s * a % mod ;
  return s ;

}
int main(){
  int T;
  scanf("%d", &T);
  while(T --)
  {
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    cnt = 0;
    for(int i = 0; i < m; i ++) ans[i] = 0;
    for(int i = 0; i < m; i ++)
    {
      scanf("%d%d",&l1,&r1) ; len[i]=r1-l1+1;
      if(l1>1)b[++cnt]=Q(l1-1,l1,r1,i,-1);
      b[++cnt]=Q(r1,l1,r1,i,1);
    }
    std::sort(b+1,b+cnt+1,cmp);
    
    for(build(1,1,n),i=j=1;i<=n;q[++t]=i++){
      while(t&&a[q[t]]<a[i])t--;
      tmp=tag(0,a[i],0,0),add(1,1,n,q[t]+1,i),add1(1,tag(1,0,1,0));
      while(j<=cnt&&b[j].i==i)(ans[b[j].p]+=(ll)ask(1,1,n,b[j].l,b[j].r)*b[j].t)%=mod,j++;
    }
    for(build(1,1,n),t=0,i=j=1;i<=n;q[++t]=i++){
      while(t&&a[q[t]]>a[i])t--;
      tmp=tag(0,a[i],0,0),add(1,1,n,q[t]+1,i),add1(1,tag(1,0,1,0));
      while(j<=cnt&&b[j].i==i)(ans[b[j].p]+=(ll)ask(1,1,n,b[j].l,b[j].r)*b[j].t)%=mod,j++;
    }

    for(i=0;i<m;i++){
      ll t=(ll)len[i]*(len[i]+1);
      t=qpow(t,mod-2);

      ans[i] %= mod ;
      printf("%lld\n",ans[i]*t%mod);
    }
  }
  