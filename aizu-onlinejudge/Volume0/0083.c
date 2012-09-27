/* AOJ 0083
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0083
 *
 */

#include <stdio.h>

typedef struct TEra Era;

struct TEra {
    char* fName;
    int fYear;
    int fMonth;
    int fDay;
};

Era era[4] = {
    {"heisei", 1989, 1, 8},
    {"showa", 1926, 12, 25},
    {"taisho", 1912, 7, 30},
    {"meiji", 1868, 9, 8},
};

int main(){
    int y, m, d;
    int dy, dm, dd;
    int i;

    while(scanf("%d %d %d", &y, &m, &d)==3){
        for(i=0;i<4;i++){
             dy = y - era[i].fYear;
             dm = m - era[i].fMonth;
             dd = d - era[i].fDay;
             if((dy > 0) || (dy==0 && dm >0)|| (dy==0 && dm==00 && dd>=0)){
                 printf("%s %d %d %d\n",era[i].fName, dy+1, m, d);
                 break;
             }
        }
        if(i==4){
            printf("pre-meiji\n");
        }
    }

    return 0;
}
