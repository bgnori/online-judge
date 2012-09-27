/* AOJ 0060
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0060
 *
 */

#include <stdio.h>
#define DEBUG 0


float odds(int* cards){
    int available[11];
    int i;
    int yes = 0;
    int no = 0;
    int sum;
    
    for(i=1;i<11;i++){
        available[i] = (
                (cards[0] != i)
                &&
                (cards[1] != i)
                &&
                (cards[2] != i)
                );
        if(DEBUG)
            printf("%d %d\n", i, available[i]);
    }
    sum = cards[0] + cards[1];

    for(i=1;i<11;i++){
        if(available[i]){
            if(sum + i < 21){
                yes += 1;
            }else{
                no += 1;
            }

        }
    }

    return yes/7.0;
}

int main(){
    int cards[3];

    while(scanf("%d %d %d", cards, cards+1, cards+2) == 3){

        if(DEBUG)
            printf("%d %d %d\n", cards[0], cards[1], cards[2]);
        if(odds(cards) < 0.50){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}
