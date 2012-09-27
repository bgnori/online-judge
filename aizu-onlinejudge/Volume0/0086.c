/* AOJ 0086
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0086
 *
 */

#include <stdio.h>

#define SIZE 101

/* http://ja.wikipedia.org/wiki/%E4%B8%80%E7%AD%86%E6%9B%B8%E3%81%8D */


int node[SIZE];

void init(void){
    int i;
    for(i=0; i< SIZE; i++){
        node[i] = 0;
    }
    /* goal and start */
    node[1]=1;
    node[2]=1;
}

int check(void){
    int i;
    for(i=1; i< SIZE; i++){
        if(node[i]%2){
            return 0;
        }
    }
    return 1;
}

int main(){
    int a, b;

    init();
    while(scanf("%d %d", &a, &b)==2){
        if(a==0 && b ==0){
            if(check()){
                printf("OK\n");
            }else{
                printf("NG\n");
            }
            init();
        }else{
            node[a]++;
            node[b]++;
        }
    }
    return 0;
}
