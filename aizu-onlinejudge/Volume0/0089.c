/* AOJ 0089
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0089
 *
 */

#include <stdio.h>

#define BUFSIZE 500
#define DEBUG 0

#define true 1
#define false 0

int data[201][100];
int sum[202][101];


int is_num(char c){
    return ('0' <= c) && (c <= '9');
}


int parseInt(char** p){
    int i, r;
    char *s;
    int sign;
    int len;
    s = *p;

    r = 0;

    if(*s == '-'){
        sign = -1;
        s++;
    }else{
        sign = +1;
    }
    while(is_num(*s)){
        r *= 10;
        r+= (*s - '0');
        s++;
    }
    *p=s;
    return sign*r;
}

int parseComma(char** p){
    if(**p == ','){
        (*p)++;
        return true;
    }
    return false;
}


int parse(char* buf, int* found){
    int n;
    char*p;

    p = buf;
    n = 0;
    found[n] = parseInt(&p);
    n++;

    while(*p){
        if(!parseComma(&p)){
            break; /* cr lf etc.*/
        }
        found[n] = parseInt(&p);
        n++;
    }
    return n;
}


void load(int row, int *found, int count){
    int i;
    for(i=0;i<count;i++){
        data[row+1][i+1] = found[i];
    }
}

int max(int a, int b){
    if(a > b)
        return a;
    return b;
}

int solve(int size){
    int i, j;
    int row, diff;

    for(row=1;row<=size;row++){
        for(i=1;i<row+1;i++){
            if(DEBUG)
                printf(" v=%d@(%d, %d) ",data[row][i], row, i);
            sum[row][i] = max(sum[row-1][i-1], sum[row-1][i]) + data[row][i];
            if(DEBUG)
                printf(" s=%d@(%d, %d) ",sum[row][i], row, i);
        }
        if(DEBUG)
            printf("\n");
    }
    for(diff=1;diff<=size-1;diff++){
        /* row = diff + size */
        for(i=1;i< size - diff + 1;i++){
            if(DEBUG)
                printf(" v=%d@(%d, %d) ",data[diff+size][i], diff+size, i);
            row = diff+size;
            sum[row][i] = max(sum[row-1][i], sum[row-1][i+1]) + data[row][i];
            if(DEBUG)
                printf(" s=%d@(%d, %d) ",sum[diff+size][i], diff+size, i);
        }
        if(DEBUG)
            printf("\n");
    }
    return sum[size*2-1][1];
}


int main(){
    char buf[BUFSIZE+3];
    int found[100];
    int row;
    int size;
    int count;

    row = 0;
    size = 1;
    while(fgets(buf, BUFSIZE, stdin)){ 
        count = parse(buf, found);
        if(DEBUG)
            printf("size = %d\n", size);
        if(count >= row){
            load(row, found, count);
            row++;
            size = row;
        }else{
            load(row, found, count);
            row++;
        }
    }
    printf("%d\n", solve(size));
    return 0;
}

