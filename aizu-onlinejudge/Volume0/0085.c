/* AOJ 0085
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0085
 *
 */

#include <stdio.h>


#define DEBUG 0

int next[1001];



int main(){
    int m, n;
    int count;
    int i;
    int p, prev;

    while(scanf("%d %d", &n, &m)==2){
        if(m==0 && n==0){
            break;
        }

        for(i=1;i<n;i++){
            next[i]=i+1;
        }
        next[n] = 1;

        count = n;
        prev = 1;
        p = 1;
        while(count > 1){
            for(i=0;i<m-1;i++){
                prev = p;
                p = next[p];
            }
            if(DEBUG)
                printf("removing %d\n", p);
            next[prev] = next[p];
            p = next[p];
            count--;
        }
        printf("%d\n", p);

    }
    return 0;
}
