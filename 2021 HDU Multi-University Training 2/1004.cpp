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
const int N = 1e5 + 10;
int n, q, L[N], R[N], A[N], B[N], c[N], ans[N], la[N];
vector<int> v[262144], vq[N];

int get(int k, int l)
{
	int o = -1;
	rrep(i, 16, 0)
    {
        int O = o + (1 << i);
        if(O < sz(v[k]) && v[k][O] <= l) o = O;
    }
    return (int)sz(v[k]) - 1 - o;
}
void sol(int rt)
{
    int k = 1;
    rrep(i, 16, 0)
    {
    	k = (k << 1) | (((A[rt] ^ B[rt]) >> i) & 1);
    	if(B[rt] & (1 << i)) ans[rt] += get(k ^ 1, L[rt] - 1);
    }
}

int main()
{
	n = read();
	rep(i, 1, n) c[i] = read();
	q = read();
	rep(i, 1, q)
	{
		L[i] = read();
		R[i] = read();
		A[i] = read();
		B[i] = read();
        B[i] ++;
        vq[R[i]].pb(i); 
    }

    rep(i, 1, n)
    {

      //  cout << i << endl;
        if(la[c[i]])
        {
            int k = 1;
            rrep(j, 16, 0)
            {
                k = (k << 1) | ((c[i] >> j) & 1);
                int tot = sz(v[k]) - get(k, la[c[i]]) - 1;
                rep(t, tot, sz(v[k]) - 2) v[k][t] = v[k][t + 1];
                v[k][v[k].size() - 1] = i;
            }
        }
        else
        {
            int k = 1;
            rrep(j, 16, 0)
            {
                k = (k << 1) | ((c[i] >> j) & 1);
                v[k].pb(i);
            }
        }
        la[c[i]] = i;
        rep0(j, sz(vq[i])) sol(vq[i][j]);
    }
    rep(i, 1, q) printf("%d\n", ans[i]);

	return 0;
}