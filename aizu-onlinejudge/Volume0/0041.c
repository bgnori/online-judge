/* AOJ 0041
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0041
 *
 */

#include <stdio.h>
#include <assert.h>


#define DEBUG 0
#define DEBUG_TREE 0

#define ADD 0
#define SUB 1
#define MUL 2


char* templates[5] = {
    "n,n,op,n,n,op,op,",
    "n,n,n,n,op,op,op,",
    "n,n,n,op,n,op,op,",
    "n,n,n,op,op,n,op,",
    "n,n,op,n,op,n,op,",
};


typedef union UOpaque Opaque;
union UOpaque{
    int uInt;
    char uChar[30];
};

Opaque gstack[10];
int gtop = 0;

Opaque pop(){
    gtop -= 1;
    return gstack[gtop];
}

void push(Opaque v){
    gstack[gtop] = v;
    gtop += 1;
}

void dumpstack(void){
    int i;
    printf("-----\n");
    for(i=0;i<gtop;i++){
        printf("stack[%d] = %d %s\n", i, gstack[i].uInt, gstack[i].uChar);
    }
    printf("-----\n");
}

typedef Opaque (*EvalFunc)(int op, Opaque a, Opaque b);
typedef Opaque (*ConvFunc)(int input);


Opaque toInt(int input){
    Opaque p;
    p.uInt = input;
    return p;
}

Opaque calc(int op, Opaque a, Opaque b){
    if(DEBUG_TREE)
        printf("got op: %d\n", op);
    switch(op){
        case ADD:
            return toInt(a.uInt + b.uInt);
            break;
        case SUB:
            return toInt(a.uInt - b.uInt);
            break;
        case MUL: 
            return toInt(a.uInt * b.uInt);
            break;
        default:
            break;
    }
    assert(0);
}


Opaque join(int op, Opaque a, Opaque b){
    Opaque r;
    switch(op){
        case ADD:
            sprintf(r.uChar, "(%s+%s)", a.uChar, b.uChar);
            return r;
            break;
        case SUB:
            sprintf(r.uChar, "(%s-%s)", a.uChar, b.uChar);
            return r;
            break;
        case MUL: 
            sprintf(r.uChar, "(%s*%s)", a.uChar, b.uChar);
            return r;
            break;
        default:
            break;
    }
    assert(0);
}

Opaque toStr(int input){
    Opaque p;
    sprintf(p.uChar, "%d",input);
    return p;
}


Opaque eval(char* t, int* ops, int* nums, EvalFunc func, ConvFunc conv){
    Opaque a;
    Opaque b;
    while(*t){
        if(DEBUG_TREE){
            printf("%s\n", t);
            dumpstack();
        }
        if(*t == 'o'){
            t+=3;
            b = pop();
            a = pop();
            push(func(*ops, a, b));
            ops++;
        }else{
            if(*t == 'n'){
                t+=2;
                push(conv(*nums));
                nums++;
            }else{
                assert(0);
            }
        }
    }
    return pop();
}


void make_ops(int hash, int * ops){
    ops[0] = hash % 3;
    ops[1] = hash / 3 % 3;
    ops[2] = hash / 3 / 3  % 3;
}



int fact(int n){
    if(n==0){
        return 1;
    }else{
        return fact(n-1)*n;
    }
}

void make_nums(int len, int hash, int* input, int* output);
void make_nums(int len, int hash, int* input, int* output){
    int n,i;
    int rest[len-1];

    n = fact(len-1);

    if(len == 1){
        *output = *input; /*filling last item*/
    }else{
        for(i=0;i<hash/n;i++){
            *(rest+i)= *(input+i);
        }
        *output = input[hash/n];
        for(i=hash/n;i<len;i++){
            *(rest+i)= *(input+i+1);
        }
        make_nums(len - 1, hash%n, rest, output+1);
    }
}

void find(int *buf){
    int i,j,k;
    int ops[3];
    int nums[4];
    Opaque r;
    for(i=0;i<81;i++){
        make_ops(i, ops);
        for(j=0;j<4*3*2*1;j++){
            make_nums(4, j, buf, nums);
            if(DEBUG)
                printf("%d %d %d %d\n", nums[0], nums[1], nums[2], nums[3]);
            for(k=0;k<5;k++){
                r = eval(templates[k], ops, nums, calc, toInt);
                if(DEBUG)
                    printf("evaluated: %d\n", r.uInt);
                if(r.uInt ==10){
                    r = eval(templates[k], ops, nums, join, toStr);
                    printf("%s\n", r.uChar);
                    return;
                }
            }
        }
    }
    printf("0\n");
}

int main(){
    int buf[4];

    while(scanf("%d %d %d %d", buf, buf+1, buf+2, buf+3) == 4){
        if(buf[0] == 0 && buf[1] == 0 && buf[2] ==0 && buf[3] == 0){
            break;
        }
        if(DEBUG)
            printf("%d %d %d %d\n", buf[0], buf[1], buf[2], buf[3]);
        find(buf);
    }
    return 0;
}
