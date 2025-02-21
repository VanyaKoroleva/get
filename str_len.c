#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    char res[1001];
    int maxlen = 0;
    while(1 == scanf("%1000s", s)) {
        if (strlen(s) > maxlen){
            maxlen = strlen(s);
            strcpy(res, s);
        }
    }

    printf("%s %d", res, maxlen);
    return 0;
}