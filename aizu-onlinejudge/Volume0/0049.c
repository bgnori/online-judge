/* AOJ 0049
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0049
 *
 */

#include <stdio.h>

#define DEBUG 0


int main(){
    int n, i;
    char input[30];
    int data[4]; /* A, B, AB, O */

    for(i=0;i<4; i++)
        data[i] = 0;

    while(scanf("%d,%s", &n, input)==2){
        if(DEBUG)
            printf("%s\n", input);
        if(input[0] == 'A'){
            if(input[1] == 'B'){
                data[2]++;
            }else{
                data[0]++;
            }
        }else if(input[0] == 'B'){
            data[1]++;
        }else if(input[0] == 'O'){
            data[3]++;
        }
    }
    for(i=0;i<4; i++)
        printf("%d\n", data[i]);
    return 0;
}
