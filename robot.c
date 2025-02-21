#include<stdio.h>

int main(){
    int s, L, k, i;
    scanf("%d%d%d", &s, &L, &k);
    while (L <= s){
        s -= L;
        L += k;
        i ++;
    }
    printf("%d %d", i, s);
    return 0;
}