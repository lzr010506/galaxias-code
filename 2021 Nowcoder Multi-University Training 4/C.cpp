#include<bits/stdc++.h>
#define maxn 200005
#define INF 1e18
#define int long long
using namespace std;


vector<char> V[3],VV[3];
int a,b,c,n;



void print(int indexx) {
	for(int i=0; i<V[indexx].size(); i++) {
		printf("%c",V[indexx][i]);
	}
	int len1 = V[indexx].size();
	int len2 =  VV[indexx].size();
	for(int i=0; i<n-len1-len2; i++) printf("%c",'x'+indexx);
	for(int i=0; i<VV[indexx].size(); i++) {
		printf("%c",VV[indexx][i]);
	}
	printf("\n");
}
pair<int,int> xx[4];
signed main() {
	cin >> a >> b >> c >> n;
	xx[0].first = a,xx[1].first=b,xx[2].first=c;
	xx[0].second=0,xx[1].second=1,xx[2].second=2;
	int minn = min(a, min(b,c));
	for(int i=0; i<minn; i++) {
		V[0].push_back('a');
		V[1].push_back('a');
		V[2].push_back('a');
	}
	sort(xx,xx+3);
	int len = xx[1].first-minn+xx[2].first-minn;
	if(minn+len>n) {
		printf("NO\n");
		return 0;
	}
	for(int i=0; i<xx[1].first-minn; i++) VV[0].push_back('b');
	for(int i=0; i<xx[2].first-minn; i++) {
		VV[0].push_back('c');
	}
	for(int i=0; i<xx[2].first-minn; i++) {
		VV[2].push_back('c');
		VV[1].push_back('y');
	}
	for(int i=0; i<xx[1].first-minn; i++) {
		VV[1].push_back('b');
	}
//	reverse(VV[0].begin(),VV[0].end());
	reverse(VV[1].begin(),VV[1].end());
	reverse(VV[2].begin(),VV[2].end());
	
	int q,w,e;
	q=w=e=4;
	if(xx[1].second == 0 && xx[2].second == 1) w=0;
	else if(xx[1].second == 0 && xx[2].second == 2) q=0;
	else if(xx[1].second == 1 && xx[2].second == 2) e = 0;
	else if(xx[1].second == 1 && xx[2].second == 0) w=0;
	else if(xx[1].second == 2 && xx[2].second == 0) q=0;
	else if(xx[1].second == 2 && xx[2].second == 1) e = 0;
	
	if(xx[1].second == 0) {
		if(q == 4) q=1;
		else w=1;
	}
	else if(xx[1].second == 1) {
		if(w == 4) w=1;
		else e=1;
	}else if(xx[1].second == 2) {
		if(e == 4) e=1;
		else q=1;
	}
	
	if(q == 4) q=2;
	else if(w == 4) w=2;
	else e=2;
	
	
	print(q);
	print(w);
	print(e);
}