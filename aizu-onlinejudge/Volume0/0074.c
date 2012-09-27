/* AOJ 0074
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0074
 *
 */

#include <stdio.h>



void f(int x){
    int h, m, s;
    h = x/3600;
    m = x%3600/60;
    s = x%60;

    printf("%02d:%02d:%02d\n", h, m, s);

}


int main(){
    int h, m, s;
    int x;

    while(scanf("%d %d %d", &h, &m, &s) == 3){
        if(h==-1&&m==-1&&s==-1)
            break;
        x = h*3600+m*60+s;
        f(120*60 - x);
        f(120*60 - x/3);
    }

    return 0;
}
