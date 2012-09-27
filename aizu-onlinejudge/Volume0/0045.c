/* AOJ 0045
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0045
 *
 */

#include <stdio.h>

int main(){
    int n;
    int sales;
    int items;
    int price;
    int volume;
    float ave;

    n = 0;
    sales = 0;
    items = 0;
    while(scanf("%d,%d", &price, &volume)==2){
        n += 1;
        sales += (price * volume);
        items += volume;
    }

    printf("%d\n", sales);

    ave = 1.0*items/n;
    if((ave - (int)ave) < 0.5){
        printf("%d\n", (int)ave);
    }else{
        printf("%d\n", (int)ave+1);
    }
                

    return 0;
}
