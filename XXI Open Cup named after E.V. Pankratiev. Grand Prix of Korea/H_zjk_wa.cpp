#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
using namespace std;
const int N = 1e6 + 10;
int n, a[N];
ll b[N], sum, pp;
bool check(ll x)
{
	b[0] += pp - sum;
	b[0] += a[0];
	x -= 2;
	 // cout << x << endl;
	 // rep0(i, n) cout << b[i] << " ";
	 // cout << endl;
	if (x - n > 70) return 0 ;

	ll c = 2 ;

	for (; c <= pp ;) {
		if (b[x] >= c) 
		{
			b[0] -= pp - sum;
			b[0] -= a[0];
			return 1 ;
		}
		c -= b[x] ; c <<= 1 ;
		x --;
	}
	b[0] -= a[0];
	b[0] -= pp - sum;
	return 0 ;
}

int main()
{
	scanf("%d", &n);
	pp = 0;
	rep0(i, n)
	{
		scanf("%d", &a[i]);
		pp += a[i];
	}
	if(pp == 1)
	{
		if(a[0] == 1) cout << 1 << endl;
		else rep0(i, n) if(a[i] == 1) cout << i << endl;
		return 0;
	}
	sum = 0;
	rep(i, 1, n - 1) b[i - 1] = a[i];
	sum += a[0];
	rep(i, 2, 1000000)
	{
		sum += a[i - 1];
		if(check(i) == 0) 
		{
			cout << i - 1 << endl;
			return 0;
		}
	}
	return 0;
} 