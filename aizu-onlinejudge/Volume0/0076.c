/* AOJ 0076
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0076
 *
 */

#include <stdio.h>
#include <math.h>


double f(double* ux, double* uy){
    double vx, vy;
    vx = -*uy;
    vy = *ux;

    *ux += (vx / sqrt(vx*vx + vy * vy));
    *uy += (vy / sqrt(vx*vx + vy * vy));
}


int main(){
    int n;
    int i;
    double x, y;

    while((scanf("%d", &n) == 1) && (n > -1)){
        x = 1.0;
        y = 0.0;

        for(i=1;i<n;i++){
            f(&x, &y);
        }
        printf("%.2f\n", x);
        printf("%.2f\n", y);
    }

    return 0;
}
