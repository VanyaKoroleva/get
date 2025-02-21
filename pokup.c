#include <stdio.h>

int main(){
    int n, i, id, k;
    int a, b;
    char pokup[1000] = {0};
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d %d %d", &a, &id, &b);
        if (pokup[id] == 0){
            pokup[id] = 1;
            k ++;
        }
    }
    printf("%d", k);

    return 0;
}