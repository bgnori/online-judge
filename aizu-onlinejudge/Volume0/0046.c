/* AOJ 0046
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0046
 *
 */

#include <stdio.h>
#include <float.h>

int main(){
    float high;
    float low;
    float input;

    high = 0.0;
    low = FLT_MAX;

    while(scanf("%f", &input)==1){
        if(input > high){
            high = input;
        }
        if(input < low ){
            low = input;
        }
    }
    printf("%0.1f\n", high - low);

    return 0;
}
