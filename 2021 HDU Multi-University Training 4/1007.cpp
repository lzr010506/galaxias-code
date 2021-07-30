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
using namespace std;
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int readint() {
	char c, _c; int x; for (c = readChar(); !isdigit(c); c = readChar());
	for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
	if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
	for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
const int MaxN = 200010;
const int infty = (1<<30)-1;
const int Mod = 998244353;
int n; // though alone, still necessary
struct Node{
	int a, id, l, r, dp;
	Node(){ dp = 0; }
	bool operator < (const Node &t) const {
		return id < t.id; // 按照下标排序
	}
};
Node node[MaxN];
class BIT{
	int c[MaxN];
public:
	void modify(int x,int v){
		for(int i=x; i<=n; i+=(i&-i))
			c[i] = (c[i]+v)%Mod;
	}
	int query(int x){
		int res = 0;
		for(int i=x; i; i-=(i&-i))
			res = (res+c[i])%Mod;
		return res;
	}
	void clear(int x){
		for(int i=x; i<=n; i+=(i&-i))
			c[i] = 0;
	}
};
BIT xyx;

vector< int > sta;
void getInfo(int l,int r){
	sort(node+l,node+r+1);
	sta.clear(); // good habit
	sta.push_back(0); // be bottom
	for(int i=l; i<=r; ++i){
		while(!sta.empty() &&
		node[sta.back()].a > node[i].a)
			sta.pop_back();
		node[i].l = node[sta.back()].id;
		sta.push_back(i);
	}
	sta.clear(); // essential
	sta.push_back(n+1); // be bottom
	for(int i=r; i>=l; --i){
		while(!sta.empty() &&
		node[i].a > node[sta.back()].a)
			sta.pop_back();
		node[i].r = node[sta.back()].id;
		sta.push_back(i);
	}
}
bool cmp(const Node &x,const Node &y){
	return x.l < y.l; // 按照 l 排序
}
bool cdq(const Node &x,const Node &y){
	return x.a < y.a; // 按照 a 值排序
}
void solve(int l,int r){
	if(l == r) return ; // nothing to do
	int m = (l+r)>>1;
	solve(l,m); // 中序遍历
	getInfo(l,m), getInfo(m+1,r);
	sort(node+m+1,node+r+1,cmp);
	sort(node+l,node+m+1); // 下标排序
	for(int i=r,j=m; i>m; --i){
		int zxy = node[i].l;
		while(j >= l && zxy < node[j].id){
			int x = node[j].dp; // 加入
			xyx.modify(node[j].r,Mod-x);
			xyx.modify(node[j].id+1,x);
			-- j; // 非常重要！
		}
		node[i].dp += xyx.query(node[i].id);
		node[i].dp %= Mod; // 小心点！
	}
	for(int i=l; i<=m; ++i){
		xyx.clear(node[i].r);
		xyx.clear(node[i].id+1);
	}
	sort(node+m+1,node+r+1,cdq);
	solve(m+1,r); // 继续递归右边
}

int main(){
	int T = readint();
	while(T --)	
	{

		n = readint();
		for(int i=1,now=n+1; i<=n; ++i){
			node[i].dp = 0;
			node[i].id = i;
			node[i].a = readint();
			if(node[i].a < now){
				node[i].dp = 1;
				now = node[i].a;
			}
		}
		node[0].id = node[0].a = 0;
		node[n+1].id = node[n+1].a = n+1;
		sort(node+1,node+n+1,cdq);
		solve(1,n); // 两个边界都是实点
		sort(node+1,node+n+1); // 还原成原序列！
		int ans = 0; // sy orz. xyx orz.
		for(int i=n,now=0; i; --i)
			if(node[i].a > now){
				ans = (node[i].dp+ans)%Mod;
				now = node[i].a;
			}
		printf("%d\n",ans);
	}
	return 0;
}
