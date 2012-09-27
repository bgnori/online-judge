/* AOJ 0057
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0057
 *
 */

#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n) == 1){
        printf("%d\n", (n*n + n + 2) /2);
    }
    return 0;
}
