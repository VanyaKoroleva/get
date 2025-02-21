#include <stdio.h>
#include <stdlib.h>
#define N 1000

int cmtChar(const void * p1, const void * p2){
    char x = *(const char *)p1;
    char y = *(const char *)p2;
    return (x > y) - (x < y);
}

int main(){
    char a[N];
    char s;
    int i;
    scanf("%c", &s);
    for(i = 0; s != '.'; i ++){
        a[i] = s;
        scanf("%c", &s);
    }
    a[i] = '\0';

    qsort(a, i, sizeof(char), cmtChar);
    
    printf("%s.", a);
    
}