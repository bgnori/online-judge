/* AOJ 0042
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0042
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define DEBUG 0

typedef struct TTresure Tresure;
struct TTresure {
    int fValue;
    int fWeight;
};

Tresure items[1001];
int count;
int Capacity;

Tresure memo[1001][1001];


int max(int i, int j){
    if( i > j)
        return i;
    return j;
}

Tresure solve(int i, int j){
    Tresure res;
    Tresure a, b;
    if(memo[i][j].fWeight >=0){
        return memo[i][j];
    }
    if(i==count){
        res.fWeight = 0;
        res.fValue = 0;
    }else if (j < items[i].fWeight){
        res = solve(i+1, j);
    }else{
        a = solve(i+1, j);
        b = solve(i+1, j-items[i].fWeight);
        b.fValue += items[i].fValue;
        b.fWeight += items[i].fWeight;
        if(a.fValue >= b.fValue){
            res = a;
        }else{
            res = b;
        }
    }
    memo[i][j] = res;
    return res;
}

int main(){
    int Case;
    int i;
    Tresure result;
    Case = 1;

    while(scanf("%d", &Capacity)==1 && Capacity){
        scanf("%d", &count);
        for(i=0;i<count;i++){
            scanf("%d,%d", &((items+i)->fValue), &((items+i)->fWeight));
        }
        if(DEBUG){
            printf("%d\n", Capacity);
            printf("%d\n", count);
            for(i=0;i<count;i++){
                printf("%d,%d\n", ((items+i)->fValue), ((items+i)->fWeight));
            }
        }
        memset(memo, -1, sizeof(memo));
        result = solve(0, Capacity);
        printf("Case %d:\n", Case);
        printf("%d\n", result.fValue);
        printf("%d\n", result.fWeight);
        Case +=1;
    }
    return 0;
}

