/* AOJ 0066
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0066
 *
 */

#include <stdio.h>


#define DEBUG 0
#define true 1
#define false 0

#define DRAW 'd'
#define OWON 'o'
#define XWON 'x'



int row(int r, char c, char* buf){
    int i;
    for(i=0;i<3;i++){
        if(buf[3*r+i] != c){
            return false;
        }
    }
    return true;
}

int col(int co, char c, char* buf){
    int i;
    for(i=0;i<3;i++){
        if(buf[co+i*3] != c){
            return false;
        }
    }
    return true;
}

int diagonalA(char c, char* buf){
    return ((buf[0]==c)
    && (buf[4]==c)
    && (buf[8]==c));
}

int diagonalB(char c, char* buf){
    return ((buf[2]==c)
    && (buf[4]==c)
    && (buf[6]==c));
}

char judge(char* buf){
    int i;
    for(i=0;i<3;i++){
        if(row(i, 'x', buf))
            return XWON;
        if(col(i, 'x', buf))
            return XWON;
    }
    if(diagonalA('x', buf))
        return XWON;
    if(diagonalB('x', buf))
        return XWON;

    for(i=0;i<3;i++){
        if(row(i, 'o', buf))
            return OWON;
        if(col(i, 'o', buf))
            return OWON;
    }
    if(diagonalA('o', buf))
        return OWON;
    if(diagonalB('o', buf))
        return OWON;

    return DRAW;
}




int main(){
    char buf[10];

    while(scanf("%s", buf)==1){
        if(DEBUG)
            printf("%s\n", buf);

        printf("%c\n", judge(buf));
    }

    return 0;
}
