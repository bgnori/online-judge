/* AOJ 0055
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0055
 *
 */

#include <stdio.h>



double sum(float a0, int n){
    int i;
    double s;
    double an;

    s = 0.0;
    an = a0;

    for(i=0;i<n;i++){
        /* printf("%f %d\n", an, i); */
        s+= an;
        if(i%2){
            an = an /3;
        }else{
            an = an *2;
        }
    }
    return s;
}



int main(){
    float a0;

    while(scanf("%f", &a0)==1){
        printf("%.8f\n", sum(a0, 10));
        /* 出力は0.000001以下の誤差を含んでもよい。 */
    }

    return 0;
}
