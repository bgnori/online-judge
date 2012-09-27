

#include <stdio.h>
/*
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0026
 *
 */
/* prints the number of cells whose density value is 0 */
/* print the maximum value of density. */


int paper[200];

int coor(int x, int y){
  return x*14+y;
}

void small(int x, int y){
  paper[coor(x, y)]+=1;
  paper[coor(x+1, y)]+=1;
  paper[coor(x, y+1)]+=1;
  paper[coor(x-1, y)]+=1;
  paper[coor(x, y-1)]+=1;
}

void midium(int x, int y){
  paper[coor(x, y)]+=1;
  paper[coor(x+1, y)]+=1;
  paper[coor(x, y+1)]+=1;
  paper[coor(x-1, y)]+=1;
  paper[coor(x, y-1)]+=1;
  paper[coor(x+1, y+1)]+=1;
  paper[coor(x+1, y-1)]+=1;
  paper[coor(x-1, y+1)]+=1;
  paper[coor(x-1, y-1)]+=1;
}

void large(int x, int y){
  midium(x, y);
  paper[coor(x+2, y)]+=1;
  paper[coor(x, y+2)]+=1;
  paper[coor(x-2, y)]+=1;
  paper[coor(x, y-2)]+=1;
}


int main(){
  int x, y, size;
  int max_density;
  int filled;
  int i,j;

  for(i=0;i<14;i++){
    for(j=0;j<14;j++){
      paper[coor(i, j)] = 0;
    }
  }

  while(scanf("%d,%d,%d", &x, &y, &size)==3){
    switch(size){
    case 1:
      small(x+2, y+2);
      break;
    case 2:
      midium(x+2, y+2);
      break;
    case 3:
      large(x+2, y+2);
      break;
    default:
      break;
    }
  }
  filled = 0;
  max_density = 0;
  for(i=2;i<12;i++){
    for(j=2;j<12;j++){
      if(paper[coor(i, j)]){
        filled += 1;
        if(paper[coor(i, j)] > max_density)
          max_density = paper[coor(i, j)];
      }
    }
  }
  printf("%d\n", 100-filled);
  printf("%d\n", max_density);
  return 0;
}
