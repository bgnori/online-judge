/* AOJ 0078
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0078
 *
 */

#include <stdio.h>

int m[15][15];

void newdiagonal(int size, int*x, int*y);
void wrap(int size, int*x, int*y);

void wrap(int size, int*x, int*y){
    if(*x<0){
        *x=size-1;
        newdiagonal(size, x, y);
    }
    if(*y<0){
        *y=size-1;
        newdiagonal(size, x, y);
    }
    if(size <= *x){
        *x=0;
        newdiagonal(size, x, y);
    }
    if(size <= *y){
        *y=0;
        newdiagonal(size, x, y);
    }
}

void newdiagonal(int size, int*x, int*y){
    if(m[*y][*x]){
        *x -=1;
        *y +=1;
        wrap(size, x, y);
    }
}



void next(int size, int*x, int*y){
    *x +=1;
    *y +=1;
    wrap(size, x, y);
    newdiagonal(size, x, y);
}

void magic(int size){
    int i;
    int range;
    int x, y;

    range = size*size +1;
    x = size/2;
    y = x+1;

    for(i=1;i<range;i++){
        m[y][x] = i;
        if(i!= size*size)
            next(size, &x, &y);
    }
}

void clean(void){
    int i; 
    int j;
    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            m[j][i]=0;
        }
    }
}

void print(int size){
    int i; 
    int j;
    for(j=0;j<size;j++){
        for(i=0;i<size;i++){
            printf("%4d",m[j][i]);
        }
        printf("\n");
    }
}

int main(){
    int n;

    while(scanf("%d", &n)==1 && n){
        clean();
        magic(n);
        print(n);
    }
    return 0;
}

