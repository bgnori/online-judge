/* AOJ 0075
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0075
 *
 */

#include <stdio.h>

int main(){
    int id;
    float w, h;


    while(scanf("%d,%f,%f", &id, &w, &h) == 3){
        if(w/(h*h) >= 25.0){
            printf("%d\n", id);
        }
    }

    return 0;
}
