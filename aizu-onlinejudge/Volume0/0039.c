/* AOJ 0039
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0039
 *
 */

#include <stdio.h>

#define DEBUG 0


/* 大きい数字の前にあって引き算を表す小さな数字は一回の引き算あたりひとつしかありません。*/

/* 実際のローマ数字ではI はV かX から、X はL かC から、C はD かM からしか引き算しません */
/* 同じローマ数字は４つ以上（または５つ以上）足し並べることはありません。*/

int r2i(char r){
    switch(r){
        case 'I':
            return 1;
        break;
        case 'V':
            return 5;
        break;
        case 'X':
            return 10;
        break;
        case 'L':
            return 50;
        break;
        case 'C':
            return 100;
        break;
        case 'D':
            return 500;
        break;
        case 'M':
            return 1000;
        break;
        default:
        break;
    }
}


int roman2num(char* s){
    int r;
    int next;
    int cur;
    r = 0;

    while(s){
        if(!*(s+1)){
            r += r2i(*s);
            break;
        }
        cur = r2i(*s);
        next = r2i(*(s+1));
        if(next > cur){
            r-= cur;
        }else{
            r+= cur;
        }

        s++;
    }
    return r;
}


int main(){
    char buf[101]; /* 与えられるローマ数字の文字列の長さはおのおの100 以下です。*/
    int n;

    while(scanf("%s", &buf) == 1){
        if(DEBUG)
            printf("%s\n", buf);
        n = roman2num(buf);
        printf("%d\n", n);
    }
    return 0;
}

