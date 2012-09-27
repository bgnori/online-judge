/* AOJ 0061
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0061
 *
 */

#include <stdio.h>
#include <stdlib.h>


#define DEBUG 1
#define DEFAULT 1

typedef struct TPair Pair;

struct TPair {
    int fID;
    int fValue;
};

int comp(const void* a, const void* b){
    return ((Pair*)b)->fValue - ((Pair*)a)->fValue;
}



int main(){
    int entry;
    Pair* scores;
    int size;
    int* ranking;
    int r;
    int score;
    int id;
    int i;

    size = DEFAULT;
    scores = (Pair*)malloc(size*sizeof(Pair));

    /* Data setup */
    entry = 0;
    while(scanf("%d,%d", &id, &score)==2 && id && score){
        (scores+entry)->fID = id;
        (scores+entry)->fValue = score;
        entry++;
        if(entry == size){
            size=size*2;
            scores = (Pair*)realloc((void*)scores, sizeof(Pair)*size);
        }
    }
    if(DEBUG){
        for(i=0;i<entry;i++){
            printf("%d, %d\n", (scores+i)->fID, (scores+i)->fValue);
        }
    }
    qsort((void*)scores, entry, sizeof(Pair), comp);

    ranking = (int*)malloc((entry+1)*sizeof(int));

    r = 0;
    score = -1;
    for(i=0;i<entry;i++){
        if (score != (scores+i)->fValue){
            r++;
            score = (scores+i)->fValue;
        }
        ranking[(scores+i)->fID] = r;

        if(DEBUG)
            printf("%d, %d, %d\n", (scores+i)->fID, (scores+i)->fValue , r);
    }

    /* Query */
    if(DEBUG){
        for(i=0;i<entry;i++){
            printf("%d\n", ranking[i+1]);
        }
        printf("------\n");
    }
    while(scanf("%d", &id)==1){
        printf("%d\n", ranking[id]);
    }
    return 0;
}

