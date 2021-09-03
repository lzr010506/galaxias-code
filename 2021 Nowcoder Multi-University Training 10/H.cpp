#include<bits/stdc++.h>
#define maxn 5000005
using namespace std;
int ans[maxn];
int main() {
	int n;
	cin >> n;
	int in = 1;
	for(in=1;in*in<=n;in++) {
		
	}
	
	for(int i=0;i<(1<<n);i++) {

		
		for(int j=0;j<n;j++) {
			int tmp = i^(1<<j);
			if(j%in == 0) {
				ans[tmp] = ans[i];
			}else ans[tmp] = ans[i]^1;
		}
	}
	
	for(int i=0;i<(1<<n);i++) printf("%d",ans[i]);
	printf("\n");
} 