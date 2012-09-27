/* AOJ 0038
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0038
 *
 */

#include <stdio.h>
#include <stdlib.h>

int diff1_Aas14_count(int *hand){
    int i, j, n;
    n = 0;
    for(i =0; i<5; i++){
        for(j=i+1;j<5;j++){
            if(hand[i]== 1 || hand[j] == 1){
                if(hand[i]== 1){
                    if((14 - hand[j]) == 1)
                        n++;
                }else{ /*hand[j] == 1*/
                    if((14 - hand[i]) == 1)
                        n++;
                }
            }else{
                if(abs(hand[i] -  hand[j]) == 1){
                    n++;
                }
            }
        }
    }
    return n;
}


int diff1_Aas1_count(int *hand){
    int i, j, n;
    n = 0;
    for(i =0; i<5; i++){
        for(j=i+1;j<5;j++){
            if(abs(hand[i] -  hand[j]) == 1){
                n++;
            }
        }
    }
    return n;
}

int eq_count(int *hand){
    int i, j, n;
    n = 0;
    for(i =0; i<5; i++){
        for(j=i+1;j<5;j++){
            if(hand[i] == hand[j]){
                n++;
            }
        }
    }
    return n;
}

int test_fourcard(int* hand){
    return eq_count(hand) == 6;
}

int test_fullhouse(int* hand){
    return eq_count(hand) == 4;
}

int test_straight(int* hand){
    return diff1_Aas14_count(hand) == 4 || diff1_Aas1_count(hand) == 4;
}

int test_threecard(int* hand){
    return eq_count(hand) == 3;
}

int test_twopair(int* hand){
    return eq_count(hand) == 2;
}

int test_onepair(int* hand){
    return eq_count(hand) == 1;
}



char* test(int* hand){
    if(test_fourcard(hand)){
        return "four card";
    }

    if(test_fullhouse(hand)){
        return "full house";
    }

    if(test_threecard(hand)){
        return "three card";
    }

    if(test_twopair(hand)){
        return "two pair";
    }

    if(test_onepair(hand)){
        return "one pair";
    }

    if(test_straight(hand)){
        return "straight";
    }
    return "null";
}


int main(){
    int hand[5];
    char* r;

    while(scanf("%d,%d,%d,%d,%d", hand, hand+1, hand+2, hand+3, hand+4) == 5){
        r = test(hand);
        printf("%s\n", r);
    }

    return 0;
}

