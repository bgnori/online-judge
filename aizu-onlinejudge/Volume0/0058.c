/* AOJ 0058
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0058
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define err 0.000000001

int main(){
    float xA, yA, xB, yB, xC, yC, xD, yD;
    double xAB, yAB, xCD, yCD;

    while(scanf("%f %f %f %f %f %f %f %f", 
            &xA, &yA, &xB, &yB, &xC, &yC, &xD, &yD) == 8){
        xAB = xB-xA;
        yAB = yB-yA;
        xCD = xD-xC;
        yCD = yD-yC;
        if(abs(xAB*xCD + yAB *yCD) < err){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }

    return 0;
}
