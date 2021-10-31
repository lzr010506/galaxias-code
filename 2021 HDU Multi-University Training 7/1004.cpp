#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll qpow(ll a,ll b) {
    ll ans=1;
    while(b) {
        if(b&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}

//1.可以预处理阶乘表
ll fac[2000005];
void Get_Fact() {  //p代表你需要取模的素数
    fac[0]=1;
    for(int i=1; i<=2000001; i++)
        fac[i]=(fac[i-1]*i)%mod;
}
ll Lucas(ll n,ll m) {
    ll ans=1;
    while(n&&m) {
        ll a=n%mod,b=m%mod;
        if(a<b) return 0;
        ans=(ans*fac[a]*qpow(fac[b]*fac[a-b]%mod,mod-2))%mod;
        n/=mod;
        m/=mod;
    }
    return ans;
}

int main() {
    int T;
    Get_Fact();
    cin >> T;

    while(T--) {
        ll n, m;
        scanf("%lld%lld",&n,&m);
        if(m>=n+1) {
            printf("%lld\n",(Lucas(n+m,m)-Lucas(m-1, n)+mod)%mod);
        }else {
            printf("%lld\n",Lucas(n+m, m));
        }
    }
}