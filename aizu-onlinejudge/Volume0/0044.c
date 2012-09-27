/* AOJ 0044
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0044
 *
 */

#include <stdio.h>

#define true 1
#define false 0

int table[51000];
/* 51000 must be bigger than the first prime after 50000 */


int isprime(int n){
    int i;
    for(i=2;i*i<=n;i++){
        if(table[i] && !(n%i)){
            return false;
        }
    }
    return true;
}

void build(void){
    int i;
    table[0]=1;
    table[1]=1;
    table[2]=1;
    for(i=2;i<51000;i++){
        table[i]=isprime(i);
    }
}


void find(int* largest, int n, int* smallest){
    int i;
    for(i=n-1; i>1; i--){
        if(table[i]){
            *largest=i;
            break;
        }
    }
    for(i=n+1; i<51000; i++){
        if(table[i]){
            *smallest=i;
            break;
        }
    }

}


int main(){
    int n, largest, smallest;
    build();
    while(scanf("%d", &n) == 1){
        find(&largest, n, &smallest);
        printf("%d %d\n", largest, smallest);
    }

    return 0;
}
