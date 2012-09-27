/* AOJ 0063
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0063
 *
 */

#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define true 1
#define false 0


int palindrome(char* buf, int len){
    if(DEBUG)
        printf("%d %s\n",len, buf);

    if(len == 0)
        return true;
    if(len == 1)
        return true;

    if(*buf == *(buf+len-1)){
        return palindrome(buf+1, len-2);
    }else{
        return false;
    }
}



int main(){
    char buf[101];
    int len;
    int count;

    count = 0;

    while(scanf("%s", buf)==1){
        len = strlen(buf);
        if(palindrome(buf, len)){
            count ++;
        }
    }
    printf("%d\n", count);

    return 0;
}
