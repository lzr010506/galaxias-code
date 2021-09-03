#include<bits/stdc++.h>
#define LL long long
#define N 50005
#define mod 998244353ll
using namespace std;
struct Edge{
	int u,v,nxt;
	Edge(){nxt=-1;}
	Edge(int u,int v):u(u),v(v){}
}g[N<<1];
LL n,k,cnt=-1,head[N],tmp[105][2],dp[N][105][2],siz[N];
inline void add_edge(int u,int v){
	g[++cnt]=Edge(u,v);
	g[cnt].nxt=head[u];
	head[u]=cnt;
}
inline LL qpow(LL x,LL k){
	LL res=1ll;
	for(;k;k>>=1,(x*=x)%=mod)
		if(k&1)	(res*=x)%=mod;
	return res;	
}
void dfs(int u,int fa){
	siz[u]=1,dp[u][0][0]=dp[u][0][1]=1;
	for(int i=head[u];~i;i=g[i].nxt){
		int v=g[i].v;
		if(v==fa)	continue;
		dfs(v,u);
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<=min(siz[u]-1,k);++i)
			for(int j=0;j<=min(siz[v]-1,k-i);++j){
				(tmp[i+j][0]+=dp[u][i][0]*dp[v][j][0]%mod)%=mod;
				(tmp[i+j][1]+=dp[u][i][0]*dp[v][j][1]%mod)%=mod;
				(tmp[i+j][1]+=dp[u][i][1]*dp[v][j][0]%mod)%=mod;
				if(i+j==k)	continue;
				(tmp[i+j+1][0]+=dp[u][i][0]*dp[v][j][1]%mod)%=mod;
				(tmp[i+j+1][1]+=dp[u][i][1]*dp[v][j][1]%mod)%=mod;
			}
		memcpy(dp[u],tmp,sizeof(tmp));
		siz[u]+=siz[v];
	}
}
signed main(){
	memset(head,0xff,sizeof head);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<n;++i){
		LL u,v;
		scanf("%lld%lld",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	printf("%lld",qpow(n,k-1)*dp[1][k][1]%mod);
	return 0;
}
