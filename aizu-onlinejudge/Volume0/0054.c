/* AOJ 0054
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0054
 *
 */

#include <stdio.h>


int s(int a, int b, int n){
    int i;
    int sum;
    sum = 0;


    for(i=0;i<n;i++){
        /* printf("%d %d\n", a, i);*/
        sum += a/b;
        a = (a%b)*10;
    }
    return sum;
}


int main(){
    int a, b, n;
    while(scanf("%d %d %d",&a, &b, &n) == 3){
        printf("%d\n", s((a%b)*10, b, n));
    }

    return 0;
}
