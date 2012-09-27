/* AOJ 0087
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0087
 *
 */
#include <stdio.h>
#include <assert.h>

#define DEBUG 0

double gstack[100];
int gtop;

void push(double v){
    assert(gtop<100);
    if(DEBUG)
        printf("pushing %f\n", v);
    gstack[gtop] = v;
    gtop +=1;
}

double pop(void){
    assert(gtop>0);
    gtop -=1;
    if(DEBUG)
        printf("popping %f\n", gstack[gtop]);
    return gstack[gtop];
}

int is_num(char c){
    return ('0' <= c) && (c<='9');
}

int tokenize(char* p){
    int len;
    switch (*p){
        case '\0':
        case '\r':
        case '\n':
            return 0;
        case ' ':
        case '*':
        case '+':
        case '/':
            return 1;
        case '-':
            if(is_num(*(p+1))){
                len = 0;
                while(is_num(*(p+len+1))){
                    len++;
                }
                return len+1; /*sign*/
            }else{
                return 1;
            }
            break;
        default: /*0-9*/
            len = 0;
            while(is_num(*(p+len))){
                len++;
            }
            return len;
            break;
    }
    return 0;
}

int read_val(char* s, int len){
    int i, r;
    int sign;
    r = 0;
    if(*s == '-'){
        sign = -1;
        i=1;
    }else{
        sign = 1;
        i=0;
    }
    while(i<len){
        r *= 10;
        r += (*(s+i) - '0');
        i++;
    }
    return sign*r;
}


int main(){
    char buf[83];
    char* p;
    int len;
    double a, b;

    gtop=0;
    while(fgets(buf, 82, stdin)){
        p = buf;
        while((len = tokenize(p))){
            switch(*p){
                case ' ':
                    break;
                case '*':
                    b = pop();
                    a = pop();
                    push(a*b);
                    break;
                case '+':
                    b = pop();
                    a = pop();
                    push(a+b);
                    break;
                case '/':
                    b = pop();
                    a = pop();
                    push(a/b);
                    break;
                case '-':
                    if(len == 1){
                        b = pop();
                        a = pop();
                        push(a-b);
                        break;
                    }
                    /* fall through */
                default:
                    push(read_val(p, len));
                    break;
            }
            p+=len;
        }
        assert(gtop==1);
        printf("%f\n",pop());
        assert(gtop==0);
    }
    return 0;
}
