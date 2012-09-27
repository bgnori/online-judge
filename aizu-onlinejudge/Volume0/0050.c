/* AOJ 0050
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0050
 *
 */

#include <stdio.h>

#define DEBUG 0

void replace(char* where, char* with){
    while(*with){
        *where++ = *with++;
    }
}

char* match(char* where, char* s){
    int pos;
    int i;

    pos = 0;
    while(*(where+pos)){
        i = 0;
        while(*(where+pos+i)==*(s+i)){
            i++;
            if(*(s+i) == '\0'){
                return where+pos;
            }
        }
        pos++;
    }
    return NULL;
}


int main(){
    char buf[1001];
    char* p;

    while(fgets(buf, 1000, stdin)){

        if(DEBUG){
            printf("%s", buf);
            printf("0123456789");
            printf("0123456789");
            printf("0123456789");
            printf("0123456789");
            printf("0123456789");
            printf("0123456789\n");
            printf("%s\n", match(buf, "peach"));
            printf("%s\n", match(buf, "apple"));
        }

        for(p=buf; p&&*p;){
            p=match(p, "apple");
            if(p)
                replace(p, "XXXXX");
        }
            
        for(p=buf; p&&*p;){
            p=match(p, "peach");
            if(p)
                replace(p, "YYYYY");
        }

        for(p=buf; p&&*p; ){
            p=match(p, "YYYYY");
            if(p)
                replace(p, "apple");
        }

        for(p=buf; p&&*p; ){
            p=match(p, "XXXXX");
            if(p)
                replace(p, "peach");
        }
        
        printf("%s", buf);
        if(DEBUG){
            printf("0123456789");
            printf("0123456789");
            printf("0123456789");
            printf("0123456789");
            printf("0123456789");
            printf("0123456789\n");
        }
    }
    return 0;
}
