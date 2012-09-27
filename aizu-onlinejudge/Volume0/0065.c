/* AOJ 0065
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0065
 *
 */

#include <stdio.h>
#include <string.h>

#define DEBUG 0

typedef struct TRecord Record;
struct TRecord {
    int fID;
    int fValue;
};

Record last[1000];
int last_n;
Record this[1000];
int this_n;

Record match[2002];
int match_n;


int comp(const void* a, const void*b){
    return ((Record*)a)->fID - ((Record*)b)->fID;
}


int load(char* buf, Record* xs, int xn){
    int id, date;
    
    sscanf(buf, "%d,%d",&id, &date);
    xs[xn].fID = id;
    xs[xn].fValue = date;
    return xn + 1;
}

int main(){
    char buf[101];
    int i,j,k;
    int chunk;
    int last_id;


    chunk = 0;
    this_n = 0;
    last_n = 0;

    while(fgets(buf, 100, stdin)){
        if(strlen(buf) > 2){
            if(chunk == 0){
                this_n = load(buf, this, this_n);
            }
            if(chunk == 1){
                last_n = load(buf, last, last_n);
            }
        }else{
            chunk++;
        }
    }

    if(DEBUG){
        for(i=0;i<this_n;i++){
            printf("%d %d\n", this[i].fID, this[i].fValue);
        }
        printf("====\n");
    }

    if(DEBUG){
        for(i=0;i<last_n;i++){
            printf("%d %d\n", last[i].fID, last[i].fValue);
        }
        printf("====\n");
    }


    match_n = 0;
    for(i=0;i<this_n;i++){
        for(j=0;j<last_n;j++){
            if(DEBUG){
                printf("%d %d\n", i,j);
            }
            if(this[i].fID == last[j].fID){
                match[match_n].fID = this[i].fID;
                match_n++;
            }
        }
    }
    if(DEBUG){
        printf("%d\n", match_n);
    }

    for(k=0;k<match_n;k++){
        for(i=0;i<this_n;i++){
            if(this[i].fID == match[k].fID){
                match[k].fValue++;
            }
        }
        for(j=0;j<last_n;j++){
            if(last[j].fID == match[k].fID){
                match[k].fValue++;
            }
        }
    }

    qsort(match, match_n, sizeof(Record), comp);

    last_id = -1;
    for(k=0;k<match_n;k++){
        if(last_id != match[k].fID){
            last_id = match[k].fID;
            printf("%d %d\n", match[k].fID, match[k].fValue);
        }
    }
    return 0;
}
