#include<bits/stdc++.h>
#define N 2100000
#define maxn 2100000
#define Pi atan2(0,-1)
#define eps 1e-4
#define complex Complex
#define comp Complex
using namespace std;
int n,k,m,L,len,rev[N],a[N],b[N],ans[N],c[N];
const double pi = acos(-1.0);
struct complex {
	double real, impl;
	complex(double r = 0.0, double i = 0.0) : real(r), impl(i) {}
	friend complex operator+(const complex &a, const complex &b) {
		return complex(a.real + b.real, a.impl + b.impl);
	}
	friend complex operator-(const complex &a, const complex &b) {
		return complex(a.real - b.real, a.impl - b.impl);
	}
	friend complex operator*(const complex &a, const complex &b) {
		return complex(a.real * b.real - a.impl * b.impl, a.impl * b.real + b.impl * a.real);
	}
	friend complex operator/(const complex &a, double b) {
		return complex(a.real / b, a.impl / b);
	}
} A[N], B[N], t[N];
using std::swap;
void FFT(complex* P, int len, int opt) {
	for (int i = 1, j = 0, k; i < len; ++i) {
		for (k = len >> 1; j & k; k >>= 1) j ^= k;
		j ^= k;
		if (i < j) swap(P[i], P[j]);
	}
	for (int h = 2; h <= len; h <<= 1) {
		complex wn = complex(cos(opt * 2 * pi / h), sin(opt * 2 * pi / h));
		for (int j = 0; j < len; j += h) {
			complex w = complex(1.0, .0);
			for (int t = 0; t < h / 2; ++t, w = w * wn) {
				complex tmp1 = P[t + j], tmp2 = P[t + j + h / 2];
				P[t + j] = tmp1 + tmp2 * w;
				P[t + j + h / 2] = tmp1 - tmp2 * w;
			}
		}
	}
	if (opt == -1)
		for (int i = 0; i < len; ++i)
			P[i] = P[i] / len;
}

void mul(int *c,int *a,int na,int *b,int nb) {
	for(len=1,L=0; len<=max(na,nb)*2; len<<=1,L++);
//	for(int i=0; i<len; i++)rev[i]=(rev[i>>1]>>1)|(i&1)<<(L-1);

	for(int i=0; i<len; i++)A[i]=(comp) {
		(double)a[i],0
	};
	for(int i=0; i<len; i++)B[i]=(comp) {
		(double)b[i],0
	};

	FFT(A,len,1);
	FFT(B,len,1);
	for(int i=0; i<len; i++)A[i]=A[i]*B[i];
	FFT(A,len,-1);

	for(int i=0; i<len; i++) {
		if(A[i].real-(int)A[i].real<eps) c[i] = (int) A[i].real;
		else c[i] = ceil(A[i].real);
	}
}


char s[maxn], tt[maxn];
int anss[maxn];
int main() {
	int n, m;
	cin >> n >> m;
	scanf("%s%s",s, tt);
	for(int i=0;i<n;i++) {
		if(s[i] == 'S') a[i] = 1;
		else a[i] = 0;
	}
	reverse(a,a+n);
	for(int i=0;i<m;i++) {
		if(tt[i] == 'R') b[i] = 1;
		else b[i] = 0;
	}
	mul(c, a, n, b, m);
	for(int i=0;i<n+m;i++) {
		anss[i] += c[i];
	}
	
	for(int i=0;i<n;i++) {
		if(s[i] == 'R') a[i] = 1;
		else a[i] = 0;
	}
	reverse(a,a+n);
	for(int i=0;i<m;i++) {
		if(tt[i] == 'P') b[i] = 1;
		else b[i] = 0;
	}
	mul(c, a, n, b, m);
	for(int i=0;i<n+m;i++) {
		anss[i] += c[i];
	}
	
	for(int i=0;i<n;i++) {
		if(s[i] == 'P') a[i] = 1;
		else a[i] = 0;
	}
	reverse(a,a+n);
	for(int i=0;i<m;i++) {
		if(tt[i] == 'S') b[i] = 1;
		else b[i] = 0;
	}
	mul(c, a, n, b, m);
	for(int i=0;i<n+m;i++) {
		anss[i] += c[i];
	}
	int xxxxx = 0;
	for(int i=0;i<=n-1;i++) {
		xxxxx = max(xxxxx, anss[i]);
	}
	cout << xxxxx << endl;
	return 0;
}