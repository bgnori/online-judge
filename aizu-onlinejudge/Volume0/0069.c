/* AOJ 0069
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0069
 *
 */

#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define BUFSIZE 81

#define MAX_V_COUNT 10
#define MAX_H_COUNT 31

int vertical;
int selected;
int winner;
int horizontal;
int bars[MAX_H_COUNT][MAX_V_COUNT];
int datacount;


void init(void){
    int i, j;
    vertical = 0;
    selected = 0;
    winner = 0;
    horizontal = 0;
    for(i=0;i<MAX_H_COUNT;i++){
        for(j=0;j<MAX_V_COUNT;j++){
            bars[i][j]=0;
        }
    }
    datacount = 0;
}


void loadh(char* buf){
    int i;
    if(DEBUG){
        printf("loading %d, %s", datacount, buf);
    }
    for(i=0; i<vertical-1; i++){
        bars[datacount][i+1] = buf[i] - '0';
    }
}

void swap(int *a, int *b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int trace(int start){
    int state[MAX_V_COUNT];
    int i;
    int j;

    for(i=1; i<=vertical;i++){
        state[i]=0;
    }
    state[start] = 1;
    if(DEBUG){
        for(i=1; i<=vertical;i++){
            printf("%d", state[i]);
        }
        printf("\n");
    }

    for(j=1; j<=horizontal; j++){
        for(i=1; i<vertical; i++){
            if(bars[j][i]){
                swap(state+i, state+i+1);
            }
        }
        if(DEBUG){
            for(i=1; i<=vertical;i++){
                printf("%d", state[i]);
            }
            printf("\n");
        }
    }
    for(i=1; i <= vertical; i++){
        if(state[i])
            return i;
    }
}

void patch(int j, int i){
    bars[j][i] = 1;
}

void unpatch(int j, int i){
    bars[j][i] = 0;
}

void run(void){
    int i,j;
    if(DEBUG){
        for(j=1; j<=horizontal;j++){
            for(i=1; i<=vertical-1; i++){
                printf("%d", bars[j][i]);
            }
            printf("\n");
        }
    }
    if(trace(selected) == winner){
        printf("0\n");
        return;
    }else{
        for(j=1; j<=horizontal;j++){
            for(i=1; i<=vertical-1; i++){
                if(!bars[j][i] && !bars[j][i-1] && !bars[j][i+1]){
                    if(DEBUG){
                        printf("patched %d %d\n", j, i);
                    }
                    bars[j][i] = 1; /* patch */
                    if(winner == trace(selected)){
                        printf("%d %d\n", j, i);
                        return;
                    }else{
                        bars[j][i] = 0; /* unpatch */
                    }
                }
            }
        }
        printf("1\n");
        return;
    }
}


int main(){
    char buf[BUFSIZE];

    init();
    while(fgets(buf, BUFSIZE, stdin)){
        if(*buf=='0' && strlen(buf) == 3){
            break;
        }
        else if(!vertical){
            sscanf(buf, "%d", &vertical);
        }
        else if(!selected){
            sscanf(buf, "%d", &selected);
        }
        else if(!winner){
            sscanf(buf, "%d", &winner);
        }
        else if(!horizontal){
            sscanf(buf, "%d", &horizontal);
        }
        else if(datacount < horizontal){
            datacount++;
            loadh(buf);
            if(datacount == horizontal){
                run();
                init();
            }
        }
    }

    return 0;
}

