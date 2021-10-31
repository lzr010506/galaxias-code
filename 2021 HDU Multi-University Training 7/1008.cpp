#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
const int dx[] = {0,1,-1,-1};
const int dy[] = {1,0,0,-1};

int curx, cury, curd;
void cal(int x, int y, int op, int xx, int yy) {
    while(x--) {
        printf("f");
    }
    if(op == 0) {
        printf("c");
        curd = (curd+1)%4;
    }

    else {
        printf("u");
        curd = (curd-1+4)%4;
    }
    while(y--) {
        printf("f");
    }
    curx = xx, cury = yy;
}

int main() {
//    freopen("in.txt","r",stdin);
    int T;
    cin >> T;
    while(T--) {
        int x,y,d;
        scanf("%d%d%d",&x,&y,&d);
        int n;
        scanf("%d",&n);
        curx = x, cury = y, curd = d;
        for(int i=1; i<=n; i++) {
            int x1,y1;
            scanf("%d%d",&x1,&y1);
            int dxx = abs(x1-curx);
            int dyy = abs(y1-cury);
            if(x1>curx && y1>cury) {
                if(curd == 0) {
                    cal(dyy,dxx,0,x1,y1);
                } else if(curd == 1) {
                    cal(dxx,dyy,1,x1,y1);
                } else if(curd == 2) {
                    printf("u");
                    curd = (curd-1+4)%4;
                    cal(dxx,dyy,1,x1,y1);
                } else {
                    printf("c");
                    curd = (curd+1)%4;
                    cal(dyy,dxx,0,x1,y1);
                }
            } else if(x1>curx && y1<cury) {
                if(curd == 0) {
                    printf("c");
                    curd = (curd+1)%4;
                    cal(dxx,dyy,0,x1,y1);
                } else if(curd == 1) {
                    cal(dxx,dyy,0,x1,y1);
                } else if(curd == 2) {
                    cal(dyy,dxx,1,x1,y1);
                } else {
                    printf("u");
                    curd = (curd-1+4)%4;
                    cal(dyy,dxx,1,x1,y1);
                }
            } else if(x1<curx && y1<cury) {
                if(curd == 0) {
                    printf("u");
                    curd = (curd-1+4)%4;

                    cal(dxx,dyy,1,x1,y1);
                } else if(curd == 1) {
                    printf("c");
                    curd = (curd+1)%4;
                    cal(dyy,dxx,0,x1,y1);
                } else if(curd == 2) {

                    cal(dyy,dxx,0,x1,y1);
                } else {
                    cal(dxx,dyy,1,x1,y1);
                }
            } else if(x1<curx && y1>cury) {
                if(curd == 0) {

                    cal(dyy,dxx,1,x1,y1);
                } else if(curd == 1) {
                    printf("u");
                    curd = (curd-1+4)%4;
                    cal(dyy,dxx,1,x1,y1);
                } else if(curd == 2) {
                    printf("c");
                    curd = (curd+1)%4;
                    cal(dxx,dyy,0,x1,y1);
                } else {
                    cal(dxx,dyy,0,x1,y1);
                }
            }
        }
        printf("\n");
    }
}