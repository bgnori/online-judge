

#include<stdio.h>
#include<math.h>


#define THRESHOLD 0.00001

double distance(double x1, double y1, double x2, double y2){
  return sqrt(pow(x1-x2, 2.0) + pow(y1-y2, 2.0));
}


int main(){
  int n;
  double x1,y1, x2,y2, x3,y3;
  double a,b,c;
  double r;
  double x, y;
  double d1, d2, d3;

  scanf("%i", &n);
  for(;n>0;n--){
    scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3);
    a = distance(x1, y1, x2, y2);
    b = distance(x2, y2, x3, y3);
    c = distance(x3, y3, x1, y1);
    printf("%.3f %.3f %.3f\n", a, b, c);

    r = a*b*c / sqrt((a+b+c)*(-a+b+c)*(a-b+c)*(a+b-c));
   
    x = 0.0;
    y = 0.0;
    
    while( abs(x*x+y*y - r*r) > THRESHOLD){
      printf("%.3f %.3f %.3f\n", x, y, r);
      d1 = distance(x, y, x1, y1);
      d2 = distance(x, y, x2, y2);
      d3 = distance(x, y, x3, y3);
      printf("%.3f %.3f %.3f\n", d1, d2, d3);

      x += ((d1-r)/r)*(x-x1);
      x += ((d2-r)/r)*(x-x2);
      x += ((d3-r)/r)*(x-x3);
      y += ((d1-r)/r)*(y-y1);
      y += ((d2-r)/r)*(y-y2);
      y += ((d3-r)/r)*(y-y3);
    }
    printf("%.3f %.3f %.3f\n", x, y, r);
  }
  return 0;
}


