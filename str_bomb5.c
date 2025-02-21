#include <stdio.h>
#include <string.h>

void replace(char * s){
    size_t lenbomb = strlen("bomb");
    size_t lenwater = strlen("watermelon");
    char * p = strstr(s, "bomb");
    while (p != NULL){
        memmove(p + lenwater, p + lenbomb, strlen(p + lenbomb) + 1);
        memcpy(p, "watermelon", lenwater);
        p = strstr(s, "bomb");
    }
}

int main(){
    char s[10001];
    while(NULL != fgets(s, 10001, stdin)){
        replace(s);
    printf("%s", s);
    }
    
    return 0;
}