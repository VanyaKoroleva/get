#include<stdio.h>
int main(){
    int n, i, j, x1, x2;
    int m[1000];
    scanf("%d", &n);
    for (i = 0; i < n; i ++)
        scanf("%d", &m[i]);
    
    j = n - 1;
    i = 0;
    while (i <= j)
    {
        if (i == j){
            printf("%d", m[i]);
            break;
        }
        x1 = (m[i] % 2 == 0);
        x2 = (m[j] % 2 == 0);
        if ((x1 + x2 == 0) || (x1 + x2 == 2) || x1)
            printf("%d %d ", m[i], m[j]);
        else
            printf("%d %d ", m[j], m[i]);
        i++;
        j--;
    }
}