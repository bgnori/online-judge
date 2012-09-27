
#include <stdio.h>

#define DEBUG 0


typedef struct TGrid Grid;
struct TGrid {
    int fRight;
    int fDown;
};

/* starting at (1, 1), not (0,0) */ #define XSIZE 6
#define YSIZE 6

Grid Grids[(XSIZE)*(YSIZE)];
enum {BadDirection=0, North=1, East=2, South=3, West=4};
char Map[5] = {'X', 'U', 'R', 'D', 'L'};



int right_at(int x, int y){
   return Grids[x+XSIZE*y].fRight;
}

int down_at(int x, int y){
   return Grids[x+XSIZE*y].fDown;
}

int left_at(int x, int y){
   return Grids[x-1+XSIZE*y].fRight;
}

int up_at(int x, int y){
   return Grids[x+XSIZE*(y-1)].fDown;
}

void cw(int* nx, int *ny, int x, int y){
    int ux, uy;
    int vx, vy;

    if(DEBUG)
        printf("(%d, %d) (%d, %d)\n", *nx, *ny, x, y);

    ux = *nx - x;
    uy = *ny - y;
    /* rotate -pi/2, (0 1), (-1, 0) */
    vx = -uy; 
    vy = ux;
    *nx = x + vx;
    *ny = y + vy;

    if(DEBUG)
        printf("=> (%d, %d) (%d, %d)\n", *nx, *ny, x, y);
}


int direction(int dx, int dy, int x, int y){
    if (dx == x){
        if(dy < y){
            return North;
        }else{
            return South;
        };
    }else{
        if(dx > x){
            return East;
        }else{
            /*dx < x*/
            return West;
        };
    }
}


void step(int* x, int* y, int* prevx, int* prevy){
    int i, d;
    int has_wall;
    int nextx, nexty;
    nextx = *prevx;
    nexty = *prevy;

    if(DEBUG)
        printf("current(%d, %d) prev(%d, %d)\n", *x, *y, *prevx, *prevy);

    for(i=0;i<4;i++){
        cw(&nextx, &nexty, *x, *y);
        d = direction(nextx, nexty, *x, *y);
        if(DEBUG)
            printf("trying direction:%c\n", Map[d]);
        switch(d){
            case North:
                has_wall = up_at(*x, *y);
                break;
            case East:
                has_wall = right_at(*x, *y);
                break;
            case South:
                has_wall = down_at(*x, *y);
                break;
            case West:
                has_wall = left_at(*x, *y);
                break;
            default:
                break;
        }
        if(DEBUG)
            printf("has_wall %d\n", has_wall);
        if(has_wall){
            printf("%c",Map[d]);
            break;
        }
    }

    *prevx = *x;
    *prevy = *y;
    *x = nextx;
    *y = nexty;
}


void set_xy_right(int x, int y, int v){
        Grids[x+XSIZE*y].fRight = v;
}

void set_xy_down(int x, int y, int v){
        Grids[x+XSIZE*y].fDown = v;
}

int load_line(int nth){
    int i;
    int x;
    if(nth%2){
        scanf("%d", &x);
        for(i=0;i<4;i++){
            set_xy_right(4-i,nth/2+1, x%10);
            x = x/10;
        }

    }else{
        scanf("%d", &x);
        for(i=0;i<5;i++){
            set_xy_down(5-i,nth/2, x%10);
            x = x/10;
        }
    }
}

int main(){
    int x, y;
    int prevx, prevy;
    int done, nth;
    nth = 1;

    while(nth < 10){
        load_line(nth);
        nth ++;
    }

    if(DEBUG){
        for(y=0;y<YSIZE;y++){
            for(x=0;x<XSIZE;x++){
                printf("%d", Grids[x+y*XSIZE].fRight);
            }
            printf("\n");
            for(x=0;x<XSIZE;x++){
                printf("%d", Grids[x+y*XSIZE].fDown);
            }
            printf("\n");
            printf("---------\n");
        }
    }

    x = 1; y = 1;
    prevx = 1; prevy = 2;
    step(&x, &y, &prevx, &prevy);
    while(!(x==1 && y==1)){
        step(&x, &y, &prevx, &prevy);
    }
    printf("\n");
    return 0;
}


