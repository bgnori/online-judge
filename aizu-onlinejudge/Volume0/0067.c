/* AOJ 0067
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0067
 *
 */

#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define BUFSIZE 20

#define true 1
#define false 0

int data[12][12];
int active;



int paint(int i, int j, int color){
    if(!(0 <= i && i<12 && 0<= j && j<12))
        return false;
    if(data[i][j]!=1){
        return false;
    }

    data[i][j] = color;

    paint(i+1, j, color);
    paint(i-1, j, color);
    paint(i, j+1, color);
    paint(i, j-1, color);
    return true;
}


void loadData(char* buf){
    int i = 0;
    while(*buf && i<12){
        data[active][i] = *buf - '0';
        i++;
        buf++;
    }
    if(DEBUG){
        for(i=0;i<12; i++){
            printf("%d", data[active][i]);
        }
        printf("\n");
    }
    active++;
}

void endData(void){
    int color;
    int i, j;
    active = 0;
    if(DEBUG){
        printf("\n");
    }

    color = 2;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
            if(paint(i, j, color)){
                color++;
            }
        }
    }
    if(DEBUG){
        for(i=0;i<12;i++){
            for(j=0;j<12;j++){
                if(data[i][j]){
                    printf("%c", data[i][j] + 'a' - 2);
                }else{
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    printf("%d\n", color -2);
}


int main(){
    char buf[BUFSIZE];
    active = 0;

    while(fgets(buf, BUFSIZE, stdin)){
        if(strlen(buf) > 2){
            loadData(buf);
        }else{
            endData();
        }
    }
    if(DEBUG){
        printf(buf);
    }
    if(active){
        endData();
    }
    return 0;
}
