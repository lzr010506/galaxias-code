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
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
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
inline ll read1() {
	char c; ll x; for (c = readChar(); !isdigit(c); c = readChar());
	for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
const int MAXN = 1010;
const int MAXM = 2e5 + 10;
typedef pair<int, int> P;
int t;
int n, m, x, y, fore, rear, cnt, ans, father[MAXN], f[MAXN], path[MAXN], tra[MAXN], que[MAXN], match[MAXN];
bool a[MAXN][MAXN], check[MAXN], treec[MAXN], pathc[MAXN];
inline void push(int x)
{
	que[++ rear] = x;
	check[x] = true;
	if (!treec[x])
	{
		tra[++ cnt] = x;
		treec[x] = true;
	}
}
 
int find(int x) 
{
	if(f[x]) return f[x] = find(f[x]);
	return x;
}
 
void clear()
{
	rep(i, 1, cnt)
	{
		int j = tra[i];
		check[j] = treec[j] = false;
		father[j] = 0, f[j] = 0;
	}
}
 
int lca(int u, int v)
{
	int len = 0;
	for (; u; u = father[match[u]])
	{
		u = find(u);
		path[++ len] = u;
		pathc[u] = true;
	}
	for (;; v = father[match[v]])
	{
		v = find(v);
		if (pathc[v]) break;
	}
	rep(i, 1, len) pathc[path[i]] = false;
	return v;
}
 
void reset(int u, int p)
{
	for (int v; find(u) != p;)
	{
		if (!check[v = match[u]]) push(v);
		if (f[u] == 0) f[u] = p;
		if (f[v] == 0) f[v] = p;
		u = father[v];
		if (find(u) != p) father[u] = v;
	}
}
 
void flower(int u, int v)
{
	int p = lca(u, v);
	if (find(u) != p) father[u] = v;
	if (find(v) != p) father[v] = u;
	reset(u, p), reset(v, p);
}
 
bool Find(int x)
{
	fore = rear = cnt = 0, push(x);
	while (fore++ < rear)
	{
		int i = que[fore];
		rep(j, 1, n)
		{
			if (a[i][j] && find(i) != find(j) && match[j] != i)
				if (match[j] && father[match[j]])
					flower(i, j);
				else if (father[j] == 0)
				{
					father[j] = i;
					tra[++cnt] = j;
					treec[j] = true;
					if (match[j])
						push(match[j]);
					else
					{
						for (int k = i, l = j, p; k; l = p, k = father[l])
						{
							p = match[k];
							match[k] = l;
							match[l] = k;
						}
						return true;
					}
				}
		}
	}
	return false;
}
 
void matching()
{
    rep(i, 1, n) father[i] = f[i] = path[i] = tra[i] = que[i] = match[i] = check[i] = treec[i] = pathc[i] = 0;
    ans = 0;
    rep(i, 1, n)
        if (match[i] == 0)
        {
            if (Find(i)) ans ++;
            clear();
        }
}

 
vi G[MAXN], rG[MAXN], vs;
bool used[MAXN];
int cmp[MAXN];
int u[MAXM], v[MAXM];
void add_edge(int u, int v)
{
	G[u].pb(v);
	rG[v].pb(u);
}
void erase_edge(int u, int v)
{
	rep0(i, sz(G[u])) if (G[u][i] == v) {G[u].erase(G[u].begin() + i); break;}
    rep0(i, sz(rG[v])) if (rG[v][i] == u) {rG[v].erase(rG[v].begin() + i); break;}
}
void dfs(int v)
{
	used[v] = true;
	for(auto to : G[v])
		if (!used[to]) dfs(to);
	vs.pb(v);
}
void rdfs(int v, int k)
{
	used[v] = true;
	cmp[v] = k;
	for(auto to : rG[v])
		if (!used[to]) rdfs(to, k);
}
int scc()
{
	memset(used, 0, sizeof(used));
	vs.clear();
	rep(v, 1, 2 * n) if (!used[v]) dfs(v);
	int k = 0;
	memset(used, 0, sizeof(used));
 
	for (int i = vs.size() - 1; i >= 0; i--) if (!used[vs[i]]) rdfs(vs[i], k++);
	return k;
}
 
int main()
{
	int T = read();
	while (T --)
	{
		n = read();
		m = read();
		rep(i, 1, 2 * n) G[i].clear(), rG[i].clear();
		rep(i, 1, n)
			rep(j, 1, n)
				a[i][j] = (i == j ? true : false);
		rep0(i, m)
		{
			u[i] = read();
			v[i] = read();
			a[u[i]][v[i]] = a[v[i]][u[i]] = true;
		}
		matching();
		rep0(i, m)
        {
            add_edge(n + u[i], v[i]);
            add_edge(n + v[i], u[i]);
            if (match[u[i]] == v[i])
            {
                add_edge(u[i], n + v[i]);
                add_edge(v[i], n + u[i]);
            }
        }
		rep(i, 1, n) if (match[i] == 0) add_edge(i, n + i);
		scc();
		bool f = true;
		rep(i, 1, n) if (cmp[i] == cmp[n + i]) f = false;
		if (f)
		{
			printf("%d\n", ans);
			rep(i, 1, n) if (cmp[i] > cmp[n + i]) printf("%d ", i);
			puts("");
			continue;
		}
 
		bool flag = false;
		rep0(i, m)
		{
	        if (match[u[i]] != v[i]) continue;
	        erase_edge(u[i], n + v[i]);
	        erase_edge(v[i], n + u[i]);
	        add_edge(n + u[i], u[i]);
	        add_edge(n + v[i], v[i]);
	        scc();
	        bool f = true;
	        for (int j = 1; j <= n; j++) if (cmp[j] == cmp[n + j]) f = false;
	        if (f)
	        {
	            printf("%d\n", ans + 1);
	            for (int j = 1; j <= n; j++) if (cmp[j] > cmp[n + j]) printf("%d ", j);
	            puts("");
	            flag = true; break;
	        }
	        erase_edge(n + u[i], u[i]);
	        erase_edge(n + v[i], v[i]);
	        add_edge(u[i], n + v[i]);
	        add_edge(v[i], n + u[i]);
	    }
	    if (flag) continue;
	    rep(i, 1, n)
	    {
	        if (match[i]) continue;
	        erase_edge(i, n + i);
	        add_edge(n + i, i);
	        scc();
	        bool f = true;
	        rep(j, 1, n) if (cmp[j] == cmp[n + j]) f = false;
	        if (f)
	        {
	            printf("%d\n", ans + 1);
	            rep(j, 1, n) if (cmp[j] > cmp[n + j]) printf("%d ", j);
	            puts("");
	            flag = true; break;
	        }
	        erase_edge(n + i, i);
	        add_edge(i, n + i);
	    }
	    if (flag) continue;
	    puts("not smol");
	}
	return 0;
}