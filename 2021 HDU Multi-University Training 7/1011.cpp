#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
bitset<100010> dp;
struct Node
{
	int a, c;
}a[110], b[10100];
int main()
{
	while(true)
	{
		dp = 0;
		int n, m;
		scanf("%d%d",&n,&m);
		if(n == 0 && m == 0) break;
		int i;
		int cnt = 0;
		for(i=1; i<=n; i++) scanf("%d",&a[i].a);
		for(i=1; i<=n; i++) scanf("%d",&a[i].c);
		for(i=1; i<=n; i++)
		{
			int x = a[i].c;
			int f = 1;
			while(x)
			{
				if(x >= f) 
				{
					b[++cnt].a = a[i].a * f;
					x -= f;
					f *= 2;
				}
				else 
				{
					b[++cnt].a = a[i].a * x;
					break;
				}
			}
		}
		dp[0] = 1;
		for(i=1; i<=cnt; i++)
		{                                       
			dp |= (dp << b[i].a);
		}
		cnt = 0;
		for(i=1; i<=m; i++)
		{
			// cout << dp[i] << " ";
			if(dp[i] == 1) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}