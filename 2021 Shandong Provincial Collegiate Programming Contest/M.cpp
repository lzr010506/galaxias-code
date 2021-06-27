#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
} 
char ch[510][510];
char a[510][510], b[510][510];
int main()
{
	int n, m;
	n = read();
	m = read();
	rep(i, 1, n)
		scanf("%s", ch[i] + 1);
	rep(i, 1, n)
	{
		if(i == 1) 
		{
			rep(j, 1, m) a[i][j] = '1';
			continue; 
		}
		if(i == n)
		{
			rep(j, 1, m) b[i][j] = '1';
			continue;
		}
		rep(j, 1, m)
		{
			if(ch[i][j] == '1') a[i][j] = b[i][j] = '1';
			else if(j & 1) a[i][j] = '1';
			else b[i][j] = '1';
		}
	}
	rep(i, 1, n)
	{
		rep(j, 1, m)
		{
			if(a[i][j] == '1') putchar('1');
			else putchar('0');
		}
		puts("");
	}
	rep(i, 1, n)
	{
		rep(j, 1, m)
		{
			if(b[i][j] == '1') putchar('1');
			else putchar('0');
		}
		puts("");
	}
	return 0;
}
