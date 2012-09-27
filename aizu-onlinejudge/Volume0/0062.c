/* AOJ 0062
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0062
 *
 */

#include <stdio.h>

#define DEBUG 0

int f(int* xs, int len){
    int ys[10];
    int i;
    if(DEBUG){
        for(i=0; i<len; i++){
            printf("%d,", xs[i]);
        }
        printf("\n", xs[i]);
    }
    if(len==1){
        return xs[0];
    }else{
        for(i=0; i<len-1; i++){
            ys[i]=(xs[i]+xs[i+1])%10;
        }
        return f(ys, len -1);
    }
}

int main(){
    char buf[11];
    int i;
    int xs[10];

    while(scanf("%s", buf)==1){
        if(DEBUG)
            printf("==> %s\n", buf);

        for(i=0; i<10; i++){
            xs[i]= buf[i]-'0';
        }
        printf("%d\n", f(xs, 10));
    }

    return 0;
}

