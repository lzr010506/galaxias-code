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
#define int long long
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int mod = 1e9 + 7;
int qpow(int x, int times)
{
	int res = 1;
	while(times)
	{
		if(times & 1) res = 1LL * res * x % mod;
		x = 1LL * x * x % mod;
		times >>= 1;
	}
	return res;
}

int pf(int n)
{
	return n * (n + 1) % mod * (2 * n + 1) % mod * qpow(6, mod - 2) ;
}

int lf(int n)
{
	int x = n * (n + 1) % mod * qpow(2, mod - 2) % mod;
	return x * x % mod; 
}

signed main()
{
	int T = read();
	while(T --)
	{
		int n = read1();
		n --;
		n %= mod;
		cout << 8 * lf(n) % mod << endl ;
	}

	return 0;
}
//n * n * (n * n - 1) * 6 - 12
