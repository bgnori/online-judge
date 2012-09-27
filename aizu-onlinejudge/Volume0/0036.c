/* AOJ 0036 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0036
 */

#include<stdio.h>
#define DEBUG 1


#define true 1
#define false 0




int main(){
    int h;
    int box[64];
    int i, j;


    while(scanf("%d", &h) == 1){
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                box[i*8+j] =h;
            }
        }
        for(i=0;i<8;i++){
            for(j=0;j<8;j++){
                printf("%d",box[i*8+j]);
            }
            printf("\n");
        }

    }

    return 0;
}

