#include <stdio.h>
#include <string.h>

int main(){
    char s[10];
    scanf("%9s", s);
    int step, x = 0, y = 0;
    while (0 != strcmp(s, "Treasure!")){
        scanf("%d", &step);
        if (strcmp(s, "North") == 0)
            y += step;
        if (strcmp(s, "South") == 0)
            y -= step;
        if (strcmp(s, "East") == 0)
            x += step;
        if (strcmp(s, "West") == 0)
            x -= step;
        scanf("%9s", s);
    }
    
    printf("%d %d", x, y);

    return 0;
}