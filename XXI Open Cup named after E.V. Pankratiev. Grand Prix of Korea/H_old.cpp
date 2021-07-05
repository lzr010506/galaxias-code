#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
using namespace std;
const int N = 1e5 + 10;
int n, a[N];
ll b[N];
bool check(ll x)
{
	ll sum = 0, nw = 0, ss = 1;
	rep0(i, n)
		if(i >= x) sum += a[i];
	rep0(i, n + 1) b[i] = 0;
	b[0] = sum;
	b[0] += a[0];
	b[0] += a[1];
	rep(i, 2, min(n - 1, (int)	x - 1)) b[i - 1] = a[i];
	
	x --;
	cout << x << endl;
	 rep0(i, n) cout << b[i] << " ";
	 cout << endl; 
	// if(x <= 5) 
	// {
	// 	cout << x << endl;
	// 	rep0(i, n) printf("%d ", b[i]);
	// 	puts("");
	// }
	if (x - n > 70) return 0 ;

	ll c = 1 , s = 0 ;
	rep (i , 0 , n) s += b[i] ;

	for (; c <= s ;) {
		if (b[x] >= c) return 1 ;
		c -= b[x] ; c <<= 1 ;
		x --;
	}

	return 0 ;
}

int main()
{
	scanf("%d", &n);
	ll pp = 0;
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

	ll l = 0, r = 1e14, ans = 0;
	while(l <= r)
	{
		ll mid = l + r >> 1;
		if(check(mid)) 
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	cout << ans << endl;
	return 0;
}