#include<bits/stdc++.h>
using namespace std;
int dp[10][5]; // 到第i位前一位（不）为6的个数
int a[10];
int dfs(int i, int j, bool limit)
{
    if(i == 0) return 1;
    if(dp[i][j] != -1 && limit == false) return dp[i][j];
    int up;
    if(limit == true) up = a[i];
    else up = 9;
    int ii;
    int ans = 0;
    for(ii=0; ii<=up; ii++)
    {
        if(j == 1 && ii == 2) continue;
        if(ii == 4) continue;
        ans += dfs(i-1, ((ii==6) ? 1:0), (a[i]==ii && limit));
    }
    if(!limit) dp[i][j] = ans;
    return ans;
}
int solve(int x)
{
    int pos = 0;
    int xx = x;
    while(xx)
    {
        a[++pos] = xx % 10;
        xx /= 10;
    }
    return dfs(pos, 0, true);
}
int main()
{
    while(true)
    {
        int x, y;
        scanf("%d%d",&x,&y);
        if(x == 0 && y == 0) break; 
        memset(dp, -1, sizeof(dp));
    // cout << "`1" << endl;
        printf("%d\n", solve(y) - solve(x - 1));
    }
    return 0;
}
