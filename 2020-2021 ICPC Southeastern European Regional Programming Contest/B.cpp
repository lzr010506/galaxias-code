#include <bits/stdc++.h>
#define ll long long
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
using namespace std;
char s[1000010];
int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	ll sum = 0, num = 0;
	rrep(i, len, 1)
		if(s[i] == '1') sum += (len - num - i), num ++;
	if(sum % 3) puts("Alice");
	else puts("Bob");
	return 0;
}