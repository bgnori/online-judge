/* AOJ 0084
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0084
 *
 */

#include <stdio.h>




int head[1024];
int len[1024];
int wc;


int is_sep(char c){
    return c == ' ' || c == '.' || c == ',';
}

void chop(char* buf){
    int h, l, pos;

    h = 0;
    l = 0;
    pos = 0;
    while(*buf){
        if(is_sep(*buf)){
            if(l){
                head[wc] = h;
                len[wc] = l;
                wc++;
            }
            l = 0;
        }else{
            if(l==0){
                h = pos;
            }
            l++;
        }
        buf++; pos++;
    }

}



int main(){
    char buf[1026];
    int i, j;
    int isfirst;

    while(fgets(buf, 1024, stdin)){
        wc = 0;
        isfirst = 1;
        chop(buf);
        for(i=0;i<wc; i++){
            if(len[i]>2 && len[i] < 7){
                if(isfirst){
                    isfirst = 0;
                }else{
                    printf(" ");
                }
                for(j=0;j<len[i];j++){
                    printf("%c", *(buf+head[i]+j));
                }
            }
        }
        printf("\n");
    }

    return 0;
}
