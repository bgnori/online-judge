/* AOJ 0056
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0056
 *
 */

#include <stdio.h>
#define true 1
#define false 0

int table[51000];

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


int goldbach(int n){
    int i;
    int count;
    count = 0;
    for(i=2;i<=n/2; i++){
        if (table[i] && table[n-i]){
            count += 1;
        }
    }
    return count;
}


int main(){
    int n, largest, smallest;
    build();
    while(scanf("%d", &n) == 1 && n){
        printf("%d\n", goldbach(n));
    }

    return 0;
}
