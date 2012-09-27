/* AOJ 0071
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0071
 *
 */

#include <stdio.h>

#define DEBUG 0

#define true 1
#define false 0


int data[8][8];


void loadline(int row, char* buf){
    int i;
    for(i=0;i<8;i++){
        data[row][i] = buf[i] - '0';
    }
}


void ignite(int x, int y, int t){
    if((0<=x)&&(x<8) && (0<=y) && (y<8)){
        if(data[y][x] == 1){
            data[y][x] = t;
        }
    }
}

void fire(int x, int y,  int t){
    int i;
    if(data[y][x] != t){
        return;
    }
    for(i=-3;i<=3;i++){
        ignite(x+i, y, t+1);
        ignite(x, y+i, t+1);
    }

}

void run(int t){
    int j,k;
    if(DEBUG){
        printf("run %d\n", t);
        for(j=0;j<8;j++){
            for(k=0;k<8;k++){
                printf("%d", data[j][k]);
            }
            printf("\n");
        }
    }

    for(j=0;j<8;j++){
        for(k=0;k<8;k++){
            fire(j, k, t);
        }
    }
}


int has_ignited(int t){
    int j,k;

    for(j=0;j<8;j++){
        for(k=0;k<8;k++){
            if(data[j][k]==t){
                return true;
            }
        }
    }
    return false;
}


int main(){
    int n, x,y;
    int i,j,k;
    int t;
    char buf[20];

    scanf("%d", &n);

    for(i=0; i<n;i++){
        for(j=0;j<8;j++){
            scanf("%s", buf);
            loadline(j, buf);
        }
        scanf("%d", &x);
        scanf("%d", &y);
        if(DEBUG)
            printf("(%d,%d)\n", x, y);

        t = 2;
        data[y-1][x-1] = 1; /* place first bomb */
        ignite(x-1, y-1, t);
        if(DEBUG){
            for(j=0;j<8;j++){
                for(k=0;k<8;k++){
                    printf("%d", data[j][k]);
                }
                printf("\n");
            }
        }
        while(has_ignited(t)){
            run(t);
            t++;
        }
        printf("Data %d:\n",i+1);
        for(j=0;j<8;j++){
            for(k=0;k<8;k++){
                if(data[j][k] == 1){
                    printf("1");
                }else{
                    printf("0");
                }
            }
            printf("\n");
        }

    }

    return 0;
}

