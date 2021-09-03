#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
#define random(a,b) (rand()%(b-a+1)+a)
LL quick_mod(LL a, LL b, LL c) {
    LL ans = 1;
    while (b) {
        if (b % 2 == 1)ans = (ans*a) % c;
        b /= 2;
        a = (a*a) % c;
    }
    return ans;
}
LL p;
LL w;//二次域的D值
bool ok;//是否有解

struct QuadraticField { //二次域
    LL x, y;
    QuadraticField operator*(QuadraticField T) { //二次域乘法重载
        QuadraticField ans;
        ans.x = (this->x*T.x%p + this->y*T.y%p*w%p) % p;
        ans.y = (this->x*T.y%p + this->y*T.x%p) % p;
        return ans;
    }
    QuadraticField operator^(LL b) { //二次域快速幂
        QuadraticField ans;
        QuadraticField a = *this;
        ans.x = 1;
        ans.y = 0;
        while (b) {
            if (b & 1) {
                ans = ans*a;
                b--;
            }
            b /= 2;
            a = a*a;
        }
        return ans;
    }
};

LL Legender(LL a) { //求勒让德符号
    LL ans=quick_mod(a, (p - 1) / 2, p);
    if (ans + 1 == p)//如果ans的值为-1，%p之后会变成p-1。
        return -1;
    else
        return ans;
}

LL Getw(LL n, LL a) { //根据随机出来a的值确定对应w的值
    return ((a*a - n) % p + p) % p;//防爆处理
}

LL Solve(LL n) {
    LL a;
    if (p == 2)//当p为2的时候，n只会是0或1，然后0和1就是对应的解
        return n;
    if (Legender(n) == -1)//无解
        ok = false;
    srand((unsigned)time(NULL));
    while (1) { //随机a的值直到有解
        a = random(0, p - 1);
        w = Getw(n, a);
        if (Legender(w) == -1)
            break;
    }
    QuadraticField ans,res;
    res.x = a;
    res.y = 1;//res的值就是a+根号w
    ans = res ^ ((p + 1) / 2);
    return ans.x;
}



ll qpow(ll x, ll y) {
    ll res = 1;
    while(y) {
        if(y&1) res=res*x%p;
        y>>=1;
        x=x*x%p;
    }
    return res;
}

ll inv(ll x) {
    return qpow(x,p-2);
}

int main() {
    int T;
    cin >> T;
    p = 1000000007;
    ll inv2 = inv(2ll);
    ll inv4 = inv(4ll);
//    cout << inv(1ll*625000005*8%p);
    while(T--) {
        LL t,v,r;
        ll g = 10;
        scanf("%lld%lld%lld",&t,&v,&r);
        double x = (1.0*v*v*t*t+0.25*g*g*t*t*t*t-r*r)/(1.0*g*t*t*t*v);
        if(x<=-1) {
            printf("0\n");
            continue;
        }else if(x>=1) {
            printf("1\n");
            continue;
        }
        ll tmp = ((v*v%p*t%p*t%p+inv4*g%p*g%p*t%p*t%p*t%p*t%p)%p-r*r%p+p)%p;
        tmp = tmp*inv(g*t%p*t%p*v%p*t%p)%p;
        tmp += 1;
        tmp %= p;
        tmp *= inv2;
        tmp %= p;
        printf("%lld\n",tmp);
    }
}