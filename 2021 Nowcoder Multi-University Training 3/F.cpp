#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
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
const db eps = 1e-8;
int n, m;
vector<db> v;
vector<vector<db> > ans;

inline bool isInt(double value)
{
    int v = (int)value;
    return fabs(v - value) < eps ||
           fabs(v - value + 1) < eps ||
           fabs(v - value - 1) < eps;
}

inline bool equal(double a, double b)
{
    return fabs(a - b) < eps;
}
inline int rd(double x)
{
    return (int)(x + 0.5);
}

int check(vector<db> va, bool frac)
{
	if(sz(va) == 1)
	{
		if(equal(va[0], m))
		{
			if(frac) return 1;
			else return 2;
		}
		else return 0;
	}
	int flag = 0;
	rep0(i, sz(va) - 1)
	{
		vector<db> vi = va;
		double x = vi[i];
		vi.erase(vi.begin() + i);
		rep(j, i, sz(vi) - 1)
		{
			vector<db> v = vi;
			double y = vi[j];
			v.erase(v.begin() + j);
			int jdg;
			vector<db> vn;
			{
                vn = v;
                vn.pb(x + y);
                jdg = check(vn, frac);
                if (jdg == 2) return 2;
                if (jdg == 1) flag = 1;
            }
            {
                vn = v;
                vn.pb(x - y);
                jdg = check(vn, frac);
                if (jdg == 2) return 2;
                if (jdg == 1) flag = 1;
            }

            {
                vn = v;
                vn.pb(y - x);
                jdg = check(vn, frac);
                if (jdg == 2) return 2;
                if (jdg == 1) flag = 1;
            }
            
            {
                vn = v;
                vn.pb(x * y);
                jdg = check(vn, frac);
                if (jdg == 2) return 2;
                if (jdg == 1) flag = 1;
            }

            if (!equal(x, 0))
            {
                vn = v;
                vn.pb(y / x);
                jdg = check(vn, frac || !isInt(y / x));
                if (jdg == 2) return 2;
                if (jdg == 1) flag = 1;
            }

            if (!equal(y, 0))
            {
                vn = v;
                vn.pb(x / y);
                jdg = check(vn, frac || !isInt(x / y));
                if (jdg == 2) return 2;
                if (jdg == 1) flag = 1;
            }
		}
	}
	return flag;
}



int main()
{
	n = read();
	m = read();

	if (n == 1)
    {
        rep(i, 1, 13)
        {
            vector<double> v;
            v.pb(i);
            if (check(v, false) == 1)
                ans.pb(v);
        }
    }
    if (n == 2)
    {
        rep(i, 1, 13)
			rep(j, i, 13)
            {
                vector<double> v;
                v.pb(i); v.pb(j);
                if (check(v, false) == 1)
                    ans.pb(v);
            }
    }
    if (n == 3)
    {
        rep(i, 1, 13)
			rep(j, i, 13)
				rep(k, j, 13)
                {
                    vector<double> v;
                    v.pb(i); v.pb(j); v.pb(k);
                    if (check(v, false) == 1)
                        ans.pb(v);
                }
    }
    if(n == 4)
    {
		rep(i, 1, 13)
			rep(j, i, 13)
				rep(k, j, 13)
					rep(l, k, 13)
					{
	                        vector<double> v;
	                        v.pb(i); v.pb(j); v.pb(k); v.pb(l);
	                        if (check(v, false) == 1) ans.pb(v);
	               }
	}
                    
	printf("%d\n", sz(ans));

	for(auto x : ans)
	{
		rep0(i, n)
        	printf("%d ", rd(x[i]));
        puts("");
	}
	return 0;
}