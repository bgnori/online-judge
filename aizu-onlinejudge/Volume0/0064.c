/* AOJ 0064
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0064
 *
 */

#include <stdio.h>


#define DEBUG 0

int match(char **sp){
    int len;

    len = 0;
    while(**sp){
        if(('0' <= **sp) && (**sp <= '9')){
            len += 1;
        }else if(len){
            *sp -= len;
            return len;
        }
        (*sp)++;
    }
    return 0;
}

int toInt(char* s, int len){
    int i, r;

    r = 0;
    for(i=0; i<len; i++){
        r=r*10;
        r+=( s[i] - '0');
    }
    return r;
}


int main(){
    char buf[81];
    char* p;
    int found;
    int sum = 0;

    while(scanf("%s", buf)==1){
        p = buf;
        while(found = match(&p)){
            if(DEBUG){
                printf("%d %s\n", found, p);
                printf("==> %d\n", toInt(p, found));
            }
            sum += toInt(p, found);
            p+= found;
        }
    }
    printf("%d\n", sum);
    return 0;
}

