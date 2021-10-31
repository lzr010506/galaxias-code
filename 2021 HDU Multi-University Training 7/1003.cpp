#include<bits/stdc++.h>
#define eps 1e-10
using namespace std;

double qpow(double x, int y) {
    double res = 1;
    while(y) {
        if(y&1) res=res*x;
        y>>=1;
        x=x*x;
    }
    return res;
}

int  main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        scanf("%d",&n);
        n--;
        double x1,y1,x2,y2,x3,y3;
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        double d = fabs(x1-x2);
        double h = fabs(y1-y2);
        printf("%.3lf\n",d*h*(4*n-6)+d*h*3*qpow(0.5, n-1));
    }
} 