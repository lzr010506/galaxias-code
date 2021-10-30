#include<bits/stdc++.h>
#define maxn 4000010
using namespace std;

char ma[maxn*2];
int mp[maxn*2];
char s[maxn];
int len;
void manacher(char s[]) {
	int l=0;
	ma[l++]='$';
	ma[l++]='#';
	for(int i=0; i<len; i++) {
		ma[l++]=s[i];
		ma[l++]='#';
	}
	ma[l]=0;
	int mx=0,id=0;
	for(int i=0; i<l; i++) {
		mp[i]=mx>i?min(mp[2*id-i],mx-i):1;
		while(ma[i+mp[i]]==ma[i-mp[i]])mp[i]++;
		if(i+mp[i]>mx) {
			mx=i+mp[i];
			id=i;
		}
	}
	len = l;

}

int main() {
	scanf("%s",s);
	len = strlen(s);
	manacher(s);
	int l = 1;
	int r = len-1;
	for(int i=l+2;i<len;i+=2) {
		if(i-mp[i]+1<=l) {
			l = i;
		}
	}
	
	for(int i=len-3;i>l;i-=2) {
		if(i+mp[i]-1>=r) {
			r = i;
		}
	}
	
	cout << (r-l)/2 << endl;
}