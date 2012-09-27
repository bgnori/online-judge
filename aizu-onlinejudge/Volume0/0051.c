/* AOJ 0051
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0051
 *
 */

#include <stdio.h>
#include <stdlib.h>


int comp_char_asc(const void* a, const void* b){

    return *((char*)a) - *((char*)b);
}

int comp_char_dsc(const void* a, const void* b){

    return *((char*)b) - *((char*)a);
}

int main(){
    int n;
    int max, min;
    char buf[9];

    scanf("%d", &n);

    while(scanf("%s", buf)== 1){
        qsort(buf, 8, 1, comp_char_asc);
        sscanf(buf, "%d", &min);

        qsort(buf, 8, 1, comp_char_dsc);
        sscanf(buf, "%d", &max);
        printf("%d\n", max-min);

    }

    return 0;
}
