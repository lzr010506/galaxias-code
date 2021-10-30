#include<bits/stdc++.h>
#define ld long double
using namespace std;

const int N = 22;
const int M = (1 << N) + 5;
int n;
int a[N];
ld b[N], c[N];
ld dp[M];

ld solve(int m) {
	if (b[m - 1] <= c[m - 1]) return b[m - 1];
	ld sumP = 0;
	ld sumDer = 1. / (b[m - 1] - c[m - 1]);
	for (int i = m - 2; i >= 0; i--) {
		ld delta = b[i + 1] - b[i];
		ld z = sumDer * delta;
		if (sumP + z > 1) {
			return b[i + 1] - (1 - sumP) / sumDer;
		}
		sumP += z;
		if (b[i] <= c[i]) {
			return b[i];
		}
		sumDer += 1. / (b[i] - c[i]);
	}
	return b[0] - (1 - sumP) / sumDer;
}

int main() {

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int mask = 1; mask < (1 << n); mask++) {
		int m = 0;
		for (int i = 0; i < n; i++) {
			if (((mask >> i) & 1) == 0) continue;
			b[m] = a[i];
			c[m] = dp[mask ^ (1 << i)];
			assert(m == 0 || c[m] <= c[m - 1] + 1e-9);
			m++;
		}
		dp[mask] = solve(m);
	}
	printf("%.13lf\n", (double)dp[(1 << n) - 1]);

}