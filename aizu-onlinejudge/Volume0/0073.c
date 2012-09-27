/* AOJ 0073
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0073
 *
 */

#include <stdio.h>

#include <math.h>


double heron(double a, double b, double c){
    double s;
    s = (a + b + c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}


int main(){
    int x;
    int h;
    double d;
    double S;

    while(scanf("%d", &x)==1){
        scanf("%d", &h);
        if(x==0 && h == 0)
            break;
        d = sqrt(x*x/2.0 + h*h);
        S = x*x + 4 * heron(d, d, x);
        printf("%f\n", S);
    }


    return 0;
}
