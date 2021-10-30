#include<bits/stdc++.h>
#define int long long
using namespace std;


const int d[] = {2,-1,1,-2};

signed main() {
	int n;
	cin >> n;
	if(n == 2) {
		printf("-1\n");
		return 0;
	}
	int cnt = 0;
	while((1ll<<cnt)<n) cnt++;
	if(n%2 == 1) {
		printf("%lld\n",cnt);
		for(int i=0; i<cnt; i++) {
			for(int j=1; j<=n; j++) {
				int tmp = (j+(1ll<<i))%n;
				if(tmp == 0) tmp += n;
				if(j == 1) printf("%lld",tmp);
				else printf(" %lld",tmp);
			}
			printf("\n");
		}
	} else {
		printf("%lld\n",cnt+1);
		if(n%4 == 0) {
			for(int i=1; i<=n; i++) {
				int tmp = i-1;
				tmp %= 4;
				if(i == 1) printf("%lld",d[tmp]+i);
				else printf(" %lld",d[tmp]+i);
			}
			printf("\n");
			for(int i=0; i<cnt; i++) {
				for(int j=1; j<=n; j++) {
					int tmp = (j+(1ll<<i))%n;
					if(tmp == 0) tmp += n;
					if(j == 1) printf("%lld",tmp);
					else printf(" %lld",tmp);
				}
				printf("\n");
			}
		} else {
			for(int i=1; i<=n-2; i++) {
				int tmp = i-1;
				tmp %= 4;
				if(i == 1) printf("%lld",d[tmp]+i);
				else printf(" %lld",d[tmp]+i);
			}
			printf(" %lld %lld",n-1,n);
			printf("\n");

			printf("1 2") ;
			for (int i = 3 ; i <= n ; ++i) {
				int tmp = (i - 3) % 4 ;
				printf(" %lld" , d[tmp] + i) ;
			}
			printf("\n") ;
			
			for(int i=0; i<cnt-1; i++) {
				for(int j=1; j<=n; j++) {
					int tmp = (j+(1ll<<i))%n;
					if(tmp == 0) tmp += n;
					if(j == 1) printf("%lld",tmp);
					else printf(" %lld",tmp);
				}
				printf("\n");
			}
		}

	}

}