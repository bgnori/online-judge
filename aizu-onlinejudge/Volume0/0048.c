/* AOJ 0048
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0048
 *
 */

#include <stdio.h>

typedef struct TData Data;

struct TData {
    char* fName;
    float fWeight;
};

Data cat[] = {
    {"light fly", 0.00,},
    {"fly", 48.00,},
    {"bantam", 51.00,},
    {"feather", 54.00,},
    {"light", 57.00,},
    {"light welter", 60.00,},
    {"welter", 64.00,},
    {"light middle", 69.00,},
    {"middle", 75.00,},
    {"light heavy", 81.00,},
    {"heavy", 91.00,},
};


int main(){
    int i;
    int count = sizeof(cat)/sizeof(Data);
    float input;

    while(scanf("%f", &input)==1){
        for(i=count-1;i>-1; i--){
            if(cat[i].fWeight < input){
                printf("%s\n", cat[i].fName);
                break;
            }
        }
    }

    return 0;
}

