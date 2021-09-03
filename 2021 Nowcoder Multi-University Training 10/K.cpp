#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define mp make_pair
#define PI pair<ll,ll>
#define poly vector<ll>
#define mem(a) memset((a),0,sizeof(a))
#define For(i,l,r) for(int i=(int)(l);i<=(int)(r);i++)
#define Rep(i,r,l) for(int i=(int)(r);i>=(int)(l);i--)
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)(x.size()))
#define re resize
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
    ll x=0; char ch=gc();bool positive=1;
    for(; !isdigit(ch); ch = gc())if (ch == '-')positive = 0;
    for(; isdigit(ch); ch = gc())x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
        a=-a; putchar('-');
    }
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); putchar('\n');}
inline void wri(ll a){write(a); putchar(' ');}
ll rnd(){
    ull ans=0;
    For(i,0,4)ans=ans<<15^rand();
    return ans%((ull)1<<63);
}
const int N=1<<20|2,mod=998244353,G=3,M=500000;
ll ksm(ll a,int b){
    int ans=1;
    for(;b;b>>=1){
        if(b&1)ans=ans*a%mod;
        a=a*a%mod;
    }
    return ans;
}
struct ffter{
    int rev[N],n,L;
    int wn[N],WN[N];
    void zheng(poly &a){
        //for(auto &i:a)i=(i+mod)%mod;
    }
    void dft(poly &a){
        int n=a.size();
        for(int i=0;i<n;i++)if(rev[i]<i)swap(a[rev[i]],a[i]);
        zheng(a);
        for(int d=1,len=L-1;d<n;d<<=1,len--){
            for(int i=0;i<d;i++)WN[i]=wn[i<<len];
            for(int i=0;i<n;i+=d<<1){
                for(int j=0;j<d;j++){
                    int t=(ll)WN[j]*a[i+j+d]%mod;
                    a[i+j+d]=a[i+j]-t<0?a[i+j]-t+mod:a[i+j]-t;
                    a[i+j]=a[i+j]+t>=mod?a[i+j]+t-mod:a[i+j]+t;
                }
            }
        }
    }
    void idft(poly &a){
        dft(a);
        reverse(a.begin()+1,a.end());
        int x=ksm(a.size(),mod-2);
        for(auto &i:a)i=(ll)i*x%mod;
    }
    void init(int N){
        n=1; L=0; while(n<N)n<<=1,L++;
        int w=ksm(G,(mod-1)/n);
        for(int i=0;i<n;i++){
            wn[i]=i?(ll)wn[i-1]*w%mod:1; rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
        }
    }
}T;
 
void FFT(poly &a,poly &b){
    int sz=a.size()+b.size()-1;
    T.init(sz);
    a.resize(T.n); b.resize(T.n);
    T.dft(a); T.dft(b);
    for(int i=0;i<T.n;i++)a[i]=(ll)a[i]*b[i]%mod;
    T.idft(a);
    a.resize(sz);
}
void bg(poly &x){
    int sz=1;
    while(sz<x.size())sz<<=1;
    x.resize(sz);
}
poly inv(poly a){//a.size()必须为2的幂次
    bg(a);
    int n=a.size();
    if(n==1){
        poly b(1); b[0]=ksm(a[0],mod-2); return b;
    }assert(n%2==0);
    poly b=a; b.resize(n>>1); b=inv(b);
    a.resize(n<<1); b.resize(n<<1);
    T.init(n<<1);
    T.dft(b); T.dft(a);
    for(int i=0;i<(n<<1);i++)b[i]=((b[i]*2-(ll)a[i]*b[i]%mod*b[i])%mod+mod)%mod;
    T.idft(b);
    b.resize(n);
    return b;
}
ll fac[N],ni[N];
ll c(int a,int b){
    return fac[a]*ni[b]%mod*ni[a-b]%mod;
}
ll get(int a,int b){
    if(a%2!=b%2||a<b)return 0;
    return c(a,(a+b)/2);
}
poly solve(int n,int a,int t){
    poly f(t+1),h(t+1),g(t+1);
    For(i,0,t){
        h[i]=ksm(2,i);
        g[i]=get(i,0);
        if(i>n)g[i]=g[i]+get(i,n+1);
    }
    g=inv(g); g.resize(t+1);
    FFT(h,g);
    h.resize(t+1);
    For(i,0,t)f[i]=(get(i,a)+get(i,n+1-a))%mod;
     
    FFT(f,h);
    For(i,0,t)f[i]=(ksm(2,i)-f[i]+mod)%mod;
    return f;
}
int t,n,m,a,b;
int main(){
    cin>>t>>n>>m>>a>>b;
    For(i,fac[0]=1,M)fac[i]=fac[i-1]*i%mod;
    ni[M]=ksm(fac[M],mod-2);
    Rep(i,M,1)ni[i-1]=ni[i]*i%mod;
    poly f(t+1),g(t+1); f=solve(n,a,t),g=solve(m,b,t);
    ll ans=0;
    For(i,0,t)ans=(ans+c(t,i)*f[i]%mod*g[t-i])%mod;
    cout<<ans<<endl;
}