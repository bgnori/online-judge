/* AOJ 0080
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0080
 *
 */

#include <stdio.h>
#include <math.h>


#define DEBUG 0


double f(double x, double q){
    return x - ((x*x*x - q)/(3*x*x));
}

double solve(double q){
    double x;
    x = q/2.0;

    if(DEBUG){
        printf("--x=%f, q=%f\n",x,q);
    }

    while(!(fabsl(x*x*x - q) < (0.00001*q))){
        x = f(x, q);
        if(DEBUG){
            printf("--x=%f, q=%f\n",x,q);
        }
    }
    return x;
}

int main(){
    int q;
    while(scanf("%d", &q)==1 && q!= -1){
        printf("%f\n", solve(q));
    }

    return 0;
}

