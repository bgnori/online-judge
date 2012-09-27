/* AOJ 0053
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0053
 *
 */

#include <stdio.h>

#define true 1
#define false 0
#define SIZE 200000

int table[SIZE];


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
    for(i=2;i<SIZE;i++){
        table[i]=isprime(i);
    }
}


int sumOfPrime(int n){
    int sum;
    int i, j;
    sum = 0;
    i = 0;
    j = 1;

    while(i<n){
        j++;
        while(!table[j]){
            j++;
        }
        sum += j;
        i++;
    }
    return sum;
}


int main(){
    int n, largest, smallest;
    build();
    while(scanf("%d", &n) == 1 && n){
        printf("%d\n", sumOfPrime(n));
    }

    return 0;
}
