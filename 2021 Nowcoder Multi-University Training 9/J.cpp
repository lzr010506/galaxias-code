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

int c[16];
set<int> bad[16];
vector<int> v;

int main()
{
	bad[1].insert(7); bad[1].insert(6); bad[1].insert(8); bad[1].insert(12);
	bad[2].insert(7); bad[2].insert(11); bad[2].insert(12); bad[2].insert(13);
	bad[6].insert(8); bad[6].insert(11); bad[6].insert(1); bad[6].insert(13);
	bad[7].insert(2); bad[7].insert(1); bad[7].insert(12); bad[7].insert(8);
	bad[8].insert(1); bad[8].insert(13); bad[8].insert(6); bad[8].insert(7);
	bad[11].insert(13); bad[11].insert(12); bad[11].insert(6); bad[11].insert(2);
	bad[12].insert(2); bad[12].insert(7); bad[12].insert(11); bad[12].insert(1);
	bad[13].insert(2); bad[13].insert(6); bad[13].insert(8); bad[13].insert(11);
	v.push_back(1); v.push_back(2); v.push_back(6); v.push_back(7);
	v.push_back(8); v.push_back(11); v.push_back(12); v.push_back(13);
	int T = read();
	while(T --)
	{
		int cnt = 0;
		rep0(i, 4)
			rep0(j, 4)
				c[cnt ++] = read();
		int ans = 0;
		rep0(i, 16) ans = max(ans, c[i]);
		for (auto x : v)
			for (auto to : bad[x])
				ans = max(ans, c[x] + c[to]);
		for (auto x : v)
			for (auto to : bad[x])
				for (auto tto : bad[to])
					if (tto != x && bad[x].count(tto)) ans = max(ans, c[x] + c[to] + c[tto]);
		int sum = 0;
		for (auto x : v) sum += c[x];
		ans = max(ans, (sum + 1) / 2);
		printf("%d\n", ans);
	
	}
}
