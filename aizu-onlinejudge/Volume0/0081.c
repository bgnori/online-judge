/* AOJ 0081
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0081
 *
 */

#include <stdio.h>
#include <math.h>



int main(){
    float x1, y1, x2, y2, xq, yq;
    double ux, uy, vx, vy, p, d;

    while(scanf("%f,%f,%f,%f,%f,%f", &x1, &y1, &x2, &y2, &xq, &yq) == 6){
        //printf("%f %f %f %f %f %f", x1, y1, x2, y2, xq, yq);
        ux = x2 - x1;
        uy = y2 - y1;

        vx = xq - x1;
        vy = yq - y1;

        d = sqrt(ux*ux + uy*uy);
        p = (ux*vx/d + uy*vy/d);
        printf("%f %f\n", xq - 2*(vx - p*ux/d), yq - 2*(vy - p*uy/d));
    }
    return 0;
}
