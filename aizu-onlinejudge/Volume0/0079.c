/* AOJ 0079
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0079
 *
 */

#include <stdio.h>
#include <math.h>

typedef struct TPoint Point;
struct TPoint {
    double fX;
    double fY;
};

Point V[20];

double heron(double a, double b, double c){
    double z;
    z = (a+b+c)/2;
    return sqrt(z*(z-a)*(z-b)*(z-c));
}

double distance(Point a, Point b){
    return sqrt((a.fX-b.fX)*(a.fX-b.fX)+(a.fY-b.fY)*(a.fY-b.fY));
}

int main(){
    float x, y;
    int i, n;
    double S;

    n = 0;
    while(scanf("%f,%f", &x, &y)==2){
        V[n].fX = x;
        V[n].fY = y;
        n++;
    }

    S = 0.0;
    for(i=1; i<n-1;i++){
        S += heron(
                distance(V[0], V[i]),
                distance(V[0], V[i+1]),
                distance(V[i], V[i+1]));
    }
    printf("%f\n",S);

    return 0;
}
