#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ULL unsigned long long
using namespace std;
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
    char c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
const int N = 4000010;
const int G = 3;
const int mod = 998244353;
const int MOD = mod;

namespace Math {
    int inv[N],fac[N],ifac[N];
    int upm(int x) {
        return x>=mod?x-mod:(x<0?x+mod:x);
    }
    void up(int &x,int y) {
        x=upm(x+y);
    }
    int mul(int x,int y) {
        return 1ll*x*y%mod;
    }
    ll qpow(ll x,ll y) {
        ll res=1;
        for(; y; y>>=1,x=x*x%mod)if(y&1)res=res*x%mod;
        return res;
    }
    ll getinv(int x) {
        return qpow(x,mod-2);
    }
    void initmath() {
        inv[0]=inv[1]=1;
        for(int i=2; i<N; ++i) inv[i]=mul(mod-mod/i,inv[mod%i]);
        fac[0]=1;
        for(int i=1; i<N; ++i) fac[i]=mul(fac[i-1],i);
        ifac[N-1]=getinv(fac[N-1]);
        for(int i=N-2; ~i; --i)ifac[i]=mul(ifac[i+1],i+1);
    }
    int m,L,rev[N];
    void ntt(int *a,int n,int op) {
        for(int i=0; i<n; ++i) if(i<rev[i]) swap(a[i],a[rev[i]]);
        for(int i=1; i<n; i<<=1) {
            int wn=qpow(G,(mod-1)/(i<<1));
            if(!~op) wn=getinv(wn);
            for(int j=0; j<n; j+=i<<1) {
                int w=1;
                for(int k=0; k<i; ++k,w=mul(w,wn)) {
                    int x=a[j+k],y=mul(w,a[i+j+k]);
                    a[j+k]=upm(x+y);
                    a[i+j+k]=upm(x-y);
                }
            }
        }
        if(!~op)for(int i=0,iv=getinv(n); i<n; ++i)a[i]=mul(a[i],iv);
    }
    void reget(int n) {
        for(m=1,L=0; m<n; m<<=1,++L);
        for(int i=0; i<m; ++i) rev[i]=(rev[i>>1]>>1)|((i&1)<<(L-1));
    }
    void polymult(int *a,int *b,int *c,int dega,int degb) {
        static int A[N],B[N];
        reget(dega+degb-1);
        copy(a,a+dega,A);
        copy(b,b+degb,B);
        ntt(A,m,1);
        ntt(B,m,1);
        for(int i=0; i<m; ++i) A[i]=mul(A[i],B[i]);
        ntt(A,m,-1);
        copy(A,A+dega+degb-1,c);
        fill(c+dega+degb-1,c+m,0);
        fill(A,A+m,0);
        fill(B,B+m,0);
    }
}
using namespace Math;

int aa[N], A[N], B[N];
int main() 
{
    initmath();
    int n = read();
    int m = 0;
    rep(i, 1, n)
    {
        aa[i] = read();
        m = max(m, aa[i]);
        A[aa[i]] ++;
    }
    rep(i, 1, n) B[m - aa[i]] ++;
    polymult(A,B,A,m+1,m+1);
    ll ans = 1;
    rep(i, 1, m)
        ans = ans * qpow(i, A[i + m]) % MOD;
    rep(i, 1, n) ans = ans * ifac[i] % MOD;
    rep(i, 1, n) ans = ans * (aa[i] + 1) % MOD;
    printf("%lld\n", ans);
    return 0;
}
