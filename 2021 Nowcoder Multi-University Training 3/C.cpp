#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100005
#define M 1000005
#define inf 1ll<<31ll-1
using namespace std;
int n,m,s,t,ss,tt,num=1;
int v[M],w[M],next[M];
int d[N],f[N],sum[N],first[N];
bool can[N];
void add(int x,int y,int f)
{
	num++;
	next[num]=first[x];
	first[x]=num;
	v[num]=y;
	w[num]=f;
}
bool bfs(int start,int end)
{
	int x,y,i,j;
	memset(d,-1,sizeof(d));
	memcpy(f,first,sizeof(f));
	queue<int>q;
	q.push(start);
	d[start]=0;
	while(!q.empty())
	{
		x=q.front();
		q.pop();
		for(i=first[x];i;i=next[i])
		{
			y=v[i];
			if(w[i]&&d[y]==-1&&!can[y])
			{
				d[y]=d[x]+1;
				if(y==end)
				  return true;
				q.push(y);
			}
		}
	}
	return false;
}
int dinic(int now,int end,int flow)
{
	if(now==end)
	  return flow;
	int x,delta,ans=0;
	for(int &i=f[now];i;i=next[i])
	{
		x=v[i];
		if(w[i]&&d[x]==d[now]+1&&!can[x])
		{
			delta=dinic(x,end,min(flow,w[i]));
			w[i]-=delta;
			w[i^1]+=delta;
			flow-=delta;
			ans+=delta;
			if(!flow)  break;
		}
	}
	if(flow)  d[now]=-1;
	return ans;
}
const int N = 2e3 + 10;
int b[N], c[N];
vector<int> hang, lie;
pair<int, int> ppp[1000100];
int main()
{
	int x,y,i,j,l,r;
	int ans=0,maxflow=0;
	int nn, mm, kk;
	nn = read();
	mm = read();
	kk = read();
	rep(i, 1, nn) b[i] = read();
	rep(i, 1, nn) c[i] = read();
	rep(i, 1, mm)
	{
		int x = read();
		int y = read();
		ppp[i] = make_pair(x, y);
	}
	rep(i, 1, nn)
		rep(j, 1, nn)
		{
			if(b[i] == c[j])
			{
				add(i, j + 501, )
			} 
		}

	n = 2000;
	ss=0,tt=n+1;
	for(i=1;i<=m;++i)
	{
		scanf("%d%d%d%d",&x,&y,&l,&r);
		sum[x]-=l,sum[y]+=l;
		add(x,y,r-l),add(y,x,0);
	}
	for(i=1;i<=n;++i)
	{
		if(sum[i]>0)  add(ss,i,sum[i]),add(i,ss,0),ans+=sum[i];
		if(sum[i]<0)  add(i,tt,-sum[i]),add(tt,i,0);
	}
	add(t,s,inf),add(s,t,0);
	while(bfs(ss,tt))
	  maxflow+=dinic(ss,tt,inf);
	can[ss]=false;
	can[tt]=false;
	if(maxflow!=ans)
	{
		printf("please go home to sleep");
		return 0;
	}
	int minflow=0;
	add(t,s,-inf),add(s,t,0);
	while(bfs(t,s))
	  minflow-=dinic(t,s,inf);
	printf("%d",minflow);
	return 0;
}