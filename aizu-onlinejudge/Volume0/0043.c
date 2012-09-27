/* AOJ 0043
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0043
 *
 */

#include <stdio.h>
#include <memory.h>
#include <assert.h>


#define false 0
#define true 1
#define DEBUG 0


int lessthan5times(char* buf){
    int i;
    int count[10];
    memset(count, 0, sizeof(count));
    while(*buf){
        count[*buf - '1']+=1;
        buf++;
    }
    for(i=0;i<10;i++){
        if(count[i] > 4){
            return false;
        }
    }
    return true;
}

void make_rest(char* src, int srclen, char*dst, int i, int j, int k){
    int m;
    assert(0<=i);
    assert(i<j);
    assert(j<k);
    assert(k<srclen);

    for(m=0;m<i;m++){
        dst[m] = src[m];
    }
    for(m=i+1;m<j;m++){
        dst[m-1] = src[m];
    }
    for(m=j+1;m<k;m++){
        dst[m-2] = src[m];
    }
    for(m=k+1;m<srclen;m++){
        dst[m-3] = src[m];
    }
    dst[m-3] = '\0';
}

int is_seq(char c, char d, char e){
    return (
            (c+2 == d+1) && (c+2 == e)
           )||(
               (c+2 == e+1) && (c+2 == d)
           )||(
               (d+2 == c+1) && (d+2 == e)
           )||(
               (d+2 == e+1) && (d+2 == c)
           )||(
               (e+2 == d+1) && (e+2 == c)
           )||(
               (e+2 == c+1) && (e+2 == d)
           );
}

int check(char* buf, int len){
    char rest[14];
    int i,j,k;

    assert(!(len%3));

    if(len == 0){
        return true;
    }
    if(DEBUG){
        printf("length: %d\n", len);
        printf("checking %s\n", buf);
        printf("         01234567890123\n");
    }

    for(i=0;i<len;i++){
        for(j=i+1;j<len;j++){
            for(k=j+1;k<len;k++){
                if ((buf[i]==buf[j]) && (buf[j]==buf[k])){
                    if(DEBUG){
                        printf("set of %c, with %d %d %d\n", buf[i], i,j,k);
                    }
                    make_rest(buf, len, rest, i, j,k);
                    if(check(rest, len -3)){
                        return true;
                    }
                }
                if (is_seq(buf[i], buf[j], buf[k])){
                    if(DEBUG){
                        printf("seq, %c %c %c\n", buf[i],buf[j],buf[k]);
                    }
                    make_rest(buf, len, rest, i, j,k);
                    if(check(rest, len -3)){
                        return true;
                    }
                }

            }
        }
    }
    return false;
}


int is_complete(char* buf){
    char rest[14];
    int i,j,k;

    if(!lessthan5times(buf)){
        return false;
    }
    for(i=0;i<14;i++){
        for(j=i+1;j<14;j++){
            if(buf[i] == buf[j]){
                if(DEBUG){
                    printf("pair of %c, with %d %d\n", buf[i], i,j);
                }
                for(k=0;k<i;k++){
                    rest[k] = buf[k];
                }
                for(k=i+1;k<j;k++){
                    rest[k-1] = buf[k];
                }
                for(k=j+1;k<14;k++){
                    rest[k-2] = buf[k];
                }
                rest[12]='\0';
                if(check(rest, 12)){
                    return true;
                }else if (DEBUG){
                    printf("restarting %s.\n", buf);

                }
            }
        }
    }
    return false;
}


int main(){
    char buf[15];
    char i;
    int first;


    while(scanf("%s", buf)==1){
        if(DEBUG){
            printf("input: %s\n", buf);
            printf("       01234567890123\n");
        }
        first = 1;
        for(i='1';i<='9';i++){
            buf[13]=i;
            buf[14]='\0';
            if(DEBUG){
                printf("trying %c\n", i);
            }
            if(is_complete(buf)){
                if(DEBUG){
                    printf("found %c for %s.\n", i, buf);
                }
                if(first){
                    printf("%c", i);
                    first = 0;
                }else{
                    printf(" %c", i);
                }
            }
        }
        if(first){
            printf("0\n");
        }else{
            printf("\n");
        }
    }
    return 0;
}

