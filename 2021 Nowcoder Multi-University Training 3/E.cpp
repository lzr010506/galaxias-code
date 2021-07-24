#include<bits/stdc++.h>
#define maxn 200005
#define rep(i, x, y) for(int i = x; i <= y; i ++)
using namespace std;
 
int ans[maxn];
long long b[100][1000005];
 
struct ID
{
	int id;
	long long a;
}a[maxn];
bool cmp(ID a, ID b)
{
	return a.a < b.a;
}
map<int, int> M;
int main() {
    int T;
    cin >> T;
 
    for(int i=1; i<=T; i++) scanf("%lld",&a[i].a), a[i].id = i;
    int cnt =0;
    sort(a+1,a+1+T, cmp);
    rep(i, 1, T)
    	M[a[i].id] = i;
    for(int i=2;; i++) {
        if(1ll*i*i*i>1e18+10) break;
        b[1][i] = 1ll*i*i*i;
        b[0][i] = i;
        cnt = 1;
        int j=2;
        for(; (__int128)i*i*b[j-1][i]-(__int128)b[j-2][i]<=(__int128)1e18; j++) {
            b[j][i] = (long long)((__int128)i*i*b[j-1][i]-(__int128)b[j-2][i]);
 
            cnt++;
        }
        b[0][i] = cnt;
        //  cout << b[1][2] << endl;
    }
 
    for(int i=1;; i++) {
        cnt = 1;
        if(b[i][2] == 0) break;
        for(int j=2; cnt<=T && b[i][j]!=0; j++) {
            while(cnt<=T && b[i][j]>a[cnt].a) cnt++;
  
            ans[cnt]++;
        }
 
    }
    ans[1] += 1;
    for(int i=1; i<=T; i++) {
        ans[i] += ans[i - 1];
    }
    for(int i=1; i<=T; i++) {
        printf("%d\n",ans[M[i]]);
    }
}
/*
10

1919810

10

100

1000

10000

100000

114514

20190104

123123123123

1000000000000000000
*/