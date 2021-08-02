#include<bits/stdc++.h>
#define maxn 200005
#define int long long
using namespace std;

int a[maxn];

signed main() {
	int n, m;
	int k;
	cin >> n >> m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	while(m--) {
		scanf("%lld",&k);
		deque<int>maxx,minn;
		int tmpma = 0, tmpmi = 0;
		int ans=0;
		int l=1;
		
		
		for(int i=1; i<=n; i++) {
			
			while(!maxx.empty() && a[maxx.back()]<a[i]) maxx.pop_back();
			maxx.push_back(i);
			while(!minn.empty() && a[minn.back()]>a[i]) minn.pop_back();
			minn.push_back(i);
			
			
			
			
			while(!minn.empty() && !maxx.empty() && a[maxx.front()]-a[minn.front()]>k) {
				
				if(maxx.front() == l) maxx.pop_front();
				if(minn.front() == l) minn.pop_front();
				l++;
			}
			ans += l-1;
		}
		cout<<ans<<endl;
	}
} 