/* AOJ 0047
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0047
 *
 */

#include <stdio.h>
#define DEBUG 0

int main(){
    char input[30];
    int i;
    int from, to, tmp;
    int buf[3];

    buf[0] = 1;
    buf[1] = 0;
    buf[2] = 0;
    
    while(scanf("%s", input) ==1){
        if(DEBUG)
            printf("%s\n",input);
        from = input[0] - 'A';
        to = input[2] - 'A';
        tmp = buf[to];
        buf[to] = buf[from];
        buf[from]=tmp;
    }

    for(i=0;i<3;i++){
        if(buf[i])
            break;
    }
    printf("%c\n", 'A'+i);
    return 0;
}
