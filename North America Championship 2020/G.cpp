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
const int mod = 998244353;
const int N = 2e5 + 10;
int n, p, q, s;
int x[N], y[N];

struct inter
{
	int l, r;
	int id;

	friend bool operator <(inter a , inter b) {
		if (a.r == b.r) return a.id < b.id ;
		return a.r > b.r ;
	}
}a[N];

bool cmp(inter a, inter b)
{
	return a.l < b.l;
}

bool check(int D)
{
	rep(i, 1, p)
	{
		int r1 = upper_bound(y + 1, y + q + 1, x[i] + D) - y - 1;
		int r2 = upper_bound(y + 1, y + q + 1, s - x[i]) - y - 1;
		int l = lower_bound(y + 1, y + q + 1, x[i] - D) - y;
		a[i].l = l;
		a[i].r = min(r1, r2);
		a[i].id = i;
	}
	sort(a + 1, a + p + 1, cmp);
	int l = 1, ans = 0;
	priority_queue<inter> Q;
	rep(i, 1, q)
	{
		while(l <= p && a[l].l <= i) Q.push(a[l ++]);
		while(!Q.empty())
		{
			inter nw = Q.top();
			Q.pop();
			if(nw.r >= i)
			{
				ans ++;
				break;
			}
		}
	}
	return ans >= n;
}

int main()
{
	n = read();
	p = read();
	q = read();
	s = read();
	rep(i, 1, p) x[i] = read();
	rep(i, 1, q) y[i] = read();
	sort(y + 1, y + q + 1);
	int l = 0, r = s + 1, ans = r;
	while(l <= r)
	{
		int mid = l + r >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	if(ans == s + 1) ans = -1;
	printf("%d\n", ans);

	return 0;
}