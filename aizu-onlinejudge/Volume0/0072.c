/* AOJ 0072
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0072
 *
 */

#include <stdlib.h>
#include <stdio.h>

#define DEBUG 0

#define MAX 100
/* 市内の史跡は100 箇所以内です */


typedef struct TStreet Street;
struct TStreet{
    int fA;
    int fB;
    int fCost;
};

int parent[MAX];
int rank[MAX];

void MakeSet(int loc){
    parent[loc] = loc;
    rank[loc] = 0;
};


int find(int loc){
    int found;
    if(parent[loc]==loc){
        return loc;
    }else{
        found = find(parent[loc]);
        parent[loc] = found;
        return found;
    }
}


void merge(int x, int y){
    int xr, yr;
    xr = find(x);
    yr = find(y);
    if(rank[xr] > rank[yr]){
        parent[yr] = xr;
    }else if( rank[xr] < rank[yr]){
        parent[xr] = yr;
    }else if (xr != yr) {
        parent[yr] = xr;
        rank[xr] += 1;
    }
}


int Kruskal(int nodecount, Street* network, int path){
    int i;
    int a, b;
    int cost;
    cost = 0;
    for(i=0; i<nodecount;i++){
        MakeSet(i);
    }
    for(i=0; i < path; i++){
        if(DEBUG)
            printf("Working on %d <-> %d  (%d)\n", network[i].fA, network[i].fB, network[i].fCost);
        a = network[i].fA;
        b = network[i].fB;
        if(DEBUG){
            printf("%d in  %d\n", a, find(a));
            printf("%d in  %d\n", b, find(b));
        }
        if(find(a) != find(b)){
            merge(a, b);
            cost += network[i].fCost;
        }
    }
    return cost;
}


int comp(const void*a, const void*b){
    return ((Street*)a)->fCost - ((Street*)b)->fCost;
}


int main(){
    /* 最小全域木問題 */
    int n, path;
    int i;
    int a, b, d;
    int cost;
    Street* network;
    

    while(scanf("%d", &n)==1 && n){
        /* n <= 100 */
        scanf("%d", &path);

        /* path <= n! */
        network = (Street*)malloc(path*sizeof(Street));

        for(i=0;i<path;i++){
            scanf("%d,%d,%d", &a, &b, &d);
            network[i].fA = a;
            network[i].fB = b;
            network[i].fCost = d/100 - 1 ;
        }

        qsort(network, path, sizeof(Street), comp);
        if(DEBUG){
            for(i=0;i<path;i++){
                printf("%d <-> %d  (%d)\n", network[i].fA, network[i].fB, network[i].fCost);
            }
        }

        cost = Kruskal(n, network, path);
        printf("%d\n", cost);

        free((void*)network);
    }

    return 0;
}

