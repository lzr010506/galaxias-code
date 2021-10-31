#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main() {
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        scanf("%lld%lld",&n,&k);
        if(n-k>=2) printf("No\n");
        else printf("Yes\n");
    }
} 