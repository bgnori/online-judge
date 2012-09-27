/* AOJ 0040
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0040
 *
 */

#include <stdio.h>

#define DEBUG 1
#define BUFSIZE 257
/* 各データセットに半角の英小文字と空白からなる256 文字以内の暗号化された文章が１行に与えられます。*/



char encode_char(int a, int b, char c){
    return (a*(c-'a') + b) % 26 + 'a';
}

char decode_char(int a, int b, char c){
    //return (a*(c-'a') + b) % 26 + 'a';
}

void decode_word(int a, int b, char* input, int len, char* output){

}

void decode_whole(int a, int b, char* input, char* output){
    while(input){



    }
}


int main(){
    int n, i;
    char input[BUFSIZE];
    char output[BUFSIZE];

    scanf("%d", &n);
    /* 一行目にデータセット数 n が与えられます。続いてｎ行のデータが与えられます */
    for (i = 0; i<n ;i++){
        scanf(" %[ a-z]", input);
        if(DEBUG)
            printf("%s\n", input);
    }
    return 0;
}
