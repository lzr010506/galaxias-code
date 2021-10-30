#include <iostream>
#define maxn 3005
#define int long long
#define mod 1000000007
using namespace std;

int dp[maxn][maxn];
int minn[maxn][maxn];
int a[maxn];
int vis[maxn];
int pos[maxn];

signed main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        pos[a[i]] = i;
    }
    for(int i=1;i<=n;i++) minn[i][i] = a[i];

    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            minn[i][j] = min(minn[i][j-1], a[j]);
        }
        
        
    }

    for(int i=1;i<=a[1];i++) {
        if(minn[1][pos[i]] == i) dp[1][i] = 1;
    }

 	
 	for(int i=2;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(dp[i-1][j] != 0) {
                for(int k=1;k<=n;k++) {
                    

                    if(pos[j]<=i && pos[k] >= i && minn[i][pos[k]] == k) {
                        dp[i][k] += dp[i - 1][j];
if(dp[i][k]>=mod) dp[i][k] -= mod;
                          continue;
                      
                    }
                    
                    if(pos[j]<=i && pos[k] <= i && minn[pos[k]][i] == k) {
                        int tmp = min(pos[j], pos[k]);
                        if(minn[tmp][i-1] == j) {
                            dp[i][k] += dp[i - 1][j];
                            if(dp[i][k]>=mod) dp[i][k] -= mod;
                             continue;
                        }
                       
                    }
                    
                    if(pos[j]>=i && pos[k] >= i && minn[i-1][pos[j]] == j) {
                        int tmp = max(pos[j], pos[k]);
                        if(minn[i][tmp] == k) {
                            dp[i][k] += dp[i - 1][j];
if(dp[i][k]>=mod) dp[i][k] -= mod;
                             continue;
                        }
                       
                    }
                    

                    
                }
                
                
                
            }
        }
 	}
 	
    int ans = 0;
    for(int i=1;i<=n;i++) {
    	ans += dp[n][i];
    	ans %= mod;
    }

    cout << ans << endl;

}
