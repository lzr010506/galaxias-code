#include <bits/stdc++.h>

#define db double

const db pi = acos(-1) ;

int T ;
db R1 , X1 , Y1 , R2 , X2 , Y2 , a ;

//////////////////

typedef struct node
{
    db x; db y;
}point;
 
double AREA(point a, double r1, point b, double r2)
{
    double d = sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
    if (d >= r1+r2)
        return 0;
    if (r1>r2)
    {
        double tmp = r1;
        r1 = r2;
        r2 = tmp;
    }
    if(r2 - r1 >= d)
        return pi*r1*r1;
    double ang1=acos((r1*r1+d*d-r2*r2)/(2*r1*d));
    double ang2=acos((r2*r2+d*d-r1*r1)/(2*r2*d));
    return ang1*r1*r1 + ang2*r2*r2 - r1*d*sin(ang1);
}

//////////////////

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%lf %lf %lf %lf %lf %lf %lf" , &R1 , &X1 , &Y1 , &R2 , &X2 , &Y2 , &a) ;
        a /= 2.0 ;

        if (a > R2) {printf("%0.6lf\n" , (double)0) ; continue ;}

        R1 = sqrt(R1 * R1 - a * a) - a ; R2 = sqrt(R2 * R2 - a * a) - a ;

        db area = AREA((point){X1 , Y1} , R1 , (point){X2 , Y2} , R2) ;

        printf("%0.6f\n" , area / (pi * R1 * R1)) ;
    }

    return 0 ;
}