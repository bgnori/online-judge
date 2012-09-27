
#include<stdio.h>
#include<math.h>


float inner_product(float x1, float y1, float x2, float y2){
  return x1*x2 + y1*y2;
}


int main(){
  float x1,y1, x2,y2, x3,y3, xp, yp;
  float v12x, v12y, v13x, v13y, v1px, v1py;
  float ux, uy;
  float z, w;
  float a, b;
  float ip1213, ip1212;

  while ( scanf("%f %f %f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x3, &y3, &xp, &yp) != EOF){
    /*
    printf("p1 %.4f %.4f\n", x1, y1);
    printf("p2 %.4f %.4f\n", x2, y2);
    printf("p3 %.4f %.4f\n", x3, y3);
    printf("pp %.4f %.4f\n", xp, yp);
    */
    v12x = x2 - x1;
    v12y = y2 - y1;
        
    v13x = x3 - x1;
    v13y = y3 - y1;
        
    v1px = xp - x1;
    v1py = yp - y1;
  
    /*
    printf("v12 %.4f %.4f\n", v12x, v12y);
    printf("v13 %.4f %.4f\n", v13x, v13y);
    printf("v1p %.4f %.4f\n", v1px, v1py);
    */

    ip1212 = inner_product(v12x, v12y, v12x, v12y);
    ip1213 = inner_product(v12x, v12y, v13x, v13y);
    /*
    printf("%.4f %.4f\n", ip1212, ip1213);
    */

    ux = v13x - ip1213 * v12x /ip1212;
    uy = v13y - ip1213 * v12y /ip1212;
    /*
    printf("v12 %.4f %.4f\n", v12x, v12y);
    printf("u   %.4f %.4f\n", ux, uy);
    printf("inner_product(v12, u) == %f\n", inner_product(v12x, v12y, ux, uy));
    */
    
    z = inner_product(ux, uy, v1px, v1py)/inner_product(ux, uy, ux, uy);
    w = inner_product(v12x, v12y, v1px, v1py)/ip1212;
    /*
     *
     *  P = w*v12 + z * u    #  inner_product (v12, u ) == 0
     *    = w*v12 + z * (v13 - ip1213 * v12 /ip1212)
     *    = (w - z*ip1213/ip1212)* v12 + z * v13
     */
    
    //printf("%.4f %.4f\n", w, z);
    a = w - z * ip1213/ip1212 ; /* param for v12 */
    b = z; /* param for v13 */
    /* printf("%.4f %.4f\n", a, b); */
    if ((0.0 < a) && (a < 1.0) && (0.0 < b) && (b<1.0) && (a + b < 1.0)){
      printf("YES\n");
    }else{
      printf("No\n");
    }
  }
  return 0;
}
