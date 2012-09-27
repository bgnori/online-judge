/* AOJ 0070
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0070
 *
 */

#include <stdio.h>


#define DEBUG 0

int hash2sum(int n, int hash){
    int used[10] = {0,0,0,0,0,0,0,0,0,0};
    int i, r;

    return r;
}


int main(){
    int n, s;
    int i, max, count;

    while(scanf("%d %d", &n, &s)==2){
        if(DEBUG)
            printf("%d %d\n", n, s);

        count = 0;
        max = fact(n);
        for(i=0;i<max;i++){
            if(hash2sum(n, i) == s){
                if(DEBUG)
                    printf("%d\n", i);
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}

