#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
ll qpow(ll x, ll y) 
{
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
    
    return 0;
}