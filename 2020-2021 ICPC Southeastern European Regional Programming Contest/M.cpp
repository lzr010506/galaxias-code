#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
using namespace std;
int a[500010];
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 1; i <= m; i ++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
	}

	for(int i = 1; i <= n * k; i ++)
	{
		int x;
		scanf("%d", &x);
		a[x] ++;
		printf("%d ", a[x]);
	}

	return 0;
}