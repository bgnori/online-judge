/* AOJ 0082
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0082
 *
 */

#include <stdio.h>


int c[8][8] = {
    {4,1,4,1,2,1,2,1},
    {1,4,1,2,1,2,1,4},
    {4,1,2,1,2,1,4,1},
    {1,2,1,2,1,4,1,4},
    {2,1,2,1,4,1,4,1},
    {1,2,1,4,1,4,1,2},
    {2,1,4,1,4,1,2,1},
    {1,4,1,4,1,2,1,2},
};

int main(){

    int p[8];
    int missed;
    int V;
    int pos;
    int mi,n;
    int i, j;
    int vi;

    while(scanf("%d %d %d %d %d %d %d %d", p, p+1, p+2, p+3, p+4, p+5, p+6, p+7)==8){
        missed = -1;
        for(i=0;i<8;i++){
            mi = 0;
            vi = 0;
            for(j=0;j<8;j++){
                n = p[j] - c[i][j];
                if(n > 0)
                    mi += n;
                vi *= 10;
                vi += c[i][j];
            }
            if(missed == -1){
                missed = mi;
                V = vi;
                pos = i;
            }else if(missed > mi){
                missed = mi;
                V = vi;
                pos = i;
            }else if(missed == mi){
                if(V > vi){
                    missed = mi;
                    V = vi;
                    pos = i;
                }
            }
        }
        printf("%d %d %d %d %d %d %d %d\n", 
                c[pos][0], c[pos][1], c[pos][2], c[pos][3], c[pos][4], c[pos][5], c[pos][6], c[pos][7]);
    }

    return 0;
}
