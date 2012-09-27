/* AOJ 0077
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0077
 *
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 101



void decode(char* buf){
    int n, i;

    while(*buf){
        if(*buf=='@'){
            buf++;
            n = *buf - '0';
            buf++;
            for(i=0;i<n;i++){
                printf("%c", *buf);
            }
        }else{
            printf("%c", *buf);
        }
        buf++;
    }

}


int main(){
    char buf[BUFSIZE];

    while(scanf("%s", buf)==1){
        decode(buf);
        printf("\n");
    }

    return 0;
}
