/* AOJ 0088
 *
 * http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0088
 *
 */

#include <stdio.h>
#include <string.h>

#define BUFSIZE 1024
#define DEBUG 0


char* mapping(char c){
    switch(c){
        case ' ': return "101";
        case '\'': return "000000";
        case ',': return "000011";
        case '-': return "10010001";
        case '.': return "010001";
        case '?': return "000001";
        case 'A': return "100101";
        case 'B': return "10011010";
        case 'C': return "0101";
        case 'D': return "0001";
        case 'E': return "110";
        case 'F': return "01001";
        case 'G': return "10011011";
        case 'H': return "010000";
        case 'I': return "0111";
        case 'J': return "10011000";
        case 'K': return "0110";
        case 'L': return "00100";
        case 'M': return "10011001";
        case 'N': return "10011110";
        case 'O': return "00101";
        case 'P': return "111";
        case 'Q': return "10011111";
        case 'R': return "1000";
        case 'S': return "00110";
        case 'T': return "00111";
        case 'U': return "10011100";
        case 'V': return "10011101";
        case 'W': return "000010";
        case 'X': return "10010010";
        case 'Y': return "10010011";
        case 'Z': return "10010000";
        default:
                  break;
    }
    return "";
}


int encode(char* src, char* dst){
    int len;
    char* s;
    len = 0;
    while(*src){
        s = mapping(*src);
        len += strlen(s);
        if(DEBUG)
            printf("%c -> %s\n", *src, s);
        while(*s){
            *dst++ = *s++;
        }
        src++;
    }
    return len;
}

int to_int(char* src){
    int i;
    int r;
    r = 0;
    for(i=0;i<5;i++){
        if(DEBUG)
            printf("%c", *(src+i));
        r = r << 1;
        r += (*(src+i) - '0');
    }
    return r;
}

char dump(char* src){
    int i;
    if(DEBUG)
        printf("\n");
    i = to_int(src);
    if(DEBUG)
        printf("-> %d -> ", i);
    switch(i){
        case 0b11010: return ' ';
        case 0b11011: return '.';
        case 0b11100: return ',';
        case 0b11101: return '-';
        case 0b11110: return '\'';
        case 0b11111: return '?';
        default:
            return i + 'A';
    }
}


int main(){
    char buf[83];
    char stream[BUFSIZE];
    int i;
    int len;
    int padding;

    while(fgets(buf, 80, stdin)){
        len = encode(buf, stream);
        if(len%5){
            padding = 5 - len%5;
        }else{
            padding = 0;
        }
        for(i=0; i < padding; i++){
            *(stream+len+i) = '0';
        }
        for(i=0; i< len+padding; i+=5){
            printf("%c",dump(stream+i));
        }
        printf("\n");
    }
    return 0;
}
