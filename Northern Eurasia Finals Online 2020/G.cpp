#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
using namespace std;
typedef long long ll;
#define db double
#define ll long long

const int maxn = 4e6+50;
ll fac[maxn];
ll inv[maxn];
ll qpow(long long a,long long b) {
	ll ans=1;
	ll k=a;
	while(b) {
		if(b&1)ans=ans*k%mod;
		k=k*k%mod;
		b>>=1;
	}
	return (ans+mod)%mod;
}
void init(int xx) {
	long long it;
	fac[0]=1;
	inv[0]=1;
	fac[1]=1;
	inv[1]=1;
	for(int i=2; i<=xx; i++)
		fac[i]=fac[i-1]*i%mod,inv[i]=mod-(mod/i)*inv[mod%i]%mod;
	for(int i=1; i<=xx; i++)
		inv[i]=inv[i-1]*inv[i]%mod;
}
ll C(ll n,ll m) {
	if (n<m||m<0 || n<0) return 0;
	return  (fac[n]*inv[m]%mod*inv[n-m]%mod+mod)%mod;
}




int x[3] , y[3] ;
std::vector<int> res ;
void findd(int b , int *x , int *y) {
	std::vector<db> point ;
	point.clear() ;
	res.clear() ;

	for (int i = 0 ; i < 3 ; ++i) {
		int j = (i + 1) % 3 ,
		    ml = std::min(x[i] , x[j]) , mr = std::max(x[i] , x[j]) ,
		    myl = std::min(y[i] , y[j]) , myr = std::max(y[i] , y[j]) ;
		ll A = y[j] - y[i] , B = x[j] - x[i] , C = x[j] * y[i] - x[i] * y[j] ;

		if (A == B) {
			if (y[i] != x[i] + b) continue ;

			point.clear() ;
			point.push_back(x[i]) ;
			point.push_back(x[j]) ;
			break ;
		} else {
			db tx = (B * b - C) * 1.0 / (A - B) ;

			if (tx < ml || mr < tx) continue ;
			if (tx + b < myl || myr < tx + b) continue ;
			point.push_back(tx) ;
		}
	}

	int siz = point.size() ;
	if (siz) {
		std::sort(point.begin() , point.end()) ;
		if(abs(point[0]-(int)point[0]) <1e-9) res.push_back((int)point[0]);
		else res.push_back(ceil(point[0])) ;
		
	//	if(abs(point[0]-res[0])>=1)cout << "xxxxxxxxxxxxxxxx" <<endl;
		if (siz > 1) {
			if(abs(point[point.size()-1]-(int)point[point.size()-1])<1e-9) res.push_back((int)point[point.size()-1]);
			else res.push_back(floor(point[point.size()-1])) ;
			
		//	if(abs(point[1]-res[1])>=1)cout << "xxxxxxxxxxxxxxxx" <<endl;
		}
		
		
	}

	///

	//for (int i = 0 ; i < res.size() ; ++i) printf("%d " , res[i]) ;
}





signed main() {
	int T;
	cin >> T;
	init(4000002);
	while(T--) {
		scanf("%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
		int ans = 0;
		for(int b=2000002; b>=0; b-=2) {
			findd(b,x,y);
			if(res.size() == 0) continue;
			//	cout << res[0] << " " << res[1] << endl;
			if(res[0]>res[1]) continue;
			if(res[0]<-b/2 && res[1]<-b/2) continue;
			res[0] = max(-b/2, res[0]);

			ans += (C(res[1]+1+b,b/2+1)-C(res[0]+b,b/2+1)+mod)%mod;
			ans %= mod;
		}
		cout << ans <<endl;



	}
}


/*
12
9 6 3 5 3 6
*/
