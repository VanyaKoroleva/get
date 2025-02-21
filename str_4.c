#include <stdio.h>
#include <string.h>

char * my_strcat (char *dest, const char *src){
    strcpy(dest + strlen(dest), src);
    return dest;
}

int main(){
    char a[100];
    char * b;    
    char a2[100];        
    char * b2;  

    strcpy(a, "abc");
    printf("%s\n", a);     // abc
    b = strcat(a, "world");
    printf("%s\n", a);     // abcworld
    printf("%s\n", b);   
    printf("2_____\n");
    strcpy(a2, "abc");   
    b2 = my_strcat(a2, "world");
    printf("%s\n", a2);     // abcworld
    printf("%s\n", b2); 
}